#include "EnsureTblInit.h"
#include <stddef.h>
#include <string.h>

/* static globals (copied) */
bool Crc8TblInitFlg_b;
_Bool get_Crc8TblInitFlg_b(void) {
  return Crc8TblInitFlg_b;
}
void set_Crc8TblInitFlg_b(_Bool val) {
  Crc8TblInitFlg_b = val;
}

/* FUNCTION TO TEST */


void EnsureTblInit(void) {
  if(Crc8TblInitFlg_b == false) {
    BuildTbl();
    Crc8TblInitFlg_b = true;
  }
}
