#ifndef LVM_MEMORY_H_
#define LVM_MEMORY_H_

#include <stdint.h>
#include <stddef.h>

#define MIN_MEMORY_SIZE (64 * 1024 * 1024) /* 64 MB */
#define FLAGS_SIZE 64
#define MAX_STACK_SIZE 50

/*\/ EFLAGS, RFLAGS; */
enum RFLAGS {
FLAG_CF = 0,// : CF : Carry Flag
// FLAG_// 1 = 1,// : 1 : Reserved
FLAG_PF = 2,// : PF : Parity Flag
// FLAG_// 0 = 3,// : 0 : Reserved
FLAG_AF = 4,// : AF : Auxiliary Carry Flag
// FLAG_// 0 = 5,// : 0 : Reserved
FLAG_ZF = 6,// : ZF : Zero Flag
FLAG_SF = 7,// : SF : Sign Flag
FLAG_TF = 8,// : TF : Trap Flag
FLAG_IF = 9,// : IF : Interrupt Enable Flag
FLAG_DF = 10,// : DF : Direction Flag
FLAG_OF = 11,// : OF : Overflow Flag
// FLAG_//12-13 : IOPL : I/O Privilege Level
FLAG_NT = 14,// : NT : Nested Task
// FLAG_// 0 = 15,// : 0 : Reserved
FLAG_RF = 16,// : RF : Resume Flag
FLAG_VM = 17,// : VM : Virtual-8086 Mode
FLAG_AC = 18,// : AC : Alignment Check / Access Control
FLAG_VIF = 19,// : VIF : Virtual Interrupt Flag
FLAG_VIP = 20,// : VIP : Virtual Interrupt Pending
FLAG_ID = 21// : ID : ID Flag
// FLAG_// 22-63 : 0 : Reserved
};

union lvmreg_u {
	int32_t i32;
};

struct lvmmem {
	/*
	 *	Similar to x86 FLAGS register
	 *
	 *	0x1	EQUAL
	 *	0x2	GREATER
	 *
	 */

	int FLAGS[FLAGS_SIZE];
	int remainder;

	int base_stack;
	int64_t stack[MAX_STACK_SIZE];

	void *mem_space;
	int mem_space_size;

	union lvmreg_u *registers;
};

struct lvmmem *lvmmem_create(size_t size);
void lvmmem_destroy(struct lvmmem *mem);

/*\/ operações com flags; */
void set_flag(struct lvmmem *mem, int flag);
void unset_flag(struct lvmmem *mem, int flag);
int is_flag_set(struct lvmmem *mem, int flag);

#endif
