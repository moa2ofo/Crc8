#include "Crc8.h"
#include "Crc8_priv.h"

#define CRC8_POLY_U8 (0x07u)
#define CRC8_INIT_U8 (0x00u)

static void EnsureTblInit(void) {
  if(Crc8TblInitFlg_b == false) {
    BuildTbl();
    Crc8TblInitFlg_b = true;
  }
}

static void BuildTbl(void) {
  uint16_t idx;
  uint8_t bitIdx;
  for(idx = 0u; idx < 256u; idx++) {
    uint8_t crc = (uint8_t)idx;
    for(bitIdx = 0u; bitIdx < 8u; bitIdx++) {
      if((crc & 0x80u) != 0u) {
        crc = (uint8_t)((crc << 1u) ^ CRC8_POLY_U8);
      } else {
        crc <<= 1u;
      }
    }
    Crc8Tbl_u8[idx] = crc;
  }
}

static uint8_t CalcByte_u8(uint8_t crc, uint8_t dataByte) {
  /* Table-driven update: crc' = table[crc XOR dataByte] */
  return Crc8Tbl_u8[(uint8_t)(crc ^ dataByte)];
}

uint8_t Crc8_Upd_u8(uint8_t crc, uint8_t dataByte) {
  EnsureTblInit();
  return CalcByte_u8(crc, dataByte);
}

uint8_t Crc8_Calc_u8(const uint8_t *dataPtr, size_t dataLen) {
  uint8_t l_crc_u8;
  size_t l_byteIdx_u32;

  l_crc_u8 = CRC8_INIT_U8;

  if(dataPtr == NULL) { return CRC8_INIT_U8; }

  EnsureTblInit();

  for(l_byteIdx_u32 = 0; l_byteIdx_u32 < dataLen; l_byteIdx_u32++) { l_crc_u8 = CalcByte_u8(l_crc_u8, dataPtr[l_byteIdx_u32]); }

  return l_crc_u8;
}