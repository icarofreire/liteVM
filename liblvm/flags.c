// #ifndef FLAGS_H_
// #define FLAGS_H_

/* Lib para afetar as flags; */

#include <lvm/flags.h>


int set_flag(const int flags_geral, int flag){
    return set_nth_bit_dir(flags_geral, flag);
}

int unset_flag(const int flags_geral, int flag){
    return unset_nth_bit_dir(flags_geral, flag);
}

int is_flag_set(const int flags_geral, int flag){
    return bit_is_set_dir(flags_geral, flag);
}

int toggle_flag(const int flags_geral, int flag){
    return toggle_nth_bit_dir(flags_geral, flag);
}

// #endif