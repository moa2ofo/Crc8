#include "CalcByte_u8.h"
#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"
#include "unity.h"

void setUp(void) {
}
void tearDown(void) {
}
void test_CalcByte_u8_crc_0x00_dataByte_0x00(void) {
  uint8_t crc = 0x00;
  uint8_t dataByte = 0x00;
  uint8_t expected_index = 0x00;
  uint8_t table_value = 0x42;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x00_dataByte_0xFF(void) {
  uint8_t crc = 0x00;
  uint8_t dataByte = 0xFF;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0x7A;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0xFF_dataByte_0x00(void) {
  uint8_t crc = 0xFF;
  uint8_t dataByte = 0x00;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0x8B;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0xFF_dataByte_0xFF(void) {
  uint8_t crc = 0xFF;
  uint8_t dataByte = 0xFF;
  uint8_t expected_index = 0x00;
  uint8_t table_value = 0x3C;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x01_dataByte_0x01(void) {
  uint8_t crc = 0x01;
  uint8_t dataByte = 0x01;
  uint8_t expected_index = 0x00;
  uint8_t table_value = 0x5D;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0xFE_dataByte_0xFE(void) {
  uint8_t crc = 0xFE;
  uint8_t dataByte = 0xFE;
  uint8_t expected_index = 0x00;
  uint8_t table_value = 0x6E;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x80_dataByte_0x80(void) {
  uint8_t crc = 0x80;
  uint8_t dataByte = 0x80;
  uint8_t expected_index = 0x00;
  uint8_t table_value = 0x9F;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x7F_dataByte_0x7F(void) {
  uint8_t crc = 0x7F;
  uint8_t dataByte = 0x7F;
  uint8_t expected_index = 0x00;
  uint8_t table_value = 0xA1;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0xAA_dataByte_0x55(void) {
  uint8_t crc = 0xAA;
  uint8_t dataByte = 0x55;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0xB2;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x12_dataByte_0x34(void) {
  uint8_t crc = 0x12;
  uint8_t dataByte = 0x34;
  uint8_t expected_index = 0x26;
  uint8_t table_value = 0xC3;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0xFE_dataByte_0x01(void) {
  uint8_t crc = 0xFE;
  uint8_t dataByte = 0x01;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0xD4;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x01_dataByte_0xFE(void) {
  uint8_t crc = 0x01;
  uint8_t dataByte = 0xFE;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0xE5;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x80_dataByte_0x40(void) {
  uint8_t crc = 0x80;
  uint8_t dataByte = 0x40;
  uint8_t expected_index = 0xC0;
  uint8_t table_value = 0xF6;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_golden_vector_crc_0x00_dataByte_0x31(void) {
  uint8_t crc = 0x00;
  uint8_t dataByte = 0x31;
  uint8_t expected_index = 0x31;
  uint8_t table_value = 0x5E;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_golden_vector_crc_0xFF_dataByte_0x31(void) {
  uint8_t crc = 0xFF;
  uint8_t dataByte = 0x31;
  uint8_t expected_index = 0xCE;
  uint8_t table_value = 0x2F;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_all_table_entries_accessible(void) {
  uint8_t dataByte = 0x00;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  for(uint16_t crc = 0x00; crc <= 0xFF; crc++) {
    table_ptr[crc] = (uint8_t)crc;

    result = CalcByte_u8((uint8_t)crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8((uint8_t)crc, result);
  }
}
void test_CalcByte_u8_xor_operation_crc_0x0F_dataByte_0xF0(void) {
  uint8_t crc = 0x0F;
  uint8_t dataByte = 0xF0;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0x11;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
void test_CalcByte_u8_crc_0x55_dataByte_0xAA(void) {
  uint8_t crc = 0x55;
  uint8_t dataByte = 0xAA;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0x22;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  TEST_ASSERT_EQUAL_UINT8(table_value, result);
}
