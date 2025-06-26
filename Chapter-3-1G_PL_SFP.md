# 3 - 1G PL SFP Design 

This document provides an overview of the Gigabit Ethernet design implemented on the Programmable Logic (PL) side using the Enclustra [Mercury+ XU8 Module](https://www.enclustra.com/en/products/system-on-chip-modules/mercury-xu8/) and [Mercury+ ST1 baseboard](https://www.enclustra.com/en/products/base-boards/mercury-st1/). The design utilizes AMD’s 1G/2.5G Ethernet Subsystem IP to establish 1G Ethernet connectivity with a compatible endpoint. The interface is based on SFP modules, with copper/optical cable used for the physical connection, ensuring compatibility with 1000BASE-T standards.

## 3.1 - Vivado Design 

The primary goal of this design is to operate the AXI 1G/2.5G Ethernet Subsystem in combination with the AXI DMA IP for efficient data transfer. The Ethernet subsystem requires a reference clock and TX/RX lines connected to the SFP port pins for proper operation. The reference clock is provided by an external clock generator, while the Ethernet speed can be configured to 1 Gbps or 2.5 Gbps through the IP’s GUI settings. However, this application note specifically focuses on 1 Gbps Ethernet speed.

The steps outlined in this document can be adapted to various Enclustra modules and baseboards that support SFP-based Ethernet transmission. For demonstration purposes, this implementation is based on the [Mercury+ XU8 Module](https://www.enclustra.com/en/products/system-on-chip-modules/mercury-xu8/) and [Mercury+ ST1 baseboard](https://www.enclustra.com/en/products/base-boards/mercury-st1/).


To implement and test this design, the following hardware components are required:  

1. 1000BASE-T compatible SFP module  
2. Compatible cable with the module
3. License for 1G/2.5G Ethernet IP (evaluation License can be also used)

Vivado Version: 2022.1

### 3.1.1 - Firmware Design

**NOTE**: To trace the connections see XU8+ Schematics and ST1+ Schematics.

The base block design is derived from the Mercury+ XU8 and Mercury+ ST1 Baseboard reference design. The reference design is available on the [Enclustra GitHub page](https://github.com/enclustra/Mercury_XU8_ST1_Reference_Design/tree/master/reference_design). The Ethernet subsystem is integrated into this existing reference design to enable 1G Ethernet communication.

<img src="figures/1G_PL_SFP/firmware_top_level.png" alt="firmware_top_level" width="900" height="600">

The reference clock and SFP pins are configured as external ports in the design. The clock is provided by a clock generator located on the baseboard, while the SFP pins are routed to an SFP cage on the baseboard, enabling Ethernet connectivity.  

The Ethernet IP and DMA IP are controlled via AXI interfaces, allowing the drivers to access and configure their registers. Additionally, the TX/RX channels of the DMA are connected to the processor through high-performance ports. This configuration allows the data stream to utilize a high-bandwidth path.

<img src="figures/1G_PL_SFP/ethernet_subsystem.png" alt="ethernet_subsystem" width="900" height="600">

The AXI 1G/2.5G Ethernet Subsystem IP operates alongside the AXI DMA IP to enable high-performance packet transmission and reception. Incoming packets are written to processor system memory via the S2MM (Stream to Memory-Mapped) port, while outgoing packets are fetched from system memory using the MM2S (Memory-Mapped to Stream) interface and transmitted over the SFP lines. The processor is notified of completed transmit and receive operations through DMA interrupts, allowing efficient synchronization and data flow management.

<img src="figures/1G_PL_SFP/ethernet_phy_interface_config.png" alt="ethernet_phy_interface_config" width="800" height="600">

Apply PHY interface settings as shown above.

<img src="figures/1G_PL_SFP/ethernet_mac_features.png" alt="ethernet_mac_features" width="800" height="600">

Apply MAC feature settings as shown above.

The GT location can be set to **"X0Y11"**, as the assigned pins for the SFP interface are mapped to this location. This ensures proper connectivity and alignment with the FPGA’s transceiver architecture.The remaining settings can be left at their default values.

### 3.1.2 - Build Vivado Project

To build the project, open Vivado 2022.1 and access the TCL console. Navigate to the script directory and execute `create_project.tcl` to generate the block design. This script automates the creation of the hardware design.

```tcl
cd <base_directory_path>
source ./scripts/create_project.tcl
```
After generating bitstream, export the XSA file including the bitstream to ensure that the complete hardware design is available for integration with PetaLinux. Detailed instructions for this process can be found in the [reference design documentation](https://github.com/enclustra/Mercury_XU8_ST1_Reference_Design/tree/master/reference_design/doc).


## 3.2 - PetaLinux Design

PetaLinux is used to build a custom Linux system tailored for the Mercury+ XU8 module and ST1 baseboard, enabling seamless integration of the 1G Ethernet subsystem. After completing the firmware design in Vivado the hardware configuration, is exported as an .xsa file and imported into a PetaLinux project. This allows the system to generate the necessary device tree and hardware configuration.

PetaLinux Version: 2022.1

### 3.2.1 - Project Creation from BSP

The PetaLinux project is generated using the pre-compiled BSP file for the XU8 module, which can be downloaded from the [official source](https://github.com/enclustra/Mercury_XU8_ST1_Reference_Design/releases/download/2022.1_v1.1.2/Petalinux_ME-XU8-7EV-2I-D12E_ST1_SD.bsp). The boot method is set to SD Card, ensuring that the BSP file configures the project accordingly to support booting from an SD card. This setup simplifies the boot process and allows the system to load the Linux kernel, root filesystem, and device tree directly from the SD card.

Please follow [Enclustra BSP usage documentation](https://github.com/enclustra/PetalinuxDocumentation/blob/master/doc/BSP.md) in order to create PetaLinux project.

After creating the PetaLinux project using the BSP, update the hardware to include the Ethernet design by running the following command:

```bash
petalinux-config --get-hw-description=<path_to_xsa>
```

Replace `<path_to_xsa>` with the actual path to the exported `.xsa` file from Vivado. This ensures that the PetaLinux project is updated with the latest hardware configuration, including the Ethernet subsystem.

### 3.2.2 - Device Tree

The device tree for the firmware design is automatically generated by the PetaLinux tool based on the hardware description from the `.xsa` file. This ensures that all peripherals, including the Ethernet subsystem, are correctly integrated into the Linux environment. The generated device tree defines the AXI 1G/2.5G Ethernet Subsystem along with its DMA configuration, specifying register addresses, interrupt assignments, and PHY mode.

```dts
hier_ethernet_axi_dma_0: dma@80000000 {
    #dma-cells = <1>;
    clock-names = "s_axi_lite_aclk", "m_axi_sg_aclk", "m_axi_mm2s_aclk", "m_axi_s2mm_aclk";
    clocks = <&zynqmp_clk 73>, <&zynqmp_clk 73>, <&zynqmp_clk 73>, <&zynqmp_clk 73>;
    compatible = "xlnx,eth-dma";
    interrupt-names = "mm2s_introut", "s2mm_introut";
    interrupt-parent = <&gic>;
    interrupts = <0 89 4 0 90 4>;
    reg = <0x0 0x80000000 0x0 0x10000>;
    xlnx,addrwidth = /bits/ 8 <0x20>;
    xlnx,include-dre ;
    xlnx,num-queues = /bits/ 16 <0x1>;
};
hier_ethernet_axi_ethernet_0: ethernet@80040000 {
    axistream-connected = <&hier_ethernet_axi_dma_0>;
    axistream-control-connected = <&hier_ethernet_axi_dma_0>;
    clock-frequency = <100000000>;
    clock-names = "s_axi_lite_clk", "axis_clk", "ref_clk";
    clocks = <&zynqmp_clk 73>, <&zynqmp_clk 73>, <&zynqmp_clk 72>;
    compatible = "xlnx,axi-ethernet-7.2", "xlnx,axi-ethernet-1.00.a";
    device_type = "network";
    interrupt-names = "mac_irq", "interrupt", "mm2s_introut", "s2mm_introut";
    interrupt-parent = <&gic>;
    interrupts = <0 91 1 0 92 4 0 89 4 0 90 4>;
    local-mac-address = [00 0a 35 00 00 00];
    phy-handle = <&hier_ethernet_axi_ethernet_0phy2>;
    phy-mode = "1000base-x";
    reg = <0x0 0x80040000 0x0 0x40000>;
    xlnx = <0x0>;
    xlnx,axiliteclkrate = <0x0>;
    xlnx,axisclkrate = <0x0>;
    xlnx,channel-ids = <0x1>;
    xlnx,clockselection = <0x0>;
    xlnx,enableasyncsgmii = <0x0>;
    xlnx,gt-type = <0x0>;
    xlnx,gtinex = <0x0>;
    xlnx,gtlocation = <0x0>;
    xlnx,gtrefclksrc = <0x0>;
    xlnx,include-dre ;
    xlnx,instantiatebitslice0 = <0x0>;
    xlnx,num-queues = /bits/ 16 <0x1>;
    xlnx,phy-type = <0x5>;
    xlnx,phyaddr = <0x2>;
    xlnx,phyrst-board-interface-dummy-port = <0x0>;
    xlnx,rable = <0x0>;
    xlnx,rxcsum = <0x2>;
    xlnx,rxlane0-placement = <0x0>;
    xlnx,rxlane1-placement = <0x0>;
    xlnx,rxmem = <0x8000>;
    xlnx,rxnibblebitslice0used = <0x0>;
    xlnx,tx-in-upper-nibble = <0x1>;
    xlnx,txcsum = <0x2>;
    xlnx,txlane0-placement = <0x0>;
    xlnx,txlane1-placement = <0x0>;
    xlnx,versal-gt-board-flow = <0x0>;
    zclock-names = "NULL";
    zclocks = "NULL";
    hier_ethernet_axi_ethernet_0_mdio: mdio {
        #address-cells = <1>;
        #size-cells = <0>;
        hier_ethernet_axi_ethernet_0phy2: phy@2 {
            device_type = "ethernet-phy";
            reg = <2>;
        };
    };
};
```

### 3.2.3 - FSBL Modification

The Ethernet IP requires a stable reference clock to operate at the specified frequency. This clock is provided by the Si5338 clock generator (component U800) on the ST1 board. Before the PL design is loaded into memory, the clock generator must be programmed to ensure it delivers the correct output frequency. It is configured to provide the required frequency through its differential output (CLK3), which is routed to the XU8 module and then to the Ethernet IP within the PL design.

To achieve this, a [patch](code/1G_PL_SFP/petalinux/project-spec/meta-user/recipes-bsp/embeddedsw/files/0001-ClockGen-156-25Mhz-programming.patch) which sets the clock 156.25 MHz located in the [`/embeddedsw`](code/1G_PL_SFP/petalinux/project-spec/meta-user/recipes-bsp) directory modify the FSBL source code to program the clock generator before the FPGA bitstream is loaded. This patch adjusts the required register values, ensuring that the Ethernet subsystem receives a stable and accurate clock signal from the start.

If a different clock frequency is required, [ClockBuilderPro](https://www.skyworksinc.com/en/Application-Pages/Clockbuilder-Pro-Software) software can be used to generate a new C file with updated register settings. The generated register map should then replace the existing data in the `Si5338_register_map.h` file to apply the new configuration.

**NOTE** : Copy the `embeddedsw` folder into the `recipes-bsp` directory of the PetaLinux project.  

### 3.2.4 - U-Boot Configuration
To enable support for the 1G PL AXI Ethernet interface in U-Boot, the following configurations should be enabled. Following configurations are enabled by default in U-Boot.

```
CONFIG_DM_ETH=y
CONFIG_XILINX_AXIEMAC=y 
```
<img src="figures/1G_PL_SFP/u-boot_config.png" alt="u-boot_config" width="600" height="300">


### 3.2.5 - Kernel Configuration  
The kernel driver connects to the Ethernet subsystem through the device tree, which provides the necessary hardware information to the Linux kernel. During boot, the kernel parses the device tree to locate and initialize the AXI 1G/2.5G Ethernet Subsystem and its associated DMA controller.  

The driver matches the hardware using the compatible string defined in the device tree. When the kernel detects a node with a matching compatible string, it loads the corresponding driver and maps the memory regions, interrupt lines, and other required resources. The driver also reads additional properties such as PHY mode, base addresses, and DMA configuration to properly initialize the Ethernet subsystem.  

Once the driver is loaded, it registers itself with the Linux network stack, enabling user-space applications to interact with the Ethernet interface through standard networking APIs.

The following config options should be enabled in order to build the AXI Ethernet driver. However, these configurations are enabled by default in this example.  
```
CONFIG_ETHERNET  
CONFIG_NET_VENDOR_XILINX  
CONFIG_XILINX_AXI_EMAC  
CONFIG_XILINX_PHY  
```

<img src="figures/1G_PL_SFP/kernel_config.png" alt="kernel_config" width="800" height="300"><br>


## 3.3 - U-Boot

This note provides instructions for testing the SFP-based Ethernet connection in U-Boot. The test help verify the link status and basic communication in U-Boot level.

### 3.3.1 - Prerequisites

Before performing the tests, ensure the following:

- A system with U-Boot access and an SFP-compatible Ethernet interface
- 1000BASE-T SFP modules connected
- Compatible cable with SFP module

### 3.3.2 - Testing
#### Step 1: Boot into U-Boot

Power on the system and stop the boot process to enter the U-Boot command line by pressing any key when prompted.

#### Step 2: Identify Network Interfaces

List available network interfaces using
```bash
mii device
```

Set 'eth2' as current device
```bash
mii device eth2
```

Print information of the device
```bash
mii info
```

<img src="figures/1G_PL_SFP/u-boot-mii-info.png" alt="u-boot-mii-info" width="800" height="100">


#### Step 3: Configure IP Addresses

Assign a static IP address to the U-Boot network interface:

```bash
setenv ipaddr 192.168.2.100
setenv netmask 255.255.255.0
setenv serverip 192.168.2.10
saveenv
```

Ensure the target system (host PC) has a compatible IP setup.

#### Step 4: Test Network Connectivity

Ping the host PC to verify basic communication:

```bash
ping 192.168.2.10
```

<img src="figures/1G_PL_SFP/u-boot-ping.png" alt="u-boot-ping" width="800" height="100"><br>


## 3.4 - Linux 

This application note provides a step-by-step guide to test the SFP-based Ethernet connection on a Linux system using the `iperf3` tool. The procedure verifies link stability, bandwidth performance, and data transmission reliability between connected devices.

### 3.4.1 - Prerequisites
Before running the test, ensure the following:
- Two systems with SFP ports (e.g., FPGA-based board and a host PC)
- Compatible 1000BASE-X SFP modules
- Compatible cable with the modules
- `iperf3` installed on both systems

### 3.4.2 - Testing
#### Step 1: Verify SFP Link Status
Before running `iperf3`, check the status of the link.

1. Check link status:
   ```bash
   ethtool eth2
   ```
   Ensure that `Link detected: yes` and the correct speed `1000Mb/s` is displayed.

    <img src="figures/1G_PL_SFP/ethtool_output.png" alt="ethtool_output" width="400" height="300">


#### Step 2: Configure IP Addresses
Assign static IP addresses.

On the FPGA module:
```bash
ifconfig eth2 192.168.2.10
```

On the host system:
```bash
ifconfig eth0 192.168.2.20
```
#### Step 3: Start iperf3 Server
On the host systems, start the `iperf3` server:
```bash
iperf3 -s
```
This system will listen for incoming test traffic.

#### Step 4: Run iperf3 Client
On the FPGA module, run `iperf3` as a client to send test traffic:
```bash
iperf3 -c 192.168.2.20
```

<img src="figures/1G_PL_SFP/iperf_output.png" alt="iperf_output" width="600" height="400">

**Please continue reading chapter 4 [10G PL SFP](./Chapter-4-10G_PL_SFP.md)**


