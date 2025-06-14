#ifndef LVM_STACK_H_
#define LVM_STACK_H_

#define MIN_STACK_SIZE (2 * 1024 * 1024) /* 2 MB */

#include "lvm_memory.h"

/* Initialize our stack by setting the base pointer and stack pointer */

static inline void lvmstack_create(struct lvmmem *mem, size_t size)
{
	/*\/ base da stack zerada; */
	mem->base_stack = 0;
}

static inline void lvmstack_push(struct lvmmem *mem, int *item)
{
	if(mem->base_stack < MAX_STACK_SIZE){
		mem->stack[mem->base_stack] = *item;
		mem->base_stack++;
	}
}

static inline void lvmstack_pop(struct lvmmem *mem, int *dest)
{
	*dest = mem->stack[mem->base_stack];
	mem->stack[mem->base_stack] = 0;
	mem->base_stack--;
}

#endif
