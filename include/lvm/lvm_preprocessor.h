#ifndef LVM_PREPROCESSOR_H_
#define LVM_PREPROCESSOR_H_

#include "lvm_htab.h"

int lvmpreprocess(char **src, int *src_len, struct lvmhtab_ctx *defines);

#endif
