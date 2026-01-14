

#ifndef BUILDTBL_H
#define BUILDTBL_H

#include <stdint.h>

/* CRC-8 polynomial */
#define CRC8_POLY_U8  (0x07u)

/* CRC-8 lookup table */
extern uint8_t Crc8Tbl_u8[256u];

/* Function to build the CRC-8 lookup table */
void BuildTbl(void);

#endif