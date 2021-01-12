## 1.0.0

* First release

## 1.0.1

* Fixed wrongly named MICREL_PHY_IDENTIFIER: PHY_MICREL_IDENTIFIER is now used in all occurences

## 1.0.2

* Fixed wrongly linked files in [Chapter-2-RGMII_timing_constraints.md](./Chapter-2-RGMII_timing_constraints.md#22-bare-metal)
* Improved code formatting
* Fixed phy_model comparison in [xemacpsif_physpeed.c](./code/RGMII/LWIPModifications/xemacpsif_physpeed.c) so that phy link speed negotiation works with LWIP Echo Server template project in Vitis
* Simplified [xaxiemacif_physpeed.c](./code/RGMII/LWIPModifications/xaxiemacif_physpeed.c) and removed debug prints