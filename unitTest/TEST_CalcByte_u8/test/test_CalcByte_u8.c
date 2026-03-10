#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"
#include "unity.h"
#include <CalcByte_u8.h>

void setUp(void) {
}
void tearDown(void) {
}
void test_CalcByte_crc00_data00(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x00 ^ 0x00);
  result = CalcByte_u8(0x00, 0x00);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crc00_dataFF(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x00 ^ 0xFF);
  result = CalcByte_u8(0x00, 0xFF);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crcFF_data00(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0xFF ^ 0x00);
  result = CalcByte_u8(0xFF, 0x00);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crcFF_dataFF(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0xFF ^ 0xFF);
  result = CalcByte_u8(0xFF, 0xFF);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crc01_data01(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x01 ^ 0x01);
  result = CalcByte_u8(0x01, 0x01);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crcFE_dataFE(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0xFE ^ 0xFE);
  result = CalcByte_u8(0xFE, 0xFE);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crc80_data80(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x80 ^ 0x80);
  result = CalcByte_u8(0x80, 0x80);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crc7F_data7F(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x7F ^ 0x7F);
  result = CalcByte_u8(0x7F, 0x7F);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crcAA_data55(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0xAA ^ 0x55);
  result = CalcByte_u8(0xAA, 0x55);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crc12_data34(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x12 ^ 0x34);
  result = CalcByte_u8(0x12, 0x34);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crcAB_dataCD(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0xAB ^ 0xCD);
  result = CalcByte_u8(0xAB, 0xCD);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crc80_data40(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x80 ^ 0x40);
  result = CalcByte_u8(0x80, 0x40);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crc01_dataFE(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0x01 ^ 0xFE);
  result = CalcByte_u8(0x01, 0xFE);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_crcFE_data01(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_index;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }
  set_Crc8Tbl_u8(test_table, 256);

  expected_index = (uint8_t)(0xFE ^ 0x01);
  result = CalcByte_u8(0xFE, 0x01);

  TEST_ASSERT_EQUAL_UINT8(test_table[expected_index], result);
}
void test_CalcByte_golden_00_00(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_crc;

  test_table[0x00] = 0x00;
  test_table[0x01] = 0x07;
  test_table[0x02] = 0x0E;
  test_table[0x03] = 0x09;
  test_table[0x04] = 0x1C;
  test_table[0x05] = 0x1B;
  test_table[0x06] = 0x12;
  test_table[0x07] = 0x15;
  test_table[0x08] = 0x38;
  test_table[0x09] = 0x3F;
  test_table[0x0A] = 0x36;
  test_table[0x0B] = 0x31;
  test_table[0x0C] = 0x24;
  test_table[0x0D] = 0x23;
  test_table[0x0E] = 0x2A;
  test_table[0x0F] = 0x2D;

  for(uint16_t i = 16; i < 256; i++) {
    test_table[i] = (uint8_t)i;
  }

  set_Crc8Tbl_u8(test_table, 256);

  expected_crc = test_table[0x00];
  result = CalcByte_u8(0x00, 0x00);

  TEST_ASSERT_EQUAL_UINT8(expected_crc, result);
}
void test_CalcByte_golden_FF_FF(void) {
  uint8_t test_table[256];
  uint8_t result;
  uint8_t expected_crc;

  for(uint16_t i = 0; i < 240; i++) {
    test_table[i] = (uint8_t)i;
  }

  test_table[0xF0] = 0xB4;
  test_table[0xF1] = 0xB3;
  test_table[0xF2] = 0xBA;
  test_table[0xF3] = 0xBD;
  test_table[0xF4] = 0xA8;
  test_table[0xF5] = 0xAF;
  test_table[0xF6] = 0xA6;
  test_table[0xF7] = 0xA1;
  test_table[0xF8] = 0x8C;
  test_table[0xF9] = 0x8B;
  test_table[0xFA] = 0x82;
  test_table[0xFB] = 0x85;
  test_table[0xFC] = 0x90;
  test_table[0xFD] = 0x97;
  test_table[0xFE] = 0x9E;
  test_table[0xFF] = 0x99;

  set_Crc8Tbl_u8(test_table, 256);

  expected_crc = test_table[0x00];
  result = CalcByte_u8(0xFF, 0xFF);

  TEST_ASSERT_EQUAL_UINT8(expected_crc, result);
}
void test_CalcByte_all_table_boundaries(void) {
  uint8_t test_table[256];
  uint8_t result;

  for(uint16_t i = 0; i < 256; i++) {
    test_table[i] = (uint8_t)(255 - i);
  }
  set_Crc8Tbl_u8(test_table, 256);

  result = CalcByte_u8(0x00, 0x00);
  TEST_ASSERT_EQUAL_UINT8(test_table[0x00], result);

  result = CalcByte_u8(0x00, 0x01);
  TEST_ASSERT_EQUAL_UINT8(test_table[0x01], result);

  result = CalcByte_u8(0x00, 0x7F);
  TEST_ASSERT_EQUAL_UINT8(test_table[0x7F], result);

  result = CalcByte_u8(0x00, 0x80);
  TEST_ASSERT_EQUAL_UINT8(test_table[0x80], result);

  result = CalcByte_u8(0x00, 0xFE);
  TEST_ASSERT_EQUAL_UINT8(test_table[0xFE], result);

  result = CalcByte_u8(0x00, 0xFF);
  TEST_ASSERT_EQUAL_UINT8(test_table[0xFF], result);
}
