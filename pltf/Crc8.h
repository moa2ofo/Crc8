/******************************************************************************/
/* Crc8.h                                                                     */
/******************************************************************************/
#ifndef CRC8_H
#define CRC8_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Crc8_Calc_u8: Calculate CRC-8 over a byte buffer.
 *
 * @details
 * **Goal of the function**
 *
 * Compute the CRC-8 value for an input buffer starting from the configured
 * initial CRC value (`CRC8_INIT_U8`).
 *
 * The processing logic:
 * - Initializes `crc` to `CRC8_INIT_U8`.
 * - If `dataPtr` is `NULL`, returns `CRC8_INIT_U8` immediately.
 * - Ensures the internal CRC-8 lookup table is initialized.
 * - Iterates over `dataPtr[0..dataLen-1]` and updates the CRC for each byte.
 * - Returns the final CRC value.
 *
 * @par Interface summary
 *
 * | Interface          | In | Out | Data type / Signature                      | Param | Data factor | Data offset | Data size | Data range      | Data unit |
 * |--------------------|:--:|:---:|--------------------------------------------|:-----:|------------:|------------:|----------:|-----------------|----------|
 * | dataPtr            | X  |     | const uint8*                               |   X   |      -      |      -      |     -     | valid/NULL      | [-]      |
 * | dataLen            | X  |     | size_t                                     |   X   |      1      |      0      |     1     | [0, SIZE_MAX]   | [byte]   |
 * | CRC8_INIT_U8       | X  |  X  | uint8 (constant / macro)                   |   -   |      -      |      -      |     -     | [0,200]         | [-]      |
 *
 * @par Activity diagram (PlantUML)
 *
 * @startuml
 * start
 * :crc = CRC8_INIT_U8;
 * if (dataPtr == NULL) then (yes)
 *   :return CRC8_INIT_U8;
 *   stop
 * endif
 * :EnsureTblInit();
 * :byteIdx = 0;
 * while (byteIdx < dataLen) is (yes)
 *   :crc = CalcByte_u8(crc, dataPtr[byteIdx]);
 *   :byteIdx++;
 * endwhile (no)
 * :return crc;
 * stop
 * @enduml
 *
 * @param dataPtr
 * Pointer to the input data buffer. If NULL, the function returns `CRC8_INIT_U8`.
 *
 * @param dataLen
 * Number of bytes in the input buffer.
 *
 * @return CRC-8 computed over @p dataPtr[0..dataLen-1], or `CRC8_INIT_U8` if @p dataPtr is NULL.
 */
uint8_t Crc8_Calc_u8(const uint8_t *dataPtr, size_t dataLen);

/**
 * @brief Update an ongoing CRC-8 with one additional data byte.
 *
 * @details
 * **Goal of the function**
 *
 * Update a previously computed CRC-8 value by processing exactly one new byte.
 * This is intended for streaming use cases where the CRC is accumulated across
 * sequential bytes.
 *
 * The processing logic:
 * - Ensures the internal CRC-8 lookup table is initialized.
 * - Computes the updated CRC using the table-driven byte update.
 * - Returns the updated CRC value.
 *
 * @par Interface summary
 *
 * | Interface          | In | Out | Data type / Signature                      | Param | Data factor | Data offset | Data size | Data range | Data unit |
 * |--------------------|:--:|:---:|--------------------------------------------|:-----:|------------:|------------:|----------:|-----------:|----------|
 * | crc                | X  |     | uint8                                      |   X   |      1      |      0      |     1     | [0,255]    | [-]      |
 * | dataByte           | X  |     | uint8                                      |   X   |      1      |      0      |     1     | [0,255]    | [-]      |
 *
 * @par Activity diagram (PlantUML)
 *
 * @startuml
 * start
 * :EnsureTblInit();
 * :crcNew = CalcByte_u8(crc, dataByte);
 * :return crcNew;
 * stop
 * @enduml
 *
 * @param crc
 * Current CRC-8 value to be updated (e.g., previous result or initial value).
 *
 * @param dataByte
 * Next input byte to process.
 *
 * @return Updated CRC-8 value after processing @p dataByte.
 */
uint8_t Crc8_Upd_u8(uint8_t crc, uint8_t dataByte);

#endif /* CRC8_H */
