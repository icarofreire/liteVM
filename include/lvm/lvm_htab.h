#ifndef LVM_HTAB_H_
#define LVM_HTAB_H_

#define KEY_LENGTH 64
#define HTAB_SIZE 4096

struct lvmhtab_node {
	char *key;
	int value;
	void *valptr;
	struct lvmhtab_node *next;
};

struct lvmhtab_ctx {
	unsigned int num_nodes;
	unsigned int size;
	struct lvmhtab_node **nodes;
};

struct lvmhtab_ctx *lvmhtab_create();
void lvmhtab_destroy(struct lvmhtab_ctx *htab);

int lvmhtab_add(struct lvmhtab_ctx *htab, const char *key, int value);
int lvmhtab_add_ref(struct lvmhtab_ctx *htab,
	const char *key, const void *valptr, int len);
int lvmhtab_find(struct lvmhtab_ctx *htab, const char *key);
char *lvmhtab_find_ref(struct lvmhtab_ctx *htab, const char *key);

#endif
