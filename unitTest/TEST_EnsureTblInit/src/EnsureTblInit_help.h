#ifndef TEST_ENSURETBLINIT_HELP_H
#define TEST_ENSURETBLINIT_HELP_H

#include "EnsureTblInit.h"
#include <stddef.h>
#include <string.h>

/* static globals (copied) */
static bool Crc8TblInitFlg_b;
_Bool get_Crc8TblInitFlg_b(void) {
  return Crc8TblInitFlg_b;
}
void set_Crc8TblInitFlg_b(_Bool val) {
  Crc8TblInitFlg_b = val;
}

#endif /* TEST_ENSURETBLINIT_HELP_H */
