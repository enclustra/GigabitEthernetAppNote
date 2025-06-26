set_false_path -from [get_clocks clk_pl_1] -to [get_ports {PL_LED2_N}]

####################################################################################
# Constraints from file : 'bd_bea1_eth_buf_0.xdc'
####################################################################################

#set_property IOSTANDARD LVCMOS33 [get_ports gtrefClk_n]
#set_property IOSTANDARD LVCMOS33 [get_ports gtrefClk_p]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets clk]

#set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets USR_CLK_ibufds/O]
# reference clock for AXI ETH IP 156.25Mhz
create_clock -name gt_ref_clk -period 6.4 [get_ports mgt_clk_p] 
