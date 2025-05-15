#include <lvm/lvm_file.h>
#include <lvm/lvm_program.h>
#include <lvm/lvm_preprocessor.h>
#include <lvm/lvm_lexer.h>
#include <lvm/lvm_parser.h>
#include <lvm/lvm.h>

struct lvmprog *lvmprog_create()
{
	struct lvmprog *p = calloc(1, sizeof(struct lvmprog));

	p->label_htab = lvmhtab_create();
	p->defines = lvmhtab_create();

	return p;
}

void lvmprog_destroy(struct lvmprog *p)
{
	lvmhtab_destroy(p->label_htab);

	if (p->values) {
		for (int i = 0; i < p->num_values; i++)
			free(p->values[i]);
		free(p->values);
	}

	if (p->args) {
		for (int i = 0; p->args[i]; i++) {
			if (p->args[i])
				free(p->args[i]);
		}

		free(p->args);
	}

	if (p->instr)
		free(p->instr);
	free(p);
}
