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

void test_Crc8_Upd_u8_sequential_0xAA_then_0x55(void)
{
  uint8_t crc_initial = 0x00;
  uint8_t dataByte1 = 0xAA;
  uint8_t crc_intermediate = 0x47;
  uint8_t dataByte2 = 0x55;
  uint8_t expected_final = 0x79;

  EnsureTblInit_CMockExpect(19);
  CalcByte_u8_CMockExpectAndReturn(20, crc_initial, dataByte1, crc_intermediate);

  uint8_t result1 = Crc8_Upd_u8(crc_initial, dataByte1);
  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((crc_intermediate)), (UNITY_INT)(UNITY_UINT8 )((result1)), (
 ((void *)0)
 ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_UINT8);

  EnsureTblInit_CMockExpect(25);
  CalcByte_u8_CMockExpectAndReturn(26, crc_intermediate, dataByte2, expected_final);

  uint8_t result2 = Crc8_Upd_u8(result1, dataByte2);
  UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((expected_final)), (UNITY_INT)(UNITY_UINT8 )((result2)), (
 ((void *)0)
 ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_UINT8);
}