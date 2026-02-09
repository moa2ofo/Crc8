#include "Crc8.h"
#include "Crc8_priv.h"

#define CRC8_POLY_U8 (0x07u)
#define CRC8_INIT_U8 (0x00u)

static void EnsureTblInit(void) {
  if (Crc8TblInitFlg_b == false) {
    BuildTbl();
    Crc8TblInitFlg_b = true;
  }
}

static void BuildTbl(void) {
  for (uint16_t l_idx_u16 = 0U; l_idx_u16 < 256U; l_idx_u16++) {
    uint8_t l_crc_u8 = (uint8_t)l_idx_u16;
    for (uint8_t l_bitIdx_u8 = 0U; l_bitIdx_u8 < 8U; l_bitIdx_u8++) {
      if ((l_crc_u8 & 0x80U) != 0U) {
        l_crc_u8 = (uint8_t)((l_crc_u8 << 1U) ^ CRC8_POLY_U8);
      } else {
        l_crc_u8 = (uint8_t)(l_crc_u8 << 1U);
      }
    }
    Crc8Tbl_u8[l_idx_u16] = l_crc_u8;
  }
}
static uint8_t CalcByte_u8(uint8_t crc, uint8_t dataByte) {
  /* Table-driven update: crc' = table[crc XOR dataByte] */
  return Crc8Tbl_u8[(uint8_t)(crc ^ dataByte)];
}

uint8_t Crc8_Upd_u8(uint8_t crc, uint8_t dataByte) {
  /* Ensure the internal CRC-8 lookup table is initialized */
  EnsureTblInit();

  /* Compute the updated CRC using the table-driven byte update */
  const uint8_t crcNew = CalcByte_u8(crc, dataByte);

  /* Return the updated CRC value */
  return crcNew;
}
uint8_t Crc8_Calc_u8(const uint8_t *dataPtr, size_t dataLen) {
  /* Current CRC value during calculation */
  uint8_t crc = CRC8_INIT_U8;

  /**
   * @brief Index for iterating over input data buffer
   */
  size_t l_byteIdx;

  if (dataPtr == NULL) {
    /* Return initial CRC value if input pointer is NULL */
    return CRC8_INIT_U8;
  }

  /* Ensure the CRC-8 lookup table is initialized before calculation */
  EnsureTblInit();

  /* Iterate over each byte in the input buffer and update CRC value */
  for (l_byteIdx = 0U; l_byteIdx < dataLen; l_byteIdx++) {
    crc = CalcByte_u8(crc, dataPtr[l_byteIdx]);
  }

  return crc;
}
