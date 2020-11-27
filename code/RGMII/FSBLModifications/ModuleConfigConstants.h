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

#pragma once

#include "StandardIncludes.h"

//-------------------------------------------------------------------------------------------------
// Definitions, typedefs and constants
//-------------------------------------------------------------------------------------------------

#define PRODUCT_FAMILY_CODE_COSMOS_XZQ10 0x0332
#define PRODUCT_FAMILY_CODE_MARS_MX1 0x0320
#define PRODUCT_FAMILY_CODE_MARS_MX2 0x0321
#define PRODUCT_FAMILY_CODE_MERCURY_CA1 0x0322
#define PRODUCT_FAMILY_CODE_MARS_ZX2 0x0329
#define PRODUCT_FAMILY_CODE_MARS_ZX3 0x0323
#define PRODUCT_FAMILY_CODE_MARS_AX3 0x0324
#define PRODUCT_FAMILY_CODE_MERCURY_AA1 0x032D
#define PRODUCT_FAMILY_CODE_MERCURY_KX1 0x0325
#define PRODUCT_FAMILY_CODE_MERCURY_KX2 0x032E
#define PRODUCT_FAMILY_CODE_MERCURY_SA1 0x0326
#define PRODUCT_FAMILY_CODE_MARS_MA3 0x0331
#define PRODUCT_FAMILY_CODE_MERCURY_SA2 0x032A
#define PRODUCT_FAMILY_CODE_MERCURY_XU1 0x032F
#define PRODUCT_FAMILY_CODE_MERCURY_XU5 0x0333
#define PRODUCT_FAMILY_CODE_MERCURY_XU7 0x0334
#define PRODUCT_FAMILY_CODE_MERCURY_XU8 0x0335
#define PRODUCT_FAMILY_CODE_MERCURY_XU9 0x0336
#define PRODUCT_FAMILY_CODE_MERCURY_ZX1 0x0327
#define PRODUCT_FAMILY_CODE_MERCURY_ZX5 0x0328
#define PRODUCT_FAMILY_CODE_MARS_XU3 0x0330
#define MODULE_INFO_ADDRESS_SERIAL_NUMBER 0x00
#define MODULE_INFO_ADDRESS_PRODUCT_NUMBER 0x04
#define MODULE_INFO_ADDRESS_MAC_ADDRESS 0x10

/// Mask defining the position of the product family code in the 32-bit product number.
#define PRODUCT_FAMILY_CODE_MASK 0xFFFF0000
#define PRODUCT_FAMILY_CODE_BIT_OFFSET 16

/// Mask defining the position of the product subtype in the 32-bit product number.
#define PRODUCT_SUBTYPE_MASK 0x0000FF00
#define PRODUCT_SUBTYPE_BIT_OFFSET 8

/// Mask defining the position of the product revision number in the 32-bit product number.
#define REVISION_NUMBER_MASK 0x000000FF



#define MAX_MODULE_NAME_LENGTH_CHARACTERS 32
#define CONFIGURATION_PROPERTY_NAME_MAXLENGTH_CHARACTERS 64


/// Struct for constituent product number elements.
typedef struct ProductNumberInfo_t
{
    uint16_t productFamilyCode;
    uint8_t productSubtype;
    uint8_t revisionNumber;
} ProductNumberInfo_t;


typedef struct
{
    uint8_t value;
    char meaning[CONFIGURATION_PROPERTY_NAME_MAXLENGTH_CHARACTERS];
} ModulePropertyValueKey_t;


/**
 * \brief Struct used for module config properties.
 *
 * Note that the valueAsStored and value fields are not constant; these values
 * are calculated when the module EEPROM config data is read and parsed using
 * Eeprom_ReadModuleConfig().
 */
typedef struct
{
	/// Description of the configuration property; i.e. "FPGA type"
    const char description[CONFIGURATION_PROPERTY_NAME_MAXLENGTH_CHARACTERS];

    /// The address where the config property is stored in EEPROM
    const uint8_t address;

    /// The length of the stored property, in bits
    const uint8_t lengthBits;

    /// Zero-based start bit of the stored property, in the byte where it's stored
    const uint8_t startBit;

    /// Zero-based end bit of the stored property, in the byte where it's stored
    const uint8_t endBit;

    /// Minimum value for the property
    const uint8_t minValue;

    /// Maximum value for the property
    const uint8_t maxValue;

    /// Resolution for memory sizes; this is zero for other properties
    const uint8_t resolution;

    /// The number of keyed values (i.e. raw values which have corresponding text values)
    const uint8_t keyValueCount;

    /// Pointer to array of keyed values
    const ModulePropertyValueKey_t* pValueKey;

    /// The value of the property, as stored in EEPROM
    uint8_t valueAsStored;

    /// The value of the property, translated when a resolution is present
    uint32_t value;
} ModuleConfigProperty_t;


/**
 * \brief Parse a raw 32-bit product number to its constituent parts.
 *
 * @param productNumber 	32-bit product number
 * @return					Struct containing decoded values
 */
static inline ProductNumberInfo_t ParseProductNumber(uint32_t productNumber)
{
    ProductNumberInfo_t productNumberInfo;

    productNumberInfo.productFamilyCode = (productNumber & PRODUCT_FAMILY_CODE_MASK) >> PRODUCT_FAMILY_CODE_BIT_OFFSET;
    productNumberInfo.productSubtype = (productNumber & PRODUCT_SUBTYPE_MASK) >> PRODUCT_SUBTYPE_BIT_OFFSET;
    productNumberInfo.revisionNumber = productNumber & REVISION_NUMBER_MASK;

    return productNumberInfo;
}

//-------------------------------------------------------------------------------------------------
// Global variables
//-------------------------------------------------------------------------------------------------

/// Pointer to array of configuration properties.
extern ModuleConfigProperty_t* g_pConfigProperties;

//-------------------------------------------------------------------------------------------------
// Cosmos XZQ10
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == COSMOS_XZQ10
extern char COSMOS_XZQ10_MODULE_NAME[];
extern ModuleConfigProperty_t COSMOS_XZQ10_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_USB_C_POWER_MODE_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_USB_C_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_SFP_PORTS_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_QSFP_PORT_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_FMC0_CONNECTOR_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_FMC1_CONNECTOR_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_MGT_MULTIPLEXERS_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t COSMOS_XZQ10_SYSTEM_MONITOR_EQUIPPED_VALUE_KEY[];
#define COSMOS_XZQ10_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define COSMOS_XZQ10_CONFIG_PROPERTIES_LENGTH_BYTES 7
#define COSMOS_XZQ10_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define COSMOS_XZQ10_PROPERTY_COUNT 20
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_FAST_ETHERNET_PORT_COUNT 5
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_DDR3L_RAM_PS_SIZE_MB 8
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_DDR3L_RAM_PL_SIZE_MB 9
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 10
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 11
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_USB_C_POWER_MODE 12
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_USB_C_EQUIPPED 13
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_SFP+_PORTS_EQUIPPED 14
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_QSFP+_PORT_EQUIPPED 15
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_FMC0_CONNECTOR_EQUIPPED 16
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_FMC1_CONNECTOR_EQUIPPED 17
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_MGT_MULTIPLEXERS_EQUIPPED 18
#define COSMOS_XZQ10_CONFIG_PROPERTY_INDEX_SYSTEM_MONITOR_EQUIPPED 19
#endif

//-------------------------------------------------------------------------------------------------
// Mars AX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_AX3
extern char MARS_AX3_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_AX3_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_AX3_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_AX3_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_AX3_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_AX3_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_AX3_PROPERTY_COUNT 9
#define MARS_AX3_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MARS_AX3_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MARS_AX3_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_AX3_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_AX3_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_AX3_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_AX3_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_AX3_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 7
#define MARS_AX3_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 8
#endif

//-------------------------------------------------------------------------------------------------
// Mars MX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX1
extern char MARS_MX1_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_MX1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_MX1_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_MX1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_MX1_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_MX1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_MX1_PROPERTY_COUNT 9
#define MARS_MX1_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MARS_MX1_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MARS_MX1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_MX1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_MX1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_MX1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_MX1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_MX1_CONFIG_PROPERTY_INDEX_DDR2_RAM_SIZE_MB 7
#define MARS_MX1_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 8
#endif

//-------------------------------------------------------------------------------------------------
// Mars MX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX2
extern char MARS_MX2_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_MX2_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_MX2_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_MX2_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_MX2_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_MX2_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_MX2_PROPERTY_COUNT 9
#define MARS_MX2_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MARS_MX2_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MARS_MX2_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_MX2_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_MX2_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_MX2_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_MX2_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_MX2_CONFIG_PROPERTY_INDEX_DDR2_RAM_SIZE_MB 7
#define MARS_MX2_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 8
#endif

//-------------------------------------------------------------------------------------------------
// Mars ZX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX2
extern char MARS_ZX2_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_ZX2_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_ZX2_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_ZX2_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_ZX2_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_ZX2_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_ZX2_PROPERTY_COUNT 10
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 8
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 9
#endif

//-------------------------------------------------------------------------------------------------
// Mars ZX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX3
extern char MARS_ZX3_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_ZX3_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_ZX3_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_ZX3_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_ZX3_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MARS_ZX3_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_ZX3_PROPERTY_COUNT 11
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 8
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 9
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_NAND_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury AA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_AA1
extern char MERCURY_AA1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_AA1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_AA1_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_AA1_SOC_TRANSCEIVER_SPEED_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_AA1_TEMPERATURE_RANGE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_AA1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_AA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_AA1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_AA1_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_AA1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_AA1_PROPERTY_COUNT 12
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_SOC_DEVICE_SPEED_GRADE 1
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_SOC_TRANSCEIVER_SPEED_GRADE 2
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_TEMPERATURE_RANGE 3
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_POWER_GRADE 4
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 5
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_USB_3_0_DEVICE_PORT_COUNT 8
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_DDR4_ECC_RAM_SIZE_GB 9
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 10
#define MERCURY_AA1_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 11
#endif

//-------------------------------------------------------------------------------------------------
// Mercury CA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_CA1
extern char MERCURY_CA1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_CA1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_CA1_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_CA1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 26
#define MERCURY_CA1_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MERCURY_CA1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_CA1_PROPERTY_COUNT 10
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_USB_2_0_DEVICE_PORT_COUNT 7
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_DDR2_RAM_SIZE_MB 8
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 9
#endif

//-------------------------------------------------------------------------------------------------
// Mercury KX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_KX1
extern char MERCURY_KX1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_KX1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_KX1_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_KX1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 29
#define MERCURY_KX1_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_KX1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_KX1_PROPERTY_COUNT 11
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_USB_3_0_DEVICE_PORT_COUNT 7
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 8
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 9
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_SECONDARY_DDR3_RAM_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury KX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_KX2
extern char MERCURY_KX2_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_KX2_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_KX2_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX2_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX2_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_KX2_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_KX2_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MERCURY_KX2_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_KX2_PROPERTY_COUNT 9
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 5
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_USB_2_0_DEVICE_PORT_COUNT 6
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 7
#define MERCURY_KX2_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 8
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU1
extern char MERCURY_XU1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_XU1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_XU1_MPSOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU1_EXTENDED_MGT_ROUTING_VALUE_KEY[];
#define MERCURY_XU1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_XU1_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_XU1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_XU1_PROPERTY_COUNT 11
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_MPSOC_TYPE 0
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_MPSOC_SPEED_GRADE 1
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 5
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_EXTENDED_MGT_ROUTING 6
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_DDR4_ECC_RAM_SIZE_GB 8
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 9
#define MERCURY_XU1_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU5
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU5
extern char MERCURY_XU5_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_XU5_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_XU5_MPSOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU5_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU5_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU5_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU5_ALTERNATIVE_MGT_ROUTING_VALUE_KEY[];
#define MERCURY_XU5_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_XU5_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_XU5_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_XU5_PROPERTY_COUNT 12
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_MPSOC_TYPE 0
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_MPSOC_SPEED_GRADE 1
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 5
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_ALTERNATIVE_MGT_ROUTING 6
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_DDR4_ECC_RAM_PS_SIZE_GB 8
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_DDR4_RAM_PL_SIZE_MB 9
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 10
#define MERCURY_XU5_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 11
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU7
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU7
extern char MERCURY_XU7_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_XU7_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_XU7_MPSOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU7_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU7_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU7_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_XU7_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_XU7_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_XU7_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_XU7_PROPERTY_COUNT 11
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_MPSOC_TYPE 0
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_MPSOC_SPEED_GRADE 1
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 5
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 6
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_DDR4_ECC_RAM_PS_SIZE_GB 7
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_DDR4_RAM_PL_SIZE_GB 8
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 9
#define MERCURY_XU7_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU8
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU8
extern char MERCURY_XU8_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_XU8_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_XU8_MPSOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU8_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU8_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU8_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_XU8_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_XU8_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_XU8_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_XU8_PROPERTY_COUNT 11
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_MPSOC_TYPE 0
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_MPSOC_SPEED_GRADE 1
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 5
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 6
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_DDR4_ECC_RAM_PS_SIZE_GB 7
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_DDR4_RAM_PL_SIZE_GB 8
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 9
#define MERCURY_XU8_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury XU9
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_XU9
extern char MERCURY_XU9_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_XU9_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_XU9_MPSOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU9_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU9_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_XU9_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_XU9_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_XU9_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_XU9_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_XU9_PROPERTY_COUNT 11
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_MPSOC_TYPE 0
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_MPSOC_SPEED_GRADE 1
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 5
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 6
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_DDR4_ECC_RAM_PS_SIZE_GB 7
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_DDR4_RAM_PL_SIZE_GB 8
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 9
#define MERCURY_XU9_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mars XU3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_XU3
extern char MARS_XU3_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_XU3_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_XU3_MPSOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_XU3_MPSOC_SPEED_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_XU3_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_XU3_POWER_GRADE_VALUE_KEY[];
#define MARS_XU3_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MARS_XU3_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MARS_XU3_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_XU3_PROPERTY_COUNT 9
#define MARS_XU3_CONFIG_PROPERTY_INDEX_MPSOC_TYPE 0
#define MARS_XU3_CONFIG_PROPERTY_INDEX_MPSOC_SPEED_GRADE 1
#define MARS_XU3_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_XU3_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_XU3_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MARS_XU3_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 5
#define MARS_XU3_CONFIG_PROPERTY_INDEX_DDR4_RAM_SIZE_GB 6
#define MARS_XU3_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 7
#define MARS_XU3_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 8
#endif

//-------------------------------------------------------------------------------------------------
// Mercury SA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA1
extern char MERCURY_SA1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_SA1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_SA1_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_SA1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MERCURY_SA1_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_SA1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_SA1_PROPERTY_COUNT 11
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_DDR3L_RAM_SIZE_MB 8
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 9
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mars MA3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MA3
extern char MARS_MA3_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_MA3_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_MA3_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MA3_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MA3_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MA3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_MA3_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MARS_MA3_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MARS_MA3_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_MA3_PROPERTY_COUNT 11
#define MARS_MA3_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MARS_MA3_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MARS_MA3_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_MA3_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_MA3_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MARS_MA3_CONFIG_PROPERTY_INDEX_FAST_ETHERNET_PORT_COUNT 5
#define MARS_MA3_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_MA3_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MARS_MA3_CONFIG_PROPERTY_INDEX_DDR3L_RAM_SIZE_GB 8
#define MARS_MA3_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 9
#define MARS_MA3_CONFIG_PROPERTY_INDEX_EMMC_FLASH_SIZE_GB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury SA2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA2
extern char MERCURY_SA2_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_SA2_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_SA2_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA2_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA2_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_SA2_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_SA2_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MERCURY_SA2_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_SA2_PROPERTY_COUNT 11
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_FAST_ETHERNET_PORT_COUNT 4
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 5
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_USB_3_0_DEVICE_PORT_COUNT 8
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_DDR3L_RAM_SIZE_MB 9
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury ZX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX1
extern char MERCURY_ZX1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_ZX1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_ZX1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_ZX1_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_ZX1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_ZX1_PROPERTY_COUNT 12
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_FAST_ETHERNET_PORT_COUNT 5
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_DDR3L_RAM_PS_SIZE_MB 8
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_DDR3L_RAM_PL_SIZE_MB 9
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 10
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_NAND_FLASH_SIZE_MB 11
#endif

//-------------------------------------------------------------------------------------------------
// Mercury ZX5
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX5
extern char MERCURY_ZX5_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_ZX5_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_ZX5_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MERCURY_ZX5_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_ZX5_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_ZX5_PROPERTY_COUNT 11
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_DDR3L_RAM_SIZE_MB 8
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_QSPI_FLASH_SIZE_MB 9
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_NAND_FLASH_SIZE_MB 10
#endif

