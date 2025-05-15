#include <lvm/lvm.h>

#include <lvm/lvm_lexer.h>
#include <lvm/lvm_parser.h>

struct lvmctx *lvmvm_create()
{
	struct lvmctx *vm =
		(struct lvmctx *)calloc(1, sizeof(struct lvmctx));

	if (!vm)
		return NULL;
	vm->mem = lvmmem_create(MIN_MEMORY_SIZE);
	vm->prog = lvmprog_create();

	if (!vm->mem || !vm->prog) {
		lvmvm_destroy(vm);
		return NULL;
	}

	lvmstack_create(vm->mem, MIN_STACK_SIZE);
	return vm;
}

int lvmvm_interpret(struct lvmctx *vm, char *filename)
{
	FILE *filp = NULL;
	int source_length = 0;

	/* Attempt to open the file.
	 * If the file cannot be opened, try once more.
	 */
	if (filename) {
		for (int i = 0; i < 2; i++) {
			if (!filp)
				filp = lvmfopen(filename, ".vm", "r");
		}
	}

	if (!filp) {
		printf("File was not found, or does not exist. Unable to interpret.\n");
		return 1;
	}

	source_length = lvmflength(filp);
	char *source = calloc(source_length, sizeof(char));

	lvmfcopy(source, source_length, filp);
	fclose(filp);

	int err = lvmpreprocess(&source, &source_length, vm->prog->defines);

	/* The preprocessor encountered a problem. */
	if (err < 0)
		return 1;

	struct lvmlexer_ctx *lexer_ctx = lexer_create();

	lvmlex(lexer_ctx, source, vm->prog->defines);
	free(source);

	if (lvmparse_labels(vm, (const char ***)lexer_ctx->tokens) != 0)
		return 1;
	if (lvmparse_program(vm, (const char ***)lexer_ctx->tokens) != 0)
		return 1;

	lvmlexer_destroy(lexer_ctx);
	return 0;
}

void lvmvm_run(struct lvmctx *vm)
{
	int *instr_idx = &vm->mem->registers[0x8].i32;
	*instr_idx = vm->prog->start;

	for (; vm->prog->instr[*instr_idx] != -0x1; ++(*instr_idx)){
		// lvmstep(vm, instr_idx);
		lvmstep_str_opcode(vm, instr_idx);
	}
}


void lvmvm_destroy(struct lvmctx *vm)
{
	if (vm && vm->mem)
		lvmmem_destroy(vm->mem);
	if (vm && vm->prog)
		lvmprog_destroy(vm->prog);
	if (vm)
		free(vm);
}
