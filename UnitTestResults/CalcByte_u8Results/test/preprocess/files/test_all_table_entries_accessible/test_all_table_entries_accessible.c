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

void test_CalcByte_u8_all_table_entries_accessible(void)
{
  uint8_t dataByte = 0x00;
  uint8_t result;
  uint8_t *table_ptr = get_Crc8Tbl_u8_ptr();

  for(uint16_t crc = 0x00; crc <= 0xFF; crc++)
{
    table_ptr[crc] = (uint8_t)crc;

    result = CalcByte_u8((uint8_t)crc, dataByte);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )(((uint8_t)crc)), (UNITY_INT)(UNITY_UINT8 )((result)), (
   ((void *)0)
   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_UINT8);
  }
}