#ifndef TEST_CALCBYTE_U8_H
#define TEST_CALCBYTE_U8_H

#include "Crc8.h"
#include "Crc8_priv.h"

#include <stddef.h>
#include <string.h>

uint8_t CalcByte_u8(uint8_t crc, uint8_t dataByte);
uint8_t *get_Crc8Tbl_u8_ptr(void);
size_t get_Crc8Tbl_u8_size(void);
void set_Crc8Tbl_u8(const uint8_t *src, size_t n);

#endif /* TEST_CALCBYTE_U8_H */
