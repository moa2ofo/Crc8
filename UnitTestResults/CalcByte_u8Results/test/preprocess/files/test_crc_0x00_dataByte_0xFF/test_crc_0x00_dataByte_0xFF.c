// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "utExecutionAndResults/utUnderTest/src/CalcByte_u8.h"
#include "utExecutionAndResults/utUnderTest/build/vendor/unity/src/unity.h"
#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_CalcByte_u8_crc_0x00_dataByte_0xFF(void)
{
  uint8_t crc = 0x00;
  uint8_t dataByte = 0xFF;
  uint8_t expected_index = 0xFF;
  uint8_t table_value = 0x7A;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  table_ptr[expected_index] = table_value;

  result = CalcByte_u8(crc, dataByte);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((table_value)), (UNITY_INT)(UNITY_UINT8 )((result)), (
 ((void *)0)
 ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_UINT8);
}