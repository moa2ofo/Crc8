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

static void BuildTbl(void)
{
    uint16_t l_idx_u16;
    uint8_t l_bitIdx_u8;
    uint8_t l_crc_u8;

    for (l_idx_u16 = 0U; l_idx_u16 < 256U; l_idx_u16++)
    {
        l_crc_u8 = (uint8_t)l_idx_u16;
        for (l_bitIdx_u8 = 0U; l_bitIdx_u8 < 8U; l_bitIdx_u8++)
        {
            if ((l_crc_u8 & 0x80U) != 0U)
            {
                l_crc_u8 = (uint8_t)((l_crc_u8 << 1) ^ CRC8_POLY_U8);
            }
            else
            {
                l_crc_u8 = (uint8_t)(l_crc_u8 << 1);
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
  EnsureTblInit();
  return CalcByte_u8(crc, dataByte);
}

uint8_t Crc8_Calc_u8(const uint8_t *dataPtr, size_t dataLen) {
  uint8_t crc = CRC8_INIT_U8;
  size_t l_byteIdx_u32;

  if (dataPtr == NULL) {
    return CRC8_INIT_U8;
  }

  EnsureTblInit();

  for (l_byteIdx_u32 = 0U; l_byteIdx_u32 < dataLen; l_byteIdx_u32++) {
    crc = CalcByte_u8(crc, dataPtr[l_byteIdx_u32]);
  }

  return crc;
}