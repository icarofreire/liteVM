#ifndef LVM_LEXER_H_
#define LVM_LEXER_H_

#define MAX_ARGS 2
#define MAX_TOKENS 4

#include "lvm_htab.h"

struct lvmlexer_ctx {
	char **source_lines;
	char ***tokens;
};

struct lvmlexer_ctx *lexer_create();
void lvmlexer_destroy(struct lvmlexer_ctx *l);

/* Tokenize the character array "source" into lines and tokens */
void lvmlex(struct lvmlexer_ctx *lexer,
	char *source, struct lvmhtab_ctx *defines);

#endif
