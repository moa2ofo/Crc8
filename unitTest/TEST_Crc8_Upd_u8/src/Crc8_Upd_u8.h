#ifndef TEST_CRC8_UPD_U8_H
#define TEST_CRC8_UPD_U8_H

#include "Crc8.h"
#include "Crc8_priv.h"

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
 * | Interface          | In | Out | Data type / Signature | Param | Data factor
 * | Data offset | Data size | Data range | Data unit |
 * |--------------------|:--:|:---:|--------------------------------------------|:-----:|------------:|------------:|----------:|-----------:|----------|
 * | crc                | X  |     | uint8_t |   X   |      1      |      0 | 1
 * | [0,255]    | [-]      | | dataByte           | X  |     | uint8_t |   X   |
 * 1      |      0      |     1     | [0,255]    | [-]      |
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


#endif /* TEST_CRC8_UPD_U8_H */
