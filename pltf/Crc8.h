/******************************************************************************/
/* Crc8.h                                                                     */
/******************************************************************************/
#ifndef CRC8_H
#define CRC8_H

#include <stddef.h>
#include <stdint.h>

/**
 * @file Crc8.h
 * @brief Public API for CRC-8 calculation (byte-wise update and buffer CRC).
 *
 * @details
 * This header provides the public interface of a CRC-8 implementation that
 * supports:
 * - Incremental CRC update (streaming) via @ref Crc8_Upd_u8
 * - Full-buffer CRC calculation via @ref Crc8_Calc_u8
 *
 * The implementation is table-driven. The internal lookup table is lazily
 * initialized on first use by the underlying module (see private interface in
 * `Crc8_priv.h`).
 *
 * @note
 * - The CRC polynomial and initial value are defined by module configuration
 *   (e.g. `CRC8_POLY_U8`, `CRC8_INIT_U8`) in the corresponding `.c` / config.
 * - `Crc8_Calc_u8(NULL, len)` returns `CRC8_INIT_U8` to avoid invalid access.
 *
 * @par Typical usage
 * **Full-buffer mode**
 * @code
 * uint8_t crc = Crc8_Calc_u8(buf, bufLen);
 * @endcode
 *
 * **Streaming mode**
 * @code
 * uint8_t crc = CRC8_INIT_U8;
 * for (i = 0; i < n; i++)
 * {
 *     crc = Crc8_Upd_u8(crc, streamByte[i]);
 * }
 * @endcode
 *
 * @par Reentrancy / thread-safety
 * The public APIs are reentrant with respect to their parameters, but the module
 * may rely on a shared internal lookup table initialized lazily on first use.
 * If used concurrently from multiple threads/cores, ensure external protection
 * during the first call (table build) or initialize once in a controlled phase.
 */

/**
 * @brief Calculate CRC-8 over a byte buffer.
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
