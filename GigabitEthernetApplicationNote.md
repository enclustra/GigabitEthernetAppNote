# Gigabit Ethernet Application Note

# Purpose
This application note provides the meanings of setting up Gigabit Ethernet on Enclustra hardware.

# Summary
This application note gives an overview over the setup process for Gigabit Ethernet on Enclustra hardware.
This includes obtaining the individual MAC addresses of the hardware in use, setting
the correct RGMII timing constraints and configuring the PHY delays via MDIO.

# License
Copyright 2020 by Enclustra GmbH, Switzerland.

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
The following chapters and sections describe in detail the hardware setup for enabling Gigabit Ethernet on Enclustra hardware. The Gigabit Ethernet PHY used on all current Enclustra modules is the [Microchip KSZ9031RNX](https://www.microchip.com/wwwproducts/en/KSZ9031).

# Table of contents
* [1 - MAC address](./Chapter-1-MAC_address.md)
    - [1.1 Enclustra Module Configuration Tool (MCT)](Chapter-1-MAC_address.md#11-module-configuration-tool-mct)
    - [1.2 Bare metal](Chapter-1-MAC_address.md#12-bare-metal)
    - [1.3 U-boot](Chapter-1-MAC_address.md#13-u-boot)
    - [1.4 Linux](Chapter-1-MAC_address.md#14-linux)
* [2 - RGMII timing constraints](./Chapter-2-RGMII_timing_constraints.md)
    - [2.1 PHY register configuration via MDIO](Chapter-2-RGMII_timing_constraints.md#21-phy-register-configuration-via-mdio)
    - [2.2 Bare metal](Chapter-2-RGMII_timing_constraints.md#22-bare-metal)
    - [2.3 U-boot](Chapter-2-RGMII_timing_constraints.md#23-u-boot)
    - [2.4 Linux](Chapter-2-RGMII_timing_constraints.md#24-linux)

# References
* [Microchip KSZ9031RNX data sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/00002117F.pdf)
* [Xilinx LWIP App Note XAPP1026](https://www.xilinx.com/support/documentation/application_notes/xapp1026.pdf)
* [Xilinx LWIP library](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18842366/Standalone+LWIP+library)
* [Enclustra MCT](https://www.enclustra.com/en/products/tools/module-configuration-tool/)
* [Enclustra EBE kernel](https://github.com/enclustra-bsp/xilinx-linux)
