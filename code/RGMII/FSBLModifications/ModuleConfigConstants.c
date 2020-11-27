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

char COSMOS_XZQ10_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Cosmos XZQ10";
ModuleConfigProperty_t COSMOS_XZQ10_CONFIG_PROPERTIES[COSMOS_XZQ10_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Fast Ethernet port count\0", 0x09, 2, 2, 3, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 1, 1, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3L RAM (PS) size (MB)\0", 0x0B, 4, 4, 7, 0, 8, 8, 0, NULL, 0, 0 }, 
{ "DDR3L RAM (PL) size (MB)\0", 0x0B, 4, 0, 3, 0, 6, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0C, 4, 4, 7, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 0, 3, 0, 5, 1, 0, NULL, 0, 0 }, 
{ "USB-C power mode\0", 0x0D, 3, 1, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_USB_C_POWER_MODE_VALUE_KEY, 0, 0 }, 
{ "USB-C equipped\0", 0x0D, 1, 0, 0, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_USB_C_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "SFP+ ports equipped\0", 0x0E, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_SFP_PORTS_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "QSFP+ port equipped\0", 0x0E, 1, 4, 4, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_QSFP_PORT_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "FMC0 connector equipped\0", 0x0E, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_FMC0_CONNECTOR_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "FMC1 connector equipped\0", 0x0E, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_FMC1_CONNECTOR_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "MGT multiplexers equipped\0", 0x0E, 1, 1, 1, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_MGT_MULTIPLEXERS_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "System monitor equipped\0", 0x0E, 1, 0, 0, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&COSMOS_XZQ10_SYSTEM_MONITOR_EQUIPPED_VALUE_KEY, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&COSMOS_XZQ10_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mars AX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_AX3

char MARS_AX3_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mars AX3";
ModuleConfigProperty_t MARS_AX3_CONFIG_PROPERTIES[MARS_AX3_PROPERTY_COUNT] = {
{ "FPGA type\0", 0x08, 4, 4, 7, 1, 4, 0, 4, (ModulePropertyValueKey_t*)&MARS_AX3_FPGA_TYPE_VALUE_KEY, 0, 0 }, 
{ "FPGA speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_AX3_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_AX3_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_AX3_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_AX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "DDR3 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 7, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MARS_AX3_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mars MX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX1

char MARS_MX1_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mars MX1";
ModuleConfigProperty_t MARS_MX1_CONFIG_PROPERTIES[MARS_MX1_PROPERTY_COUNT] = {
{ "FPGA type\0", 0x08, 4, 4, 7, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MARS_MX1_FPGA_TYPE_VALUE_KEY, 0, 0 }, 
{ "FPGA speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX1_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX1_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX1_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "DDR2 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 5, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MARS_MX1_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mars MX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX2

char MARS_MX2_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mars MX2";
ModuleConfigProperty_t MARS_MX2_CONFIG_PROPERTIES[MARS_MX2_PROPERTY_COUNT] = {
{ "FPGA type\0", 0x08, 4, 4, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX2_FPGA_TYPE_VALUE_KEY, 0, 0 }, 
{ "FPGA speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX2_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX2_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX2_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "DDR2 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 6, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MARS_MX2_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mars ZX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX2

char MARS_ZX2_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mars ZX2";
ModuleConfigProperty_t MARS_ZX2_CONFIG_PROPERTIES[MARS_ZX2_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX2_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX2_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX2_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX2_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 8, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MARS_ZX2_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mars ZX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX3

char MARS_ZX3_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mars ZX3";
ModuleConfigProperty_t MARS_ZX3_CONFIG_PROPERTIES[MARS_ZX3_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 0, 0, 1, (ModulePropertyValueKey_t*)&MARS_ZX3_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX3_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX3_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX3_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_ZX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 8, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "NAND flash size (MB)\0", 0x0C, 4, 0, 3, 0, 10, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MARS_ZX3_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury AA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_AA1

char MERCURY_AA1_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury+ AA1";
ModuleConfigProperty_t MERCURY_AA1_CONFIG_PROPERTIES[MERCURY_AA1_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_AA1_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC device speed grade\0", 0x08, 2, 2, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "SoC transceiver speed grade\0", 0x08, 2, 0, 1, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MERCURY_AA1_SOC_TRANSCEIVER_SPEED_GRADE_VALUE_KEY, 0, 0 }, 
{ "Temperature range\0", 0x09, 2, 6, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_AA1_TEMPERATURE_RANGE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_AA1_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 3, 4, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_AA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 1, 1, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "USB 3.0 device port count\0", 0x0A, 1, 0, 0, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR4 ECC RAM size (GB)\0", 0x0B, 4, 4, 7, 0, 3, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 4, 7, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_AA1_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury CA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_CA1

char MERCURY_CA1_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury CA1";
ModuleConfigProperty_t MERCURY_CA1_CONFIG_PROPERTIES[MERCURY_CA1_PROPERTY_COUNT] = {
{ "FPGA type\0", 0x08, 4, 4, 7, 0, 4, 0, 5, (ModulePropertyValueKey_t*)&MERCURY_CA1_FPGA_TYPE_VALUE_KEY, 0, 0 }, 
{ "FPGA speed grade\0", 0x08, 4, 0, 3, 6, 8, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_CA1_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_CA1_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_CA1_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_CA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 device port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR2 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 6, 8, 0, NULL, 0, 0 }, 
{ "SPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_CA1_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury KX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_KX1

char MERCURY_KX1_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury KX1";
ModuleConfigProperty_t MERCURY_KX1_CONFIG_PROPERTIES[MERCURY_KX1_PROPERTY_COUNT] = {
{ "FPGA type\0", 0x08, 4, 4, 7, 0, 5, 0, 6, (ModulePropertyValueKey_t*)&MERCURY_KX1_FPGA_TYPE_VALUE_KEY, 0, 0 }, 
{ "FPGA speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_KX1_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_KX1_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_KX1_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_KX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 3.0 device port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 9, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "Secondary DDR3 RAM size (MB)\0", 0x0C, 4, 0, 3, 0, 9, 2, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_KX1_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury KX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_KX2

char MERCURY_KX2_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury+ KX2";
ModuleConfigProperty_t MERCURY_KX2_CONFIG_PROPERTIES[MERCURY_KX2_PROPERTY_COUNT] = {
{ "FPGA type\0", 0x08, 4, 4, 7, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MERCURY_KX2_FPGA_TYPE_VALUE_KEY, 0, 0 }, 
{ "FPGA speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_KX2_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_KX2_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 4, 5, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 1, 1, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_KX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 device port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3 RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 10, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_KX2_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury XU1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU1

char MERCURY_XU1_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury+ XU1";
ModuleConfigProperty_t MERCURY_XU1_CONFIG_PROPERTIES[MERCURY_XU1_PROPERTY_COUNT] = {
{ "MPSoC type\0", 0x08, 4, 4, 7, 0, 4, 0, 5, (ModulePropertyValueKey_t*)&MERCURY_XU1_MPSOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "MPSoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 2, 6, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_XU1_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU1_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 3, 4, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "Extended MGT routing\0", 0x09, 1, 1, 1, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU1_EXTENDED_MGT_ROUTING_VALUE_KEY, 0, 0 }, 
{ "DDR4 ECC enabled\0", 0x09, 1, 0, 0, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU1_DDR4_ECC_ENABLED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "DDR4 RAM size (GB)\0", 0x0B, 4, 4, 7, 0, 4, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 4, 7, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_XU1_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury XU5
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU5

char MERCURY_XU5_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury XU5";
ModuleConfigProperty_t MERCURY_XU5_CONFIG_PROPERTIES[MERCURY_XU5_PROPERTY_COUNT] = {
{ "MPSoC type\0", 0x08, 4, 4, 7, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MERCURY_XU5_MPSOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "MPSoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 2, 6, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_XU5_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU5_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 3, 4, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU5_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "Alternative MGT routing\0", 0x09, 1, 1, 1, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU5_ALTERNATIVE_MGT_ROUTING_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "DDR4 ECC RAM (PS) size (GB)\0", 0x0B, 4, 4, 7, 0, 4, 1, 0, NULL, 0, 0 }, 
{ "DDR4 RAM (PL) size (MB)\0", 0x0B, 4, 0, 3, 0, 9, 8, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 4, 7, 0, 5, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0C, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_XU5_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury XU7
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU7

char MERCURY_XU7_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury+ XU7";
ModuleConfigProperty_t MERCURY_XU7_CONFIG_PROPERTIES[MERCURY_XU7_PROPERTY_COUNT] = {
{ "MPSoC type\0", 0x08, 4, 4, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_XU7_MPSOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "MPSoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 2, 6, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_XU7_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU7_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 3, 4, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU7_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "DDR4 ECC RAM (PS) size (GB)\0", 0x0B, 4, 4, 7, 0, 4, 1, 0, NULL, 0, 0 }, 
{ "DDR4 RAM (PL) size (GB)\0", 0x0B, 4, 0, 3, 0, 3, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 4, 7, 0, 5, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0C, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_XU7_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury XU8
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU8

char MERCURY_XU8_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury+ XU8";
ModuleConfigProperty_t MERCURY_XU8_CONFIG_PROPERTIES[MERCURY_XU8_PROPERTY_COUNT] = {
{ "MPSoC type\0", 0x08, 4, 4, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_XU8_MPSOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "MPSoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 2, 6, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_XU8_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU8_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 3, 4, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU8_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "DDR4 ECC RAM (PS) size (GB)\0", 0x0B, 4, 4, 7, 0, 4, 1, 0, NULL, 0, 0 }, 
{ "DDR4 RAM (PL) size (GB)\0", 0x0B, 4, 0, 3, 0, 3, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 4, 7, 0, 5, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0C, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_XU8_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury XU9
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU9

char MERCURY_XU9_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury+ XU9";
ModuleConfigProperty_t MERCURY_XU9_CONFIG_PROPERTIES[MERCURY_XU9_PROPERTY_COUNT] = {
{ "MPSoC type\0", 0x08, 4, 4, 7, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MERCURY_XU9_MPSOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "MPSoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 2, 6, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_XU9_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU9_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 3, 4, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_XU9_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "DDR4 ECC RAM (PS) size (GB)\0", 0x0B, 4, 4, 7, 0, 4, 1, 0, NULL, 0, 0 }, 
{ "DDR4 RAM (PL) size (GB)\0", 0x0B, 4, 0, 3, 0, 4, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 4, 7, 0, 5, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0C, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_XU9_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mars XU3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_XU3

char MARS_XU3_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mars XU3";
ModuleConfigProperty_t MARS_XU3_CONFIG_PROPERTIES[MARS_XU3_PROPERTY_COUNT] = {
{ "MPSoC type\0", 0x08, 4, 4, 7, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MARS_XU3_MPSOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "MPSoC speed grade\0", 0x08, 4, 0, 3, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MARS_XU3_MPSOC_SPEED_GRADE_VALUE_KEY, 0, 0 }, 
{ "Temperature grade\0", 0x09, 2, 6, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MARS_XU3_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 5, 5, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_XU3_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 3, 4, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR4 RAM size (GB)\0", 0x0B, 4, 4, 7, 0, 3, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 4, 7, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MARS_XU3_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury SA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA1

char MERCURY_SA1_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury SA1";
ModuleConfigProperty_t MERCURY_SA1_CONFIG_PROPERTIES[MERCURY_SA1_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_SA1_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 6, 8, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_SA1_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_SA1_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_SA1_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_SA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3L RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 10, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 0, 3, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_SA1_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mars MA3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MA3

char MARS_MA3_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mars MA3";
ModuleConfigProperty_t MARS_MA3_CONFIG_PROPERTIES[MARS_MA3_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 3, 0, 4, (ModulePropertyValueKey_t*)&MARS_MA3_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 6, 8, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MA3_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MA3_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 1, 5, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Fast Ethernet port count\0", 0x09, 1, 4, 4, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MARS_MA3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3L RAM size (GB)\0", 0x0B, 4, 4, 7, 0, 2, 1, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "eMMC flash size (GB)\0", 0x0C, 4, 0, 3, 0, 5, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MARS_MA3_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury SA2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA2

char MERCURY_SA2_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury+ SA2";
ModuleConfigProperty_t MERCURY_SA2_CONFIG_PROPERTIES[MERCURY_SA2_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 0, 0, 1, (ModulePropertyValueKey_t*)&MERCURY_SA2_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 6, 8, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_SA2_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_SA2_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Fast Ethernet port count\0", 0x09, 2, 4, 5, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 1, 3, 3, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_SA2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 1, 1, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "USB 3.0 device port count\0", 0x0A, 1, 0, 0, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3L RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 10, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_SA2_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury ZX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX1

char MERCURY_ZX1_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury ZX1";
ModuleConfigProperty_t MERCURY_ZX1_CONFIG_PROPERTIES[MERCURY_ZX1_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 2, 0, 3, (ModulePropertyValueKey_t*)&MERCURY_ZX1_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX1_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX1_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Gigabit Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Fast Ethernet port count\0", 0x09, 2, 2, 3, 0, 2, 0, 0, NULL, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 1, 1, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3L RAM (PS) size (MB)\0", 0x0B, 4, 4, 7, 0, 8, 8, 0, NULL, 0, 0 }, 
{ "DDR3L RAM (PL) size (MB)\0", 0x0B, 4, 0, 3, 0, 6, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0C, 4, 4, 7, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "NAND flash size (MB)\0", 0x0C, 4, 0, 3, 0, 7, 8, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_ZX1_CONFIG_PROPERTIES;
#endif


//-------------------------------------------------------------------------------------------------
// Mercury ZX5
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX5

char MERCURY_ZX5_MODULE_NAME[MAX_MODULE_NAME_LENGTH_CHARACTERS] = "Mercury ZX5";
ModuleConfigProperty_t MERCURY_ZX5_CONFIG_PROPERTIES[MERCURY_ZX5_PROPERTY_COUNT] = {
{ "SoC type\0", 0x08, 4, 4, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX5_SOC_TYPE_VALUE_KEY, 0, 0 }, 
{ "SoC speed grade\0", 0x08, 4, 0, 3, 1, 3, 0, 0, NULL, 0, 0 }, 
{ "Temperature grade\0", 0x09, 1, 7, 7, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX5_TEMPERATURE_GRADE_VALUE_KEY, 0, 0 }, 
{ "Power grade\0", 0x09, 1, 6, 6, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX5_POWER_GRADE_VALUE_KEY, 0, 0 }, 
{ "Ethernet port count\0", 0x09, 2, 4, 5, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "Ethernet speed\0", 0x09, 1, 3, 3, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX5_ETHERNET_SPEED_VALUE_KEY, 0, 0 }, 
{ "Real-time clock equipped\0", 0x09, 1, 2, 2, 0, 1, 0, 2, (ModulePropertyValueKey_t*)&MERCURY_ZX5_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY, 0, 0 }, 
{ "USB 2.0 port count\0", 0x0A, 2, 0, 1, 0, 1, 0, 0, NULL, 0, 0 }, 
{ "DDR3L RAM size (MB)\0", 0x0B, 4, 4, 7, 0, 8, 8, 0, NULL, 0, 0 }, 
{ "QSPI flash size (MB)\0", 0x0B, 4, 0, 3, 0, 7, 1, 0, NULL, 0, 0 }, 
{ "NAND flash size (MB)\0", 0x0C, 4, 0, 3, 0, 10, 1, 0, NULL, 0, 0 } };
ModuleConfigProperty_t* g_pConfigProperties = (ModuleConfigProperty_t*)&MERCURY_ZX5_CONFIG_PROPERTIES;
#endif
