#ifndef LVM_PROGRAM_H_
#define LVM_PROGRAM_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lvm_htab.h"
#include "lvm_memory.h"

struct lvmprog {
	int start;

	int num_instr;
	int *instr;
	int ***args;

	int **values;
	int num_values;

	struct lvmhtab_ctx *defines;
	struct lvmhtab_ctx *label_htab;
};

/* Create and initialize an empty program object */
struct lvmprog *lvmprog_create();

void lvmprog_destroy(struct lvmprog *p);

#endif
