#include <lvm/lvm_memory.h>

#include <stdlib.h>
#include <string.h>

#define NUM_REGISTERS 17

struct lvmmem *lvmmem_create(size_t size)
{
	struct lvmmem *m =
		(struct lvmmem *)calloc(1, sizeof(struct lvmmem));

	m->registers = calloc(NUM_REGISTERS, sizeof(union lvmreg_u));

	m->mem_space_size = size;
	m->mem_space = (int *)calloc(size, 1);

	return m;
}

void lvmmem_destroy(struct lvmmem *m)
{
	free(m->mem_space);
	free(m->registers);
	free(m);
}

/*\/ operações com flags; */
void set_flag(struct lvmmem *mem, int flag){
    mem->FLAGS[flag] = 1;
}

void unset_flag(struct lvmmem *mem, int flag){
    mem->FLAGS[flag] = 0;
}

/** In C, zero is interpreted as false, and any non-zero value is interpreted as true. */
int is_flag_set(struct lvmmem *mem, int flag){
    return (mem->FLAGS[flag] == 1) ? (1) : (0);
}