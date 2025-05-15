#ifndef TDB_H_
#define TDB_H_

#include <lvm/lvm.h>
#include "tdb_breakpoint.h"

void tdb_shell(struct lvmctx *vm);

int tdb_run(struct lvmctx *vm, struct tdb_breakpoint *breakpoints, int num_breakpoints);
void tdb_step(struct lvmctx *vm);

#endif
