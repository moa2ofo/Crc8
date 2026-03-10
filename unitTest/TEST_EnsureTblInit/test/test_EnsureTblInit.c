#include "unity.h"
#include <EnsureTblInit.h>
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
    set_Crc8TblInitFlg_b(false);
    
    BuildTbl_Expect();
    
    EnsureTblInit();
    
    TEST_ASSERT_TRUE(get_Crc8TblInitFlg_b());
}
void test_InitFlg_true_does_not_trigger_BuildTbl(void)
{
    set_Crc8TblInitFlg_b(true);
    
    EnsureTblInit();
    
    TEST_ASSERT_TRUE(get_Crc8TblInitFlg_b());
}
