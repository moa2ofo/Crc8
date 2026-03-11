// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "utExecutionAndResults/utUnderTest/src/BuildTbl.h"
#include "utExecutionAndResults/utUnderTest/build/vendor/unity/src/unity.h"
#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_BuildTbl_multiple_calls_idempotent(void)
{
  uint8_t first_call_table[256];
  uint8_t second_call_table[256];

  BuildTbl();
  memcpy(first_call_table, Crc8Tbl_u8, sizeof(Crc8Tbl_u8));

  BuildTbl();
  memcpy(second_call_table, Crc8Tbl_u8, sizeof(Crc8Tbl_u8));

  UnityAssertEqualIntArray(( const void*)((first_call_table)), ( const void*)((second_call_table)), (UNITY_UINT32)((256)), (
 ((void *)0)
 ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);
}