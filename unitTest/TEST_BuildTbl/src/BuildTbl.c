#include "BuildTbl.h"

/* CRC-8 lookup table */
uint8_t Crc8Tbl_u8[256u];

/* FUNCTION TO TEST */


void BuildTbl(void) {
  uint16_t l_idx_u16;
  uint8_t l_bitIdx_u8;
  uint8_t l_crc_u8;

  for(l_idx_u16 = 0U; l_idx_u16 < 256U; l_idx_u16++) {
    l_crc_u8 = (uint8_t)l_idx_u16;
    for(l_bitIdx_u8 = 0U; l_bitIdx_u8 < 8U; l_bitIdx_u8++) {
      if((l_crc_u8 & 0x80U) != 0U) {
        l_crc_u8 = (uint8_t)((l_crc_u8 << 1) ^ CRC8_POLY_U8);
      } else {
        l_crc_u8 = (uint8_t)(l_crc_u8 << 1);
      }
    }
    Crc8Tbl_u8[l_idx_u16] = l_crc_u8;
  }
}
