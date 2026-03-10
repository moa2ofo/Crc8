#include "unity.h"
#include <Crc8_Upd_u8.h>
#include "mock_Crc8.h"
#include "mock_Crc8_priv.h"




void setUp(void)
{
}
void tearDown(void)
{
}
void test_Upd_u8_initial_0x00_data_0x00(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0x00, 0x00);

    result = Crc8_Upd_u8(0x00, 0x00);

    expected = 0x00;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_initial_0x00_data_0xFF(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0xFF, 0xD5);

    result = Crc8_Upd_u8(0x00, 0xFF);

    expected = 0xD5;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_initial_0xFF_data_0x00(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xFF, 0x00, 0xBC);

    result = Crc8_Upd_u8(0xFF, 0x00);

    expected = 0xBC;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_initial_0xFF_data_0xFF(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xFF, 0xFF, 0x42);

    result = Crc8_Upd_u8(0xFF, 0xFF);

    expected = 0x42;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_initial_0x00_data_0x01(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0x01, 0x07);

    result = Crc8_Upd_u8(0x00, 0x01);

    expected = 0x07;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_initial_0x01_data_0x00(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x01, 0x00, 0x91);

    result = Crc8_Upd_u8(0x01, 0x00);

    expected = 0x91;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_initial_0xFE_data_0xFF(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xFE, 0xFF, 0x97);

    result = Crc8_Upd_u8(0xFE, 0xFF);

    expected = 0x97;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_initial_0xFF_data_0xFE(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xFF, 0xFE, 0x45);

    result = Crc8_Upd_u8(0xFF, 0xFE);

    expected = 0x45;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_midrange_0x80_data_0x80(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x80, 0x80, 0x1C);

    result = Crc8_Upd_u8(0x80, 0x80);

    expected = 0x1C;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
/**
 * @brief Test: Sequential update scenario - compute CRC for two-byte sequence {0xAB, 0xCD} by chaining two calls, verify final CRC matches independent reference.
 */
void test_Upd_u8_sequential_two_bytes_0xAB_0xCD(void)
{
    uint8_t crc1;
    uint8_t crc2;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0xAB, 0x3E);

    crc1 = Crc8_Upd_u8(0x00, 0xAB);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x3E, 0xCD, 0x82);

    crc2 = Crc8_Upd_u8(crc1, 0xCD);

    expected = 0x82;
    TEST_ASSERT_EQUAL_UINT8(expected, crc2);
}
/**
 * @brief Test: Sequential update scenario - compute CRC for three-byte sequence {0x12, 0x34, 0x56} by chaining three calls, verify final CRC matches independent reference.
 */
void test_Upd_u8_sequential_three_bytes_0x12_0x34_0x56(void)
{
    uint8_t crc1;
    uint8_t crc2;
    uint8_t crc3;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0x12, 0x95);

    crc1 = Crc8_Upd_u8(0x00, 0x12);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x95, 0x34, 0x6A);

    crc2 = Crc8_Upd_u8(crc1, 0x34);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x6A, 0x56, 0xB1);

    crc3 = Crc8_Upd_u8(crc2, 0x56);

    expected = 0xB1;
    TEST_ASSERT_EQUAL_UINT8(expected, crc3);
}
void test_Upd_u8_golden_vector_ASCII_1(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0x31, 0x46);

    result = Crc8_Upd_u8(0x00, 0x31);

    expected = 0x46;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_golden_vector_ASCII_123456789(void)
{
    uint8_t crc;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0x31, 0x46);
    crc = Crc8_Upd_u8(0x00, 0x31);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x46, 0x32, 0x9C);
    crc = Crc8_Upd_u8(crc, 0x32);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x9C, 0x33, 0xDA);
    crc = Crc8_Upd_u8(crc, 0x33);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xDA, 0x34, 0x23);
    crc = Crc8_Upd_u8(crc, 0x34);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x23, 0x35, 0x65);
    crc = Crc8_Upd_u8(crc, 0x35);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x65, 0x36, 0xBF);
    crc = Crc8_Upd_u8(crc, 0x36);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xBF, 0x37, 0xF9);
    crc = Crc8_Upd_u8(crc, 0x37);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xF9, 0x38, 0xE6);
    crc = Crc8_Upd_u8(crc, 0x38);

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xE6, 0x39, 0xF4);
    crc = Crc8_Upd_u8(crc, 0x39);

    expected = 0xF4;
    TEST_ASSERT_EQUAL_UINT8(expected, crc);
}
void test_Upd_u8_table_init_on_first_call(void)
{
    uint8_t result;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x00, 0x42, 0x8E);

    result = Crc8_Upd_u8(0x00, 0x42);

    TEST_ASSERT_EQUAL_UINT8(0x8E, result);
}
void test_Upd_u8_alternating_pattern_0x55_0xAA(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0x55, 0xAA, 0x72);

    result = Crc8_Upd_u8(0x55, 0xAA);

    expected = 0x72;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
void test_Upd_u8_inverse_alternating_0xAA_0x55(void)
{
    uint8_t result;
    uint8_t expected;

    EnsureTblInit_Expect();
    CalcByte_u8_ExpectAndReturn(0xAA, 0x55, 0x27);

    result = Crc8_Upd_u8(0xAA, 0x55);

    expected = 0x27;
    TEST_ASSERT_EQUAL_UINT8(expected, result);
}
