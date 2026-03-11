// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "utExecutionAndResults/utUnderTest/src/EnsureTblInit.h"
#include "utExecutionAndResults/utUnderTest/build/vendor/unity/src/unity.h"
#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_InitFlg_true_does_not_trigger_BuildTbl(void)
{
  Crc8TblInitFlg_b =
                    

  EnsureTblInit();

  do { if ((Crc8TblInitFlg_b))
{ } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((17))); } } while (0);
}