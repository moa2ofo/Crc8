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

void test_BuildTbl_idx_128_mid_range_MSB_set(void)
{
  BuildTbl();

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((0x8E)), (UNITY_INT)(UNITY_UINT8 )((Crc8Tbl_u8[128])), (
 ((void *)0)
 ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_UINT8);
}