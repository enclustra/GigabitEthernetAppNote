# Gigabit Ethernet Application Note

# Purpose
This application note provides the meanings of setting up Gigabit Ethernet on Enclustra hardware.

# Summary
This application note gives an overview over the setup process for Gigabit Ethernet on Enclustra hardware.
This includes obtaining the individual MAC addresses of the hardware in use, setting
the correct RGMII timing constraints and configuring the PHY delays via MDIO. As addition, a brief description of the GMII to RGMII converter design, included in some reference designs, explains the useage and provides information to meet timing closure.

# License
Copyright 2025 by Enclustra GmbH, Switzerland.

Permission is hereby granted, free of charge, to any person obtaining a copy of this hardware, software,
firmware, and associated documentation files (the ”Product”), to deal in the Product without restriction, including
without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Product, and to permit persons to whom the Product is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions
of the Product.

THE PRODUCT IS PROVIDED ”AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE PRODUCT OR THE USE OR OTHER DEALINGS
IN THE PRODUCT.

# Introduction
The following chapters and sections describe in detail the hardware setup for enabling Gigabit Ethernet on Enclustra hardware. The Gigabit Ethernet PHY used on all current Enclustra modules are the [Microchip KSZ9031RNX](https://www.microchip.com/wwwproducts/en/KSZ9031) and [Microchip KSZ9131RNX](https://www.microchip.com/wwwproducts/en/KSZ9131).

# Table of contents
* [1 - MAC address](./Chapter-1-MAC_address.md)
    - [1.1 Enclustra Module Configuration Tool (MCT)](Chapter-1-MAC_address.md#11-module-configuration-tool-mct)
    - [1.2 Bare metal](Chapter-1-MAC_address.md#12-bare-metal)
    - [1.3 U-boot](Chapter-1-MAC_address.md#13-u-boot)
    - [1.4 Linux](Chapter-1-MAC_address.md#14-linux)
* [2 - PHY Configuration](./Chapter-2-PHY_configuration.md)
    - [2.1 KSZ9031RNX](Chapter-2-PHY_configuration.md#KSZ9031RNX)
    - [2.2 KSZ9131RNX](Chapter-2-PHY_configuration.md#KSZ9131RNX)
* [3 - 1G PL SFP Design](./Chapter-3-1G_PL_SFP.md)
    - [3.1 Vivado Design](Chapter-3-1G_PL_SFP.md#vivado-design)
    - [3.2 Petalinux Design](Chapter-3-1G_PL_SFP.md#petalinux-design)
    - [3.3 U-boot](Chapter-3-1G_PL_SFP.md#u-boot)
    - [3.4 Linux](Chapter-3-1G_PL_SFP.md#linux)
* [4 - 10G PL SFP Design](./Chapter-4-10G_PL_SFP.md)
    - [4.1 Vivado Design](Chapter-4-10G_PL_SFP.md#vivado-design)
    - [4.2 Petalinux Design](Chapter-4-10G_PL_SFP.md#petalinux-design)
    - [4.3 Linux](Chapter-4-1G_PL_SFP.md#linux)
* [5 - GMII to RGMII](./Chapter-5-GMII_to_RGMII.md)
    - [5.1 Affected Modules/Reference Designs](Chapter-5-GMII_to_RGMII.md#affected-modules/reference-designs)
    - [5.2 Block Diagram](Chapter-5-GMII_to_RGMII.md#block-diagram)
    - [5.3 Clocking](Chapter-5-GMII_to_RGMII.md#clocking)
    - [5.4 VHDL Component Declaration](Chapter-5-GMII_to_RGMII.md#vhdl-componenet-declaration)
    - [5.5 Signal Description](Chapter-5-GMII_to_RGMII.md#vhdl-componenet-declaration)
    - [5.6 Timing Constraints Description](Chapter-5-GMII_to_RGMII.md#vhdl-componenet-declaration)
    - [5.7 Placement Constraints Description](Chapter-5-GMII_to_RGMII.md#placement-constraints-description)
    - [5.8 PHY Delay Configuration](Chapter-5-GMII_to_RGMII.md#vhdl-phy-delay-configuration)
    - [5.9 Tips when Timing Constraints are not met](Chapter-5-GMII_to_RGMII.md#tips-when-timing-constraints-are-not-met)
    - [5.10 Variation between different Enclustra modules](Chapter-5-GMII_to_RGMII.md#variation-between-different-enclustra-modules)
* [6 - PS Ethernet](./Chapter-6-PS-Ethernet.md)
    - [6.1 GMII (Gigabit Media Independent Interface)](Chapter-6-PS-Ethernet.md#gmii)
    - [6.2 RGMII (Reduced Gigabit Media Independent Interface)](Chapter-6-PS-Ethernet.md#rgmii)
    - [6.3 SGMII (Serial Gigabit Media Independent Interface)](Chapter-6-PS-Ethernet.md#sgmii)
    - [6.4 Device Tree](Chapter-6-PS-Ethernet.md#device-tree)  

# References
* [Microchip KSZ9031RNX data sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/00002117F.pdf)
* [Microchip KSZ9131RNX data sheet](https://ww1.microchip.com/downloads/aemDocuments/documents/UNG/ProductDocuments/DataSheets/00002841D.pdf)
* [Xilinx LWIP App Note XAPP1026](https://www.xilinx.com/support/documentation/application_notes/xapp1026.pdf)
* [Xilinx LWIP library](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18842366/Standalone+LWIP+library)
* [Enclustra MCT](https://www.enclustra.com/en/products/tools/module-configuration-tool/)
* [Enclustra EBE kernel](https://github.com/enclustra-bsp/xilinx-linux)
* [AMD 10G/25G Ethernet Subsystem](https://www.xilinx.com/products/intellectual-property/ef-di-25gemac.html)
* [AMD 1G/2.5G Ethernet Subsystem](https://www.amd.com/en/products/adaptive-socs-and-fpgas/intellectual-property/axi_ethernet.html)
* [Iperf3](https://github.com/esnet/iperf)
* [U-Boot AXI Ethernet Driver](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/152207646/U-boot+axi+ethernet)
* [Linux AXI Ethernet Driver](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18842485/Linux+AXI+Ethernet+driver)
* [Zynq Ultrascale+ Technical Reference Manual](https://docs.amd.com/v/u/en-US/ug1085-zynq-ultrascale-trm)
* [MPSoC PS and PL Ethernet Example Projects](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/478937213/MPSoC+PS+and+PL+Ethernet+Example+Projects) 

