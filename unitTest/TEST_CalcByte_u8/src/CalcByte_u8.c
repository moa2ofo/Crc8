#include "CalcByte_u8.h"
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


uint8_t CalcByte_u8(uint8_t crc, uint8_t dataByte) {
  /* Table-driven update: crc' = table[crc XOR dataByte] */
  return Crc8Tbl_u8[(uint8_t)(crc ^ dataByte)];
}
