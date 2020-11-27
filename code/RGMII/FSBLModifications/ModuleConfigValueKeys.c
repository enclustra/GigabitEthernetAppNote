/**---------------------------------------------------------------------------------------------------
-- Copyright (c) 2020 by Enclustra GmbH, Switzerland.
--
-- Permission is hereby granted, free of charge, to any person obtaining a copy of
-- this hardware, software, firmware, and associated documentation files (the
-- "Product"), to deal in the Product without restriction, including without
-- limitation the rights to use, copy, modify, merge, publish, distribute,
-- sublicense, and/or sell copies of the Product, and to permit persons to whom the
-- Product is furnished to do so, subject to the following conditions:
--
-- The above copyright notice and this permission notice shall be included in all
-- copies or substantial portions of the Product.
--
-- THE PRODUCT IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
-- INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
-- PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
-- HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
-- OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
-- PRODUCT OR THE USE OR OTHER DEALINGS IN THE PRODUCT.
---------------------------------------------------------------------------------------------------
*/

#include "ModuleConfigConstants.h"

//-------------------------------------------------------------------------------------------------
// Cosmos XZQ10
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == COSMOS_XZQ10
 const ModulePropertyValueKey_t COSMOS_XZQ10_SOC_TYPE_VALUE_KEY[4] = {
{0, "Xilinx Zynq-7030 FBG\0" }, 
{1, "Xilinx Zynq-7035 FBG\0" }, 
{2, "Xilinx Zynq-7045 FFG\0" }, 
{3, "Xilinx Zynq-7030 FFG\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_USB_C_POWER_MODE_VALUE_KEY[2] = {
{0, "Not supported\0" }, 
{1, "USB type-C current 3A supported\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_USB_C_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_SFP_PORTS_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_QSFP_PORT_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_FMC0_CONNECTOR_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_FMC1_CONNECTOR_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_MGT_MULTIPLEXERS_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t COSMOS_XZQ10_SYSTEM_MONITOR_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mars AX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_AX3
 const ModulePropertyValueKey_t MARS_AX3_FPGA_TYPE_VALUE_KEY[4] = {
{1, "Xilinx Artix-7 XC7A35T\0" }, 
{2, "Xilinx Artix-7 XC7A50T\0" }, 
{3, "Xilinx Artix-7 XC7A75T\0" }, 
{4, "Xilinx Artix-7 XC7A100T\0" }
 };
 const ModulePropertyValueKey_t MARS_AX3_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MARS_AX3_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MARS_AX3_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MARS_AX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mars MX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX1
 const ModulePropertyValueKey_t MARS_MX1_FPGA_TYPE_VALUE_KEY[4] = {
{0, "Xilinx Spartan-6 XC6SLX9\0" }, 
{1, "Xilinx Spartan-6 XC6SLX16\0" }, 
{2, "Xilinx Spartan-6 XC6SLX25\0" }, 
{3, "Xilinx Spartan-6 XC6SLX45\0" }
 };
 const ModulePropertyValueKey_t MARS_MX1_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MARS_MX1_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MARS_MX1_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MARS_MX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mars MX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX2
 const ModulePropertyValueKey_t MARS_MX2_FPGA_TYPE_VALUE_KEY[2] = {
{0, "Xilinx Spartan-6 XC6SLX25T\0" }, 
{1, "Xilinx Spartan-6 XC6SLX45T\0" }
 };
 const ModulePropertyValueKey_t MARS_MX2_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MARS_MX2_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MARS_MX2_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MARS_MX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mars ZX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX2
 const ModulePropertyValueKey_t MARS_ZX2_SOC_TYPE_VALUE_KEY[2] = {
{0, "Xilinx Zynq-7010\0" }, 
{1, "Xilinx Zynq-7020\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX2_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX2_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX2_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mars ZX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX3
 const ModulePropertyValueKey_t MARS_ZX3_SOC_TYPE_VALUE_KEY[1] = {
{0, "Xilinx Zynq-7020\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX3_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX3_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX3_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MARS_ZX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury AA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_AA1
 const ModulePropertyValueKey_t MERCURY_AA1_SOC_TYPE_VALUE_KEY[2] = {
{0, "Altera Arria 10 10AS027\0" }, 
{1, "Altera Arria 10 10AS048\0" }
 };
 const ModulePropertyValueKey_t MERCURY_AA1_SOC_TRANSCEIVER_SPEED_GRADE_VALUE_KEY[4] = {
{0, "1\0" }, 
{1, "2\0" }, 
{2, "3\0" }, 
{3, "4\0" }
 };
 const ModulePropertyValueKey_t MERCURY_AA1_TEMPERATURE_RANGE_VALUE_KEY[3] = {
{0, "Commercial\0" }, 
{1, "Extended\0" }, 
{2, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_AA1_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_AA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury CA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_CA1
 const ModulePropertyValueKey_t MERCURY_CA1_FPGA_TYPE_VALUE_KEY[5] = {
{0, "Altera Cyclone IV EP4CE30\0" }, 
{1, "Altera Cyclone IV EP4CE40\0" }, 
{2, "Altera Cyclone IV EP4CE55\0" }, 
{3, "Altera Cyclone IV EP4CE75\0" }, 
{4, "Altera Cyclone IV EP4CE115\0" }
 };
 const ModulePropertyValueKey_t MERCURY_CA1_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_CA1_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_CA1_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MERCURY_CA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury KX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_KX1
 const ModulePropertyValueKey_t MERCURY_KX1_FPGA_TYPE_VALUE_KEY[6] = {
{0, "Xilinx Kintex-7 XC7K160T FBG\0" }, 
{1, "Xilinx Kintex-7 XC7K325T FBG\0" }, 
{2, "Xilinx Kintex-7 XC7K410T FBG\0" }, 
{3, "Xilinx Kintex-7 XC7K160T FFG\0" }, 
{4, "Xilinx Kintex-7 XC7K325T FFG\0" }, 
{5, "Xilinx Kintex-7 XC7K410T FFG\0" }
 };
 const ModulePropertyValueKey_t MERCURY_KX1_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_KX1_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_KX1_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MERCURY_KX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury KX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_KX2
 const ModulePropertyValueKey_t MERCURY_KX2_FPGA_TYPE_VALUE_KEY[4] = {
{0, "Xilinx Kintex-7 XC7K160T FBG\0" }, 
{1, "Xilinx Kintex-7 XC7K160T FFG\0" }, 
{2, "Xilinx Kintex-7 XC7K325T FFG\0" }, 
{3, "Xilinx Kintex-7 XC7K410T FFG\0" }
 };
 const ModulePropertyValueKey_t MERCURY_KX2_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_KX2_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_KX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU1
 const ModulePropertyValueKey_t MERCURY_XU1_MPSOC_TYPE_VALUE_KEY[5] = {
{0, "Xilinx Zynq UltraScale+ XCZU9EG ES\0" }, 
{1, "Xilinx Zynq UltraScale+ XCZU6EG\0" }, 
{2, "Xilinx Zynq UltraScale+ XCZU9EG\0" }, 
{3, "Xilinx Zynq UltraScale+ XCZU15EG\0" }, 
{4, "Xilinx Zynq UltraScale+ XCZU6CG\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU1_TEMPERATURE_GRADE_VALUE_KEY[3] = {
{0, "Commercial\0" }, 
{1, "Extended\0" }, 
{2, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU1_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU1_EXTENDED_MGT_ROUTING_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU1_DDR4_ECC_ENABLED_VALUE_KEY[2] = {
{0, "Yes\0" }, 
{1, "No\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU5
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU5
 const ModulePropertyValueKey_t MERCURY_XU5_MPSOC_TYPE_VALUE_KEY[4] = {
{0, "Xilinx Zynq UltraScale+ XCZU2EG\0" }, 
{1, "Xilinx Zynq UltraScale+ XCZU3EG\0" }, 
{2, "Xilinx Zynq UltraScale+ XCZU4EV\0" }, 
{3, "Xilinx Zynq UltraScale+ XCZU5EV\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU5_TEMPERATURE_GRADE_VALUE_KEY[3] = {
{0, "Commercial\0" }, 
{1, "Extended\0" }, 
{2, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU5_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU5_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU5_ALTERNATIVE_MGT_ROUTING_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU7
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU7
 const ModulePropertyValueKey_t MERCURY_XU7_MPSOC_TYPE_VALUE_KEY[3] = {
{0, "Xilinx Zynq UltraScale+ XCZU6EG\0" }, 
{1, "Xilinx Zynq UltraScale+ XCZU9EG\0" }, 
{2, "Xilinx Zynq UltraScale+ XCZU15EG\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU7_TEMPERATURE_GRADE_VALUE_KEY[3] = {
{0, "Commercial\0" }, 
{1, "Extended\0" }, 
{2, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU7_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU7_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU8
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU8
 const ModulePropertyValueKey_t MERCURY_XU8_MPSOC_TYPE_VALUE_KEY[3] = {
{0, "Xilinx Zynq UltraScale+ XCZU4CG\0" }, 
{1, "Xilinx Zynq UltraScale+ XCZU5EV\0" }, 
{2, "Xilinx Zynq UltraScale+ XCZU7EV\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU8_TEMPERATURE_GRADE_VALUE_KEY[3] = {
{0, "Commercial\0" }, 
{1, "Extended\0" }, 
{2, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU8_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU8_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU9
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU9
 const ModulePropertyValueKey_t MERCURY_XU9_MPSOC_TYPE_VALUE_KEY[4] = {
{0, "Xilinx Zynq UltraScale+ XCZU4CG\0" }, 
{1, "Xilinx Zynq UltraScale+ XCZU4EV\0" }, 
{2, "Xilinx Zynq UltraScale+ XCZU5EV\0" }, 
{3, "Xilinx Zynq UltraScale+ XCZU7EV\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU9_TEMPERATURE_GRADE_VALUE_KEY[3] = {
{0, "Commercial\0" }, 
{1, "Extended\0" }, 
{2, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU9_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_XU9_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mars XU3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_XU3
 const ModulePropertyValueKey_t MARS_XU3_MPSOC_TYPE_VALUE_KEY[4] = {
{0, "Xilinx Zynq UltraScale+ XCZU3EG ES\0" }, 
{1, "Xilinx Zynq UltraScale+ XCZU2EG\0" }, 
{2, "Xilinx Zynq UltraScale+ XCZU2CG\0" }, 
{3, "Xilinx Zynq UltraScale+ XCZU3EG\0" }
 };
 const ModulePropertyValueKey_t MARS_XU3_MPSOC_SPEED_GRADE_VALUE_KEY[4] = {
{0, "1L\0" }, 
{1, "1\0" }, 
{2, "2\0" }, 
{3, "3\0" }
 };
 const ModulePropertyValueKey_t MARS_XU3_TEMPERATURE_GRADE_VALUE_KEY[3] = {
{0, "Commercial\0" }, 
{1, "Extended\0" }, 
{2, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MARS_XU3_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury SA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA1
 const ModulePropertyValueKey_t MERCURY_SA1_SOC_TYPE_VALUE_KEY[3] = {
{0, "Altera Cyclone V 5CSEBA2U23\0" }, 
{1, "Altera Cyclone V 5CSXFC5C6U23\0" }, 
{2, "Altera Cyclone V 5CSXFC6C6U23\0" }
 };
 const ModulePropertyValueKey_t MERCURY_SA1_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_SA1_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_SA1_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MERCURY_SA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mars MA3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MA3
 const ModulePropertyValueKey_t MARS_MA3_SOC_TYPE_VALUE_KEY[4] = {
{0, "Altera Cyclone V 5CSEBA4U23\0" }, 
{1, "Altera Cyclone V 5CSEBA5U23\0" }, 
{2, "Altera Cyclone V 5CSXFC5C6U23\0" }, 
{3, "Altera Cyclone V 5CSXFC6C6U23\0" }
 };
 const ModulePropertyValueKey_t MARS_MA3_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MARS_MA3_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MARS_MA3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury SA2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA2
 const ModulePropertyValueKey_t MERCURY_SA2_SOC_TYPE_VALUE_KEY[1] = {
{0, "Altera Cyclone V 5CSTFD6D5F31\0" }
 };
 const ModulePropertyValueKey_t MERCURY_SA2_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_SA2_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_SA2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury ZX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX1
 const ModulePropertyValueKey_t MERCURY_ZX1_SOC_TYPE_VALUE_KEY[3] = {
{0, "Xilinx Zynq-7030 FBG\0" }, 
{1, "Xilinx Zynq-7035 FBG\0" }, 
{2, "Xilinx Zynq-7045 FFG\0" }
 };
 const ModulePropertyValueKey_t MERCURY_ZX1_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_ZX1_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_ZX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

//-------------------------------------------------------------------------------------------------
// Mercury ZX5
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX5
 const ModulePropertyValueKey_t MERCURY_ZX5_SOC_TYPE_VALUE_KEY[2] = {
{0, "Xilinx Zynq-7015\0" }, 
{1, "Xilinx Zynq-7030\0" }
 };
 const ModulePropertyValueKey_t MERCURY_ZX5_TEMPERATURE_GRADE_VALUE_KEY[2] = {
{0, "Commercial\0" }, 
{1, "Industrial\0" }
 };
 const ModulePropertyValueKey_t MERCURY_ZX5_POWER_GRADE_VALUE_KEY[2] = {
{0, "Normal\0" }, 
{1, "Low power\0" }
 };
 const ModulePropertyValueKey_t MERCURY_ZX5_ETHERNET_SPEED_VALUE_KEY[2] = {
{0, "Fast\0" }, 
{1, "Gigabit\0" }
 };
 const ModulePropertyValueKey_t MERCURY_ZX5_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[2] = {
{0, "No\0" }, 
{1, "Yes\0" }
 };
#endif

