#ifndef LVM_MEMORY_H_
#define LVM_MEMORY_H_

#include <stdint.h>
#include <stddef.h>

#define MIN_MEMORY_SIZE (64 * 1024 * 1024) /* 64 MB */

union lvmreg_u {
	int32_t i32;
	int32_t *i32_ptr;

	union {
		int16_t h;
		int16_t l;
	} i16;

};

struct lvmmem {
	/*
	 *	Similar to x86 FLAGS register
	 *
	 *	0x1	EQUAL
	 *	0x2	GREATER
	 *
	 */

	int FLAGS;
	int remainder;

	void *mem_space;
	int mem_space_size;

	union lvmreg_u *registers;
};

struct lvmmem *lvmmem_create(size_t size);
void lvmmem_destroy(struct lvmmem *mem);

#endif
