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
void forwardTraversal(struct NodeDLL* head);
void backwardTraversal(struct NodeDLL* tail);
struct NodeDLL* getHead(struct NodeDLL* curr);
struct NodeDLL* getTail(struct NodeDLL* head);
// */

#endif