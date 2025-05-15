#include <stdlib.h>
#include <stdio.h>

#include <lvm/lvm.h>

int main(int argc, char **argv)
{
	struct lvmctx *vm = lvmvm_create();

	if (vm != NULL && lvmvm_interpret(vm, argv[1]) == 0)
		lvmvm_run(vm);

	lvmvm_destroy(vm);

	return 0;
}
