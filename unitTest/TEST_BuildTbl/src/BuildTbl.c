#include "BuildTbl.h"
#include <stddef.h>
#include <string.h>

/* static globals (copied) */
uint8_t Crc8Tbl_u8[256u];
uint8_t *get_Crc8Tbl_u8_ptr(void) {
  return Crc8Tbl_u8;
}
size_t get_Crc8Tbl_u8_size(void) {
  return (size_t)256;
}
void set_Crc8Tbl_u8(const uint8_t *src, size_t n) {
  size_t m = (n < (size_t)256) ? n : (size_t)256;
  memcpy(Crc8Tbl_u8, src, m * sizeof(uint8_t));
}

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
