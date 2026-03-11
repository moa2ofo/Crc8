// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "utExecutionAndResults/utUnderTest/src/Crc8_Upd_u8.h"
#include "utExecutionAndResults/utUnderTest/build/vendor/unity/src/unity.h"
#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Crc8_Upd_u8_boundary_0x01_data_0x01(void)
{
  uint8_t crc = 0x01;
  uint8_t dataByte = 0x01;
  uint8_t expected_result;

  EnsureTblInit_CMockExpect(17);
  CalcByte_u8_CMockExpectAndReturn(18, crc, dataByte, 0x0C);
  expected_result = 0x0C;

  uint8_t result = Crc8_Upd_u8(crc, dataByte);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((expected_result)), (UNITY_INT)(UNITY_UINT8 )((result)), (
 ((void *)0)
 ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_UINT8);
}