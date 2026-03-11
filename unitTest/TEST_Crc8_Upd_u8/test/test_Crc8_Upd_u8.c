#include "Crc8_Upd_u8.h"
#include "unity.h"
#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"




void setUp(void)
{
}
void tearDown(void)
{
}
void test_Crc8_Upd_u8_initial_0x00_data_0x00(void)
{
    uint8_t crc = 0x00;
    uint8_t dataByte = 0x00;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x00);
    expected_result = 0x00;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_initial_0x00_data_0xFF(void)
{
    uint8_t crc = 0x00;
    uint8_t dataByte = 0xFF;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x07);
    expected_result = 0x07;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_initial_0xFF_data_0x00(void)
{
    uint8_t crc = 0xFF;
    uint8_t dataByte = 0x00;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x3A);
    expected_result = 0x3A;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_initial_0xFF_data_0xFF(void)
{
    uint8_t crc = 0xFF;
    uint8_t dataByte = 0xFF;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x3D);
    expected_result = 0x3D;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_midrange_0x80_data_0x80(void)
{
    uint8_t crc = 0x80;
    uint8_t dataByte = 0x80;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0xC1);
    expected_result = 0xC1;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_golden_vector_0x00_0x31(void)
{
    uint8_t crc = 0x00;
    uint8_t dataByte = 0x31;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x5E);
    expected_result = 0x5E;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_sequential_0xAA_then_0x55(void)
{
    uint8_t crc_initial = 0x00;
    uint8_t dataByte1 = 0xAA;
    uint8_t crc_intermediate = 0x47;
    uint8_t dataByte2 = 0x55;
    uint8_t expected_final = 0x79;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc_initial, dataByte1, crc_intermediate);

    uint8_t result1 = Crc8_Upd_u8(crc_initial, dataByte1);
    TEST_ASSERT_EQUAL_UINT8(crc_intermediate, result1);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc_intermediate, dataByte2, expected_final);

    uint8_t result2 = Crc8_Upd_u8(result1, dataByte2);
    TEST_ASSERT_EQUAL_UINT8(expected_final, result2);
}
void test_Crc8_Upd_u8_boundary_0x01_data_0x01(void)
{
    uint8_t crc = 0x01;
    uint8_t dataByte = 0x01;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x0C);
    expected_result = 0x0C;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_boundary_0xFE_data_0xFE(void)
{
    uint8_t crc = 0xFE;
    uint8_t dataByte = 0xFE;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x31);
    expected_result = 0x31;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_crc_0x00_data_0x7F(void)
{
    uint8_t crc = 0x00;
    uint8_t dataByte = 0x7F;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x2F);
    expected_result = 0x2F;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_crc_0x7F_data_0x00(void)
{
    uint8_t crc = 0x7F;
    uint8_t dataByte = 0x00;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x2F);
    expected_result = 0x2F;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
void test_Crc8_Upd_u8_table_init_verification(void)
{
    uint8_t crc = 0x00;
    uint8_t dataByte = 0x42;
    uint8_t expected_result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(crc, dataByte, 0x54);
    expected_result = 0x54;

    uint8_t result = Crc8_Upd_u8(crc, dataByte);

    TEST_ASSERT_EQUAL_UINT8(expected_result, result);
}
