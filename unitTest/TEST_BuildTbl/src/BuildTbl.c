#include "BuildTbl.h"

/* CRC-8 lookup table */
uint8_t Crc8Tbl_u8[256u];

/* FUNCTION TO TEST */

void BuildTbl(void)
{
    uint16_t idx;
    uint8_t bitIdx;

    for (idx = 0u; idx < 256u; idx++)
    {
        uint8_t crc = (uint8_t)idx;

        for (bitIdx = 0u; bitIdx < 8u; bitIdx++)
        {
            if ((crc & 0x80u) != 0u)
            {
                crc = (uint8_t)((crc << 1u) ^ CRC8_POLY_U8);
            }
            else
            {
                crc <<= 1u;
            }
        }

        Crc8Tbl_u8[idx] = crc;
    }
}