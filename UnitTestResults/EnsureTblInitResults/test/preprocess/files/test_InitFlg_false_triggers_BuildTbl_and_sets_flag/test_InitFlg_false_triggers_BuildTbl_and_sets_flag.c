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

void test_InitFlg_false_triggers_BuildTbl_and_sets_flag(void)
{
  Crc8TblInitFlg_b =
                    

  BuildTbl_CMockExpect(15);

  EnsureTblInit();

  do { if ((Crc8TblInitFlg_b))
{ } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((19))); } } while (0);
}