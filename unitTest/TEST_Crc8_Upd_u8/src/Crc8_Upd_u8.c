#include "Crc8_Upd_u8.h"
#include <stddef.h>
#include <string.h>

/* FUNCTION TO TEST */


uint8_t Crc8_Upd_u8(uint8_t crc, uint8_t dataByte) {
  EnsureTblInit();
  return CalcByte_u8(crc, dataByte);
}
