#ifndef LVM_PARSER_H_
#define LVM_PARSER_H_

#include "lvm.h"
#include "lvm_program.h"

int lvmparse_labels(struct lvmctx *vm, const char ***tokens);
int lvmparse_program(struct lvmctx *vm, const char ***tokens);

int *lvmadd_value(struct lvmctx *vm, const int val);
long long lvmparse_value(const char *str);

#endif
