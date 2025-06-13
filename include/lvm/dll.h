#ifndef DLL_H_
#define DLL_H_

/* Lib Doubly Linked List; */

#include <inttypes.h>
#include <stdbool.h>

/* Node Doubly Linked List; */
struct NodeDLL {
    /*\/ dado representativo do nó,
    ou um indice para a nó da Doubly Linked List;*/
    int data;

    /*\/ valor associado ao nó; */
    int64_t value;

    /*\/ array com tamanhos de 64bits para serem armazenados
    resultados de 64bits em eventuais operações, e armazenados
    no próprio nó; */
    int max_values_opr;
    int64_t *values_opr;

    /*
    ;RFLAGS Register; EFLAGS and RFLAGS registers (in modern x86-64);
    Bit(s) : Label : Description
    0 : CF : Carry Flag
    1 : 1 : Reserved
    2 : PF : Parity Flag
    3 : 0 : Reserved
    4 : AF : Auxiliary Carry Flag
    5 : 0 : Reserved
    6 : ZF : Zero Flag
    7 : SF : Sign Flag
    8 : TF : Trap Flag
    9 : IF : Interrupt Enable Flag
    10 : DF : Direction Flag
    11 : OF : Overflow Flag
    12-13 : IOPL : I/O Privilege Level
    14 : NT : Nested Task
    15 : 0 : Reserved
    16 : RF : Resume Flag
    17 : VM : Virtual-8086 Mode
    18 : AC : Alignment Check / Access Control
    19 : VIF : Virtual Interrupt Flag
    20 : VIP : Virtual Interrupt Pending
    21 : ID : ID Flag
    22-63 : 0 : Reserved
    */
    /*\/ FLAGS register; */
    int64_t FLAGS;

    struct NodeDLL *next;
    struct NodeDLL *prev;
};

// /*
struct NodeDLL *createNodeDLL(int key, int64_t value);
struct NodeDLL *insertAtFront(struct NodeDLL *head, int key, int64_t value);
struct NodeDLL* insertEnd(struct NodeDLL *head, int key, int64_t value);
void append(struct NodeDLL **head, int key, int64_t value);
bool searchKey(struct NodeDLL* head, int key);
struct NodeDLL* searchNodeByKey(struct NodeDLL* head, int key);
struct NodeDLL * delPos(struct NodeDLL * head, int pos);
void deleteNode(struct NodeDLL** head_ref, struct NodeDLL* del);
void deleteAllNodes(struct NodeDLL** head_ref);
void printList(struct NodeDLL *head);
void printList64(struct NodeDLL *head);
void forwardTraversal(struct NodeDLL* head);
void backwardTraversal(struct NodeDLL* tail);
struct NodeDLL* getHead(struct NodeDLL* curr);
struct NodeDLL* getTail(struct NodeDLL* head);
// */

#endif