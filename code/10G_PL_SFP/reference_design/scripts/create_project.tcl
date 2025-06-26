#
# create_project.tcl: Tcl script for re-creating Vivado project
# 
# requires sourcing the settings.tcl to define the following variables:
# part, PS_DDR, project_name, vivado_dir
# ########################################################################################

if {[file exists [file join scripts settings.tcl]] } { source [file join scripts settings.tcl] }
if {![info exists vivado_dir]} { set vivado_dir [file join Vivado ${module_name}] }

# Create project
create_project ${project_name} ${vivado_dir} -part ${part}

# Set project directory
set proj_dir [get_property directory [current_project]]

# Set project properties
set_property "default_lib"        "xil_defaultlib" [current_project]
set_property "part"               "${part}"        [current_project]
set_property "simulator_language" "Mixed"          [current_project]
set_property "target_language"    "VHDL"           [current_project]

# Create filesets (if not found)
if {[string equal [get_filesets -quiet sources_1] ""]} {
    create_fileset -srcset sources_1
}
if {[string equal [get_filesets -quiet constrs_1] ""]} {
    create_fileset -srcset constrs_1
}

# add source and constraints to corresponding fileset
add_files -norecurse -fileset sources_1 [glob -type f -directory src *.{vhd,edn}]
add_files -norecurse -fileset constrs_1 [glob -type f -directory src *.{tcl,xdc}]

# re-create block design
# contains PS settings, IP instances, DDR settings
# ################################################
source scripts/${project_name}_bd.tcl
# ################################################

# handle list of generics at level top
if {[info exists generics]} {
	set list [get_property "generic" $obj]
	lappend list ${generics}
	set_property "generic" ${list} $obj
}

# add the settings.tcl file to synth and implementation tcl.pre
set proj_dir [get_property DIRECTORY [current_project]]
set settings_file $proj_dir/../../scripts/settings.tcl
set norm_settings_file [file normalize $settings_file]
add_files -fileset utils_1 -norecurse $settings_file
set_property STEPS.SYNTH_DESIGN.TCL.PRE [ get_files $norm_settings_file -of [get_fileset utils_1] ] [get_runs synth_1]
set_property STEPS.INIT_DESIGN.TCL.PRE [ get_files $norm_settings_file -of [get_fileset utils_1] ] [get_runs impl_1]

# timing constraints are only relevant for implementation
if {[llength [glob -nocomplain -type f -directory src *_timing.tcl]] != 0} {
    set_property used_in_synthesis false [get_files -filter {NAME =~ *_timing.tcl}]
}
set_property used_in_synthesis false [get_files *.xdc]

puts "INFO: END of [info script]"