#ifndef TEST_BUILDTBL_H
#define TEST_BUILDTBL_H

#include "Crc8.h"
#include "Crc8_priv.h"

#include <stddef.h>
#include <string.h>

#define CRC8_POLY_U8 (0x07u)

/**
 * @brief Build the CRC-8 lookup table.
 *
 * @details
 * **Goal of the function**
 *
 * Precompute CRC-8 results for all 256 possible byte values, according to the
 * configured polynomial (`CRC8_POLY_U8`), and store them in @ref Crc8Tbl_u8.
 *
 * The processing logic:
 * - For each `idx` in [0..255]:
 *   - Set `crc = (uint8_t)idx`
 *   - Repeat 8 times:
 *     - If MSB of `crc` is set, shift left and XOR with `CRC8_POLY_U8`
 *     - Else shift left
 *   - Store `crc` into `Crc8Tbl_u8[idx]`
 *
 * @par Interface summary
 *
 * | Interface          | In | Out | Data type / Signature           | Param |
 * Data factor | Data offset | Data size | Data range | Data unit |
 * |--------------------|:--:|:---:|---------------------------------|:-----:|------------:|------------:|----------:|-----------:|----------|
 * | Crc8Tbl_u8[idx]    |    |  X  | uint8_t[256]                      |   -   |
 * 1      |      0      |    256    | [0,255]    | [-]      | | CRC8_POLY_U8 | X
 * |     | uint8_t (constant / macro)        |   -   |      -      |      - | -
 * | [0,255]    | [-]      |
 *
 * @par Activity diagram (PlantUML)
 *
 * @startuml
 * start
 * :idx = 0;
 * while (idx < 256) is (yes)
 *   :crc = (uint8_t)idx;
 *   :bitIdx = 0;
 *   while (bitIdx < 8) is (yes)
 *     if ((crc & 0x80) != 0) then (msb=1)
 *       :crc = (crc << 1) XOR CRC8_POLY_U8;
 *     else (msb=0)
 *       :crc = crc << 1;
 *     endif
 *     :bitIdx++;
 *   endwhile (no)
 *   :Crc8Tbl_u8[idx] = crc;
 *   :idx++;
 * endwhile (no)
 * stop
 * @enduml
 *
 * @return None.
 */
void BuildTbl(void);

uint8_t *get_Crc8Tbl_u8_ptr(void);
size_t get_Crc8Tbl_u8_size(void);
void set_Crc8Tbl_u8(const uint8_t *src, size_t n);

#endif /* TEST_BUILDTBL_H */
