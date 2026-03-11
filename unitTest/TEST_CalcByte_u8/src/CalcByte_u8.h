#ifndef TEST_CALCBYTE_U8_H
#define TEST_CALCBYTE_U8_H

#include "Crc8.h"
#include "Crc8_priv.h"

/**
 * @brief Update CRC-8 using the lookup table for a single input byte.
 *
 * @details
 * **Goal of the function**
 *
 * Compute the next CRC-8 value from the current CRC and one byte using the
 * precomputed lookup table.
 *
 * The processing logic:
 * - Index = `(uint8_t)(crc ^ dataByte)`
 * - Return `Crc8Tbl_u8[Index]`
 *
 * @par Interface summary
 *
 * | Interface         | In | Out | Data type / Signature                    |
 * Param | Data factor | Data offset | Data size | Data range | Data unit |
 * |-------------------|:--:|:---:|------------------------------------------|:-----:|------------:|------------:|----------:|-----------:|----------|
 * | crc               | X  |     | uint8_t                                    |
 * X   |      1      |      0      |     1     | [0,255]    | [-]      | |
 * dataByte          | X  |     | uint8_t                                    |
 * X   |      1      |      0      |     1     | [0,255]    | [-]      | |
 * Crc8Tbl_u8[]      | X  |     | uint8_t[256]                               |
 * -   |      1      |      0      |    256    | [0,255]    | [-]      |
 *
 * @par Activity diagram (PlantUML)
 *
 * @startuml
 * start
 * :idx = (uint8_t)(crc XOR dataByte);
 * :crcNew = Crc8Tbl_u8[idx];
 * :return crcNew;
 * stop
 * @enduml
 *
 * @param crc
 * Current CRC-8 value.
 *
 * @param dataByte
 * Next input byte to process.
 *
 * @return Updated CRC-8 value after processing @p dataByte.
 *
 * @warning
 * The lookup table must be initialized before calling this function.
 * Typically ensured by calling @ref EnsureTblInit from the public APIs.
 */
uint8_t CalcByte_u8(uint8_t crc, uint8_t dataByte);

uint8_t* get_Crc8Tbl_u8_ptr(void);
size_t get_Crc8Tbl_u8_size(void);
void set_Crc8Tbl_u8(const uint8_t* src, size_t n);

#endif /* TEST_CALCBYTE_U8_H */
