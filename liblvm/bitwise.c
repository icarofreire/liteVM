#ifndef BITWISE_H_
#define BITWISE_H_

/* Lib bitwise; */

/* Artigos de apoio;
https://catonmat.net/low-level-bit-hacks
https://graphics.stanford.edu/~seander/bithacks.html
*/

#include <inttypes.h>

/*
int bit_is_set(int x, int n);
int bit_is_set64(int64_t x, int n);
int set_nth_bit(int x, int n);
int64_t set_nth_bit64(int64_t x, int n);
int unset_nth_bit(int x, int n);
int64_t unset_nth_bit64(int64_t x, int n);
int toggle_nth_bit(int x, int n);
int64_t toggle_nth_bit64(int64_t x, int n);
*/

// if the n-th bit is set.
/*
1         00000001    (same as 1<<0)
1<<1      00000010
1<<2      00000100
1<<3      00001000
1<<4      00010000
1<<5      00100000
1<<6      01000000
1<<7      10000000
*/
int bit_is_set(int x, int n){
    if (x & (1<<n)) {
        // n-th bit is set
        return 1;
    }
    // n-th bit is not set
    return -1;
}

// if the n-th bit is set.
int bit_is_set64(int64_t x, int n){
    if (x & (1<<n)) {
        // n-th bit is set
        return 1;
    }
    // n-th bit is not set
    return -1;
}

// Set the n-th bit.
int set_nth_bit(int x, int n){
    int y = x | (1<<n);
    return y;
}

// Set the n-th bit.
int64_t set_nth_bit64(int64_t x, int n){
    int64_t y = x | (1<<n);
    return y;
}

// Unset the n-th bit.
/*
~1        11111110  (same as ~(1<<0))
~(1<<1)   11111101
~(1<<2)   11111011
~(1<<3)   11110111
~(1<<4)   11101111
~(1<<5)   11011111
~(1<<6)   10111111
~(1<<7)   01111111
*/
int unset_nth_bit(int x, int n){
    int y = x & ~(1<<n);
    return y;
}

// Unset the n-th bit.
int64_t unset_nth_bit64(int64_t x, int n){
    int64_t y = x & ~(1<<n);
    return y;
}

// Toggle the n-th bit.
int toggle_nth_bit(int x, int n){
    int y = x ^ (1<<n);
    return y;
}

// Toggle the n-th bit.
int64_t toggle_nth_bit64(int64_t x, int n){
    int64_t y = x ^ (1<<n);
    return y;
}

#endif