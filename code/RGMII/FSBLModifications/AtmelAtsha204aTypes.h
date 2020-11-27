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


/**
 * \brief Packet function. Note that these values directly correspond to the value to be used as the register
 *  address when performing an I2C write.
 */
typedef enum
{
    EPacketFunction_Reset = 0x00,
    EPacketFunction_Sleep = 0x01,
    EPacketFunction_Idle = 0x02,
    EPacketFunction_Command = 0x03
} EPacketFunction_t;


/**
 * \brief Command response codes.
 */
typedef enum
{
    /// Command executed successfully
    EStatusCode_Success = 0x00,

    /// The CheckMac command was properly sent to the device, but the input Client response did not match the
    /// expected value
    EStatusCode_InvalidMac = 0x01,

    /// Command was properly received, but the length, command opcode, or parameters are illegal, regardless of the
    /// state (volatile and/or EEPROM configuration) of the ATSHA204A. Changes in the value of the command bits must
    /// be made before it is re-attempted.
    EStatusCode_ParseError = 0x03,

    /// Command was properly received, but could not be executed by the device in its current state. Changes in the
    /// device state or the value of the command bits must be made before it is re-attempted.
    EStatusCode_ExecutionError = 0x0F,

    /// Indication that the ATSHA204A has received a proper Wake token
    EStatusCode_AfterWake = 0x11,

    /// Command was not properly received by the ATSHA204A, and should be re-transmitted by the I/O driver in the
    /// system. No attempt was made to parse or execute the command.
    EStatusCode_IoError = 0xFF
} EStatusCode_t;


/// Read size select
typedef enum
{
    EReadSizeSelect_4Bytes = 4,
    EReadSizeSelect_32Bytes = 32
} EReadSizeSelect_t;


/// Zone select
typedef enum
{
    EZoneSelect_Config = 0,
    EZoneSelect_Otp = 1,
    EZoneSelect_Data = 2
} EZoneSelect_t;


/**
 * \brief Command opcodes.
 */
typedef enum
{
    ECommand_DeriveKey = 0x1C,
    ECommand_GetDeviceRevision = 0x30,
    ECommand_GenerateDigest = 0x15,
    ECommand_Hmac = 0x11,
    ECommand_CheckMac = 0x28,
    ECommand_Lock = 0x17,
    ECommand_Mac = 0x08,
    ECommand_Nonce = 0x16,
    ECommand_Pause = 0x01,
    ECommand_Random = 0x1B,
    ECommand_Read = 0x02,
    ECommand_Sha = 0x47,
    ECommand_UpdateExtra = 0x20,
    ECommand_Write = 0x12
} ECommand_t;
