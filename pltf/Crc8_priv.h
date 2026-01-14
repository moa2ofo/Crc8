#ifndef CRC8_PRIV_H
#define CRC8_PRIV_H

#include <stdbool.h>
#include <stdint.h>

/* Private (cfile-static) variables (Table 6: Global static -> N/A + PascalCasing + _datatype) */
static uint8_t Crc8Tbl_u8[256u];
static bool Crc8TblInitFlg_b;

/* Private (cfile-static) functions (Table 7: Local -> no prefix + PascalCasing) */
static void EnsureTblInit(void);
static void BuildTbl(void);
static uint8_t CalcByte_u8(uint8_t crc, uint8_t dataByte);

#endif /* CRC8_PRIV_H */
