#ifndef LVM_FILE_H_
#define LVM_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *lvmfopen(const char *filename, const char *extension, const char *mode);

/* Copy the contents of a file from file handle "src" to char array "dest" */
int lvmfcopy(char *dest, size_t size, FILE *src);

/* Get the length of a file in bytes (including EOF character) */
int lvmflength(FILE *f);

#endif
