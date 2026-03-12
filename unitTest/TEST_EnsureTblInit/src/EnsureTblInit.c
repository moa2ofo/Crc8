#include "EnsureTblInit_help.h"

/* FUNCTION TO TEST */


void EnsureTblInit(void) {
  if(Crc8TblInitFlg_b == false) {
    BuildTbl();
    Crc8TblInitFlg_b = true;
  }
}
