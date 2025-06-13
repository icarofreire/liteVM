#ifndef BITWISE_H_
#define BITWISE_H_

/* Lib bitwise; */

/* Artigos de apoio;
https://catonmat.net/low-level-bit-hacks
https://graphics.stanford.edu/~seander/bithacks.html
*/

#include <inttypes.h>
#include <limits.h>


int bit_is_set(int x, int n);
int bit_is_set_dir(int x, int n);
int bit_is_set64(int64_t x, int n);
int set_nth_bit(int x, int n);
int set_nth_bit_dir(int x, int n);
int64_t set_nth_bit64(int64_t x, int n);
int unset_nth_bit(int x, int n);
int unset_nth_bit_dir(int x, int n);
int64_t unset_nth_bit64(int64_t x, int n);
int toggle_nth_bit(int x, int n);
int toggle_nth_bit_dir(int x, int n);
int64_t toggle_nth_bit64(int64_t x, int n);
int bit_length(long long number);
int nbits_int(long long value);

#endif