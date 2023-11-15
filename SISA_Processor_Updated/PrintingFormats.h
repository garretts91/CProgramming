#pragma once

/*******************************************************************************
* Module:       PrintingFormats
* Developer:    Michael Koepp
* Company:      WWU Computer Science Department
* Create Date:
* Description:
*******************************************************************************/

//PRINTING FORMATS
#define SIXTEEN_BIT_BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define EIGHT_BIT_BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define FOUR_BIT_NIBBLE_TO_BINARY_PATTERN "%c%c%c%c"
#define TW0_BITS_TO_BINARY_PATTERN "%c%c"
#define ONE_BIT_TO_BINARY_PATTERN "%c"

#define SIXTEEN_BIT_BYTE_TO_BINARY(byte)  \
    (byte & 0x8000 ? '1' : '0'), \
    (byte & 0x4000 ? '1' : '0'), \
    (byte & 0x2000 ? '1' : '0'), \
    (byte & 0x1000 ? '1' : '0'), \
    (byte & 0x0800 ? '1' : '0'), \
    (byte & 0x0400 ? '1' : '0'), \
    (byte & 0x0200 ? '1' : '0'), \
    (byte & 0x0100 ? '1' : '0'), \
    (byte & 0x0080 ? '1' : '0'), \
    (byte & 0x0040 ? '1' : '0'), \
    (byte & 0x0020 ? '1' : '0'), \
    (byte & 0x0010 ? '1' : '0'), \
    (byte & 0x0008 ? '1' : '0'), \
    (byte & 0x0004 ? '1' : '0'), \
    (byte & 0x0002 ? '1' : '0'), \
    (byte & 0x0001 ? '1' : '0') 

#define EIGHT_BIT_BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#define FOUR_BIT_NIBBLE_TO_BINARY(byte)  \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#define TWO_BITS_TO_BINARY(byte)  \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#define ONE_BIT_TO_BINARY(byte)  \
  (byte & 0x01 ? '1' : '0') 
