#ifndef TEST_ENSURETBLINIT_H
#define TEST_ENSURETBLINIT_H

#include "Crc8.h"
#include "Crc8_priv.h"

/**
 * @brief Ensure the CRC-8 lookup table is initialized.
 *
 * @details
 * **Goal of the function**
 *
 * Guarantee that the lookup table is built exactly once before use.
 *
 * The processing logic:
 * - If `Crc8TblInitFlg_b` is `false`, call @ref BuildTbl.
 * - Set `Crc8TblInitFlg_b` to `true`.
 *
 * @par Interface summary
 *
 * | Interface            | In | Out | Data type / Signature | Param | Data
 * factor | Data offset | Data size | Data range | Data unit |
 * |----------------------|:--:|:---:|------------------------|:-----:|------------:|------------:|----------:|-----------:|----------|
 * | Crc8TblInitFlg_b     | X  |  X  | bool                   |   -   |      1
 * |      0      |     1     | {0,1}      | [-]      | | BuildTbl()           |
 * X  |  X  | void(void)             |   -   |      -      |      -      |     -
 * | -          | [-]      |
 *
 * @par Activity diagram (PlantUML)
 *
 * @startuml
 * start
 * if (Crc8TblInitFlg_b == false) then (yes)
 *   :BuildTbl();
 *   :Crc8TblInitFlg_b = true;
 * endif
 * stop
 * @enduml
 *
 * @return None.
 */
void EnsureTblInit(void);

_Bool get_Crc8TblInitFlg_b(void);
void set_Crc8TblInitFlg_b(_Bool val);

#endif /* TEST_ENSURETBLINIT_H */
