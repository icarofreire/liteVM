#ifndef LVM_H_
#define LVM_H_

#include <inttypes.h>
#include <stddef.h>

#include "lvm_file.h"
#include "lvm_preprocessor.h"
#include "lvm_stack.h"

#include "lvm_memory.h"
#include "lvm_program.h"
#include "lvm_tokens.h"
#include "dll.h"

struct lvmctx {
	struct lvmprog *prog;
	struct lvmmem *mem;
	/*\/ estrutura para armazenar dados de operações de 64bits; */
	struct NodeDLL* node64;
};

struct lvmctx *lvmvm_create();
void lvmvm_destroy(struct lvmctx *vm);

int lvmvm_interpret(struct lvmctx *vm, char *filename);
void lvmvm_run(struct lvmctx *vm);

/** \/ ; */
#define cmp_str(x, array, indice) (strcmp(x, array[indice]) == 0)

// static inline void lvmstep(struct lvmctx *vm, int *instr_idx)
// {
// 	/*int*/int64_t **args = vm->prog->args[*instr_idx];
// 	int64_t temp = (int64_t)*instr_idx;

// 	switch (vm->prog->instr[*instr_idx]) {
// /* nop   */	case 0x0:  break;
// /* int   */	case 0x1:  /* unimplemented */ break;
// /* mov   */	case 0x2:  *args[0] = *args[1]; break;
// /* push  */	case 0x3:  lvmstack_push64(vm->mem, args[0]); break;
// /* pop   */	case 0x4:  lvmstack_pop64(vm->mem, args[0]); break;
// /* pushf */	case 0x5:  lvmstack_push64(vm->mem, &vm->mem->FLAGS); break;
// /* popf  */	case 0x6:  lvmstack_pop64(vm->mem, args[0]); break;
// /* inc   */	case 0x7:  ++(*args[0]); break;
// /* dec   */	case 0x8:  --(*args[0]); break;
// /* add   */	case 0x9:  *args[0] += *args[1]; break;
// /* sub   */	case 0xA:  *args[0] -= *args[1]; break;
// /* mul   */	case 0xB:  *args[0] *= *args[1]; break;
// /* div   */	case 0xC:  *args[0] /= *args[1]; break;
// /* mod   */	case 0xD:  vm->mem->remainder = *args[0] % *args[1]; break;
// /* rem   */	case 0xE:  *args[0] = vm->mem->remainder; break;
// /* not   */	case 0xF:  *args[0] = ~(*args[0]); break;
// /* xor   */	case 0x10:  *args[0] ^= *args[1];  break;
// /* or    */	case 0x11: *args[0] |= *args[1];   break;
// /* and   */	case 0x12: *args[0] &= *args[1];   break;
// /* shl   */	case 0x13: *args[0] <<= *args[1];  break;
// /* shr   */	case 0x14: *args[0] >>= *args[1];  break;
// /* cmp   */	case 0x15: vm->mem->FLAGS =
// 				((*args[0] == *args[1]) | (*args[0] > *args[1]) << 1);
// 				break;
// /* call	 */	case 0x17: lvmstack_push64(vm->mem, &temp);
// /* jmp	 */	case 0x16: *instr_idx = *args[0] - 1; break;
// /* ret   */	case 0x18: lvmstack_pop64(vm->mem, &temp);
// 				break;
// /* je    */	case 0x19:
// 				*instr_idx = (vm->mem->FLAGS & 0x1)
// 					? *args[0] - 1 : *instr_idx;
// 				break;
// /* jne   */	case 0x1A:
// 				*instr_idx = (!(vm->mem->FLAGS & 0x1))
// 					? *args[0] - 1 : *instr_idx;
// 				break;
// /* jg    */	case 0x1B:
// 				*instr_idx = (vm->mem->FLAGS & 0x2)
// 					? *args[0] - 1 : *instr_idx;
// 				break;
// /* jge   */	case 0x1C:
// 				*instr_idx = (vm->mem->FLAGS & 0x3)
// 					? *args[0] - 1 : *instr_idx;
// 				break;
// /* jl    */	case 0x1D:
// 				*instr_idx = (!(vm->mem->FLAGS & 0x3))
// 					? *args[0] - 1 : *instr_idx;
// 				break;
// /* jle   */	case 0x1E:
// 				*instr_idx = (!(vm->mem->FLAGS & 0x2))
// 					? *args[0] - 1 : *instr_idx;
// 				break;
// /* prn   */	case 0x1F: printf("%lld\n", (long long)*args[0]);// printf("%ll\n", *args[0]);
// 	};
// }

static inline void lvmstep_str_opcode(struct lvmctx *vm, int *instr_idx)
{
	int **args = vm->prog->args[*instr_idx];
	int indice = vm->prog->instr[*instr_idx];
// printf(">> [%lld]: [%s] [%lld] [%lld]\n", (long long)*instr_idx, lvmopcode_map[indice], (long long)*args[0], (long long)*args[0] );

	struct NodeDLL* nodeValue = searchNodeByKey(vm->node64, 0);
	if(nodeValue){
		int64_t v64 = nodeValue->value;
		printf("%lld\n", (long long)v64);
	}

	if(cmp_str("nop", lvmopcode_map, indice)){  }
	else if (cmp_str("int", lvmopcode_map, indice)){  /* unimplemented */ }
	else if (cmp_str("mov", lvmopcode_map, indice)){
		*args[0] = *args[1];
	}
	else if (cmp_str("push", lvmopcode_map, indice)){
		lvmstack_push(vm->mem, args[0]);
	}
	else if (cmp_str("pop", lvmopcode_map, indice)){
		lvmstack_pop(vm->mem, args[0]);
	}
	else if (cmp_str("pushf", lvmopcode_map, indice)){
		lvmstack_push(vm->mem, &vm->mem->FLAGS);
	}
	else if (cmp_str("popf", lvmopcode_map, indice)){
		lvmstack_pop(vm->mem, args[0]);
	}
	else if (cmp_str("inc", lvmopcode_map, indice)){
		++(*args[0]);
	}
	else if (cmp_str("dec", lvmopcode_map, indice)){
		--(*args[0]);
	}
	else if (cmp_str("add", lvmopcode_map, indice)){
		*args[0] += *args[1];
	}
	else if (cmp_str("sub", lvmopcode_map, indice)){
		*args[0] -= *args[1];
	}
	else if (cmp_str("mul", lvmopcode_map, indice)){
		*args[0] *= *args[1];
	}
	else if (cmp_str("div", lvmopcode_map, indice)){
		*args[0] /= *args[1];
	}
	else if (cmp_str("mod", lvmopcode_map, indice)){
		vm->mem->remainder = *args[0] % *args[1];
	}
	else if (cmp_str("rem", lvmopcode_map, indice)){
		*args[0] = vm->mem->remainder;
	}
	else if (cmp_str("not", lvmopcode_map, indice)){
		*args[0] = ~(*args[0]);
	}
	else if (cmp_str("xor", lvmopcode_map, indice)){
		*args[0] ^= *args[1];
	}
	else if (cmp_str("or", lvmopcode_map, indice)){
		*args[0] |= *args[1];
	}
	else if (cmp_str("and", lvmopcode_map, indice)){
		*args[0] &= *args[1];
	}
	else if (cmp_str("shl", lvmopcode_map, indice)){
		*args[0] <<= *args[1];
	}
	else if (cmp_str("shr", lvmopcode_map, indice)){
		*args[0] >>= *args[1];
	}
	else if (cmp_str("cmp", lvmopcode_map, indice)){
		vm->mem->FLAGS = ((*args[0] == *args[1]) | (*args[0] > *args[1]) << 1);
	}
	else if (cmp_str("call", lvmopcode_map, indice)){
		lvmstack_push(vm->mem, instr_idx);
	}
	else if(cmp_str("jmp", lvmopcode_map, indice)){
		*instr_idx = *args[0] - 1;
	}
	else if (cmp_str("ret", lvmopcode_map, indice)){
		lvmstack_pop(vm->mem, instr_idx);
	}
	else if (cmp_str("je", lvmopcode_map, indice)){
		*instr_idx = (vm->mem->FLAGS & 0x1) ? *args[0] - 1 : *instr_idx;
	}
	else if (cmp_str("jne", lvmopcode_map, indice)){
		*instr_idx = (!(vm->mem->FLAGS & 0x1)) ? *args[0] - 1 : *instr_idx;
	}
	else if (cmp_str("jg", lvmopcode_map, indice)){
		*instr_idx = (vm->mem->FLAGS & 0x2) ? *args[0] - 1 : *instr_idx;
	}
	else if (cmp_str("jge", lvmopcode_map, indice)){
		*instr_idx = (vm->mem->FLAGS & 0x3) ? *args[0] - 1 : *instr_idx;
	}
	else if (cmp_str("jl", lvmopcode_map, indice)){
		*instr_idx = (!(vm->mem->FLAGS & 0x3)) ? *args[0] - 1 : *instr_idx;
	}
	else if (cmp_str("jle", lvmopcode_map, indice)){
		*instr_idx = (!(vm->mem->FLAGS & 0x2)) ? *args[0] - 1 : *instr_idx;
	}
	else if (cmp_str("prn", lvmopcode_map, indice)){
		printf("%i\n", *args[0]);
	}
	// printf(">> [%lld]: [%s] [%lld] [%lld]\n", (long long)*instr_idx, lvmopcode_map[indice], (long long)*args[0], (long long)*args[0] );
}

#endif
