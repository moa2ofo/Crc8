// CEEDLING NOTICE: This generated file only to be consumed by CMock

#ifndef _CRC8_PRIV_H_ // Ceedling-generated include guard
#define _CRC8_PRIV_H_

uint8_t Crc8Tbl_u8[256u];

_Bool
     Crc8TblInitFlg_b;
 void EnsureTblInit(void);
 uint8_t CalcByte_u8(uint8_t crc, uint8_t dataByte);

#endif // _CRC8_PRIV_H_
