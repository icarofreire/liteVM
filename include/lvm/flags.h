#ifndef FLAGS_H_
#define FLAGS_H_

/* Lib para afetar as flags; */

#include "bitwise.h"

enum RFLAGS {
FLAG_CF = 0,// : CF : Carry Flag
// FLAG_// 1 = 1,// : 1 : Reserved
FLAG_PF = 2,// : PF : Parity Flag
// FLAG_// 0 = 3,// : 0 : Reserved
FLAG_AF = 4,// : AF : Auxiliary Carry Flag
// FLAG_// 0 = 5,// : 0 : Reserved
FLAG_ZF = 6,// : ZF : Zero Flag
FLAG_SF = 7,// : SF : Sign Flag
FLAG_TF = 8,// : TF : Trap Flag
FLAG_IF = 9,// : IF : Interrupt Enable Flag
FLAG_DF = 10,// : DF : Direction Flag
FLAG_OF = 11,// : OF : Overflow Flag
// FLAG_//12-13 : IOPL : I/O Privilege Level
FLAG_NT = 14,// : NT : Nested Task
// FLAG_// 0 = 15,// : 0 : Reserved
FLAG_RF = 16,// : RF : Resume Flag
FLAG_VM = 17,// : VM : Virtual-8086 Mode
FLAG_AC = 18,// : AC : Alignment Check / Access Control
FLAG_VIF = 19,// : VIF : Virtual Interrupt Flag
FLAG_VIP = 20,// : VIP : Virtual Interrupt Pending
FLAG_ID = 21// : ID : ID Flag
// FLAG_// 22-63 : 0 : Reserved
};

int set_flag(const int flags_geral, int flag);
int unset_flag(const int flags_geral, int flag);
int is_flag_set(const int flags_geral, int flag);
int toggle_flag(const int flags_geral, int flag);

#endif