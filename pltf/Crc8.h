#ifndef CRC8_H
#define CRC8_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Compute CRC-8 over a buffer (poly 0x07, init 0x00, no refin/refout, xorout 0x00).
 *
 * @param dataPtr Pointer to input buffer.
 * @param dataLen Number of bytes in input buffer.
 * @return CRC-8 value.
 */
uint8_t Crc8_Calc_u8(const uint8_t *dataPtr, size_t dataLen);

/**
 * @brief Update CRC-8 with one byte (same parameters as Crc8_Calc_u8()).
 *
 * @param crc Current CRC value.
 * @param dataByte Next byte to process.
 * @return Updated CRC value.
 */
uint8_t Crc8_Upd_u8(uint8_t crc, uint8_t dataByte);

#endif /* CRC8_H */
