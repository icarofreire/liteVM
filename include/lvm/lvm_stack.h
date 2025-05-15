#ifndef LVM_STACK_H_
#define LVM_STACK_H_

#define MIN_STACK_SIZE (2 * 1024 * 1024) /* 2 MB */

#include "lvm_memory.h"

/* Initialize our stack by setting the base pointer and stack pointer */

static inline void lvmstack_create(struct lvmmem *mem, size_t size)
{
	mem->registers[0x7].i32_ptr =
		((int32_t *)mem->mem_space) + (size / sizeof(int32_t));
	mem->registers[0x6].i32_ptr = mem->registers[0x7].i32_ptr;
}

static inline void lvmstack_push(struct lvmmem *mem, int *item)
{
	mem->registers[0x6].i32_ptr -= 1;
	*mem->registers[0x6].i32_ptr = *item;
}

static inline void lvmstack_pop(struct lvmmem *mem, int *dest)
{
	*dest = *mem->registers[0x6].i32_ptr;
	mem->registers[0x6].i32_ptr += 1;
}

#endif
