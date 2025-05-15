#include <stdio.h>
#include "tdb.h"

int main(int argc, char **argv)
{
	struct lvmctx *vm = lvmvm_create();
	if(vm != NULL && lvmvm_interpret(vm, argv[1]) == 0) tdb_shell(vm);

	lvmvm_destroy(vm);

	return 0;
}
