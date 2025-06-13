/* Lib Doubly Linked List; */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <lvm/dll.h>

/* Node Doubly Linked List; */
// struct NodeDLL {
//     /*\/ dado representativo do nó,
//     ou um indice para a nó da Doubly Linked List;*/
//     int data;

//     /*\/ valor associado ao nó; */
//     int64_t value;

//     struct NodeDLL *next;
//     struct NodeDLL *prev;
// };

/*
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
*/

// Function to create a new node
struct NodeDLL *createNodeDLL(int key, int64_t value) {
    struct NodeDLL *new_node = (struct NodeDLL *)malloc(sizeof(struct NodeDLL));
    new_node->data = key;
    new_node->value = value;

    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to insert a new node at the front of doubly linked list
struct NodeDLL *insertAtFront(struct NodeDLL *head, int key, int64_t value) {

    // Create a new node
    struct NodeDLL *new_node = createNodeDLL(key, value);

    // Make next of new node as head
    new_node->next = head;

    // Change prev of head node to new node
    if (head != NULL) {
        head->prev = new_node;
    }

    // Return the new node as the head of the doubly linked list
    return new_node;
}

// Function to insert a new node at the end of the doubly linked list
struct NodeDLL* insertEnd(struct NodeDLL *head, int key, int64_t value) {
    struct NodeDLL *new_node = createNodeDLL(key, value);

    // If the linked list is empty, set the new node as the head
    if (head == NULL) {
        head = new_node;
    } else {
        struct NodeDLL *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        // Set the next of last node to new node
        curr->next = new_node;
        // Set prev of new node to last node
        new_node->prev = curr;
    }

    return head;
}

void append(struct NodeDLL **head, int key, int64_t value) {
    *head = insertEnd(*head, key, value);
}

// Checks whether key is present in linked list
bool searchKey(struct NodeDLL* head, int key) {

    // Initialize curr with the head of linked list
    struct NodeDLL* curr = head;

    // Iterate over all the nodes
    while (curr != NULL) {

        // If the current node's value is equal to key,
        // return true
        if (curr->data == key)
            return true;

        // Move to the next node
        curr = curr->next;
    }

    // If there is no node with value as key, return false
    return false;
}

// Checks whether key is present in linked list
struct NodeDLL* searchNodeByKey(struct NodeDLL* head, int key) {

    // Initialize curr with the head of linked list
    struct NodeDLL* curr = head;

    // Iterate over all the nodes
    while (curr != NULL) {

        // If the current node's value is equal to key,
        // return true
        if (curr->data == key)
            return curr;

        // Move to the next node
        curr = curr->next;
    }

    // If there is no node with value as key, return false
    return NULL;
}

// Function to delete a node at a specific 
//position in the doubly linked list
struct NodeDLL * delPos(struct NodeDLL * head, int pos) {

    // If the list is empty
    if (head == NULL)
        return head;

    struct NodeDLL * curr = head;

    // Traverse to the node at the given position
    for (int i = 1; curr && i < pos; ++i) {
        curr = curr -> next;
    }

    // If the position is out of range
    if (curr == NULL)
        return head;

    // Update the previous node's next pointer
    if (curr -> prev)
        curr -> prev -> next = curr -> next;

    // Update the next node's prev pointer
    if (curr -> next)
        curr -> next -> prev = curr -> prev;

    // If the node to be deleted is the head node
       if (head == curr)
               head = curr -> next;

    //    free(curr->data);
    // Deallocate memory for the deleted node
    free(curr);
    return head;
}

/* Function to delete a node in a Doubly Linked List. 
   head_ref --> pointer to head node pointer. 
   del  -->  pointer to node to be deleted. */
void deleteNode(struct NodeDLL** head_ref, struct NodeDLL* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be deleted is NOT the first node */
       if (del->prev != NULL) 
               del->prev->next = del->next; 
  
    //    free(del->data);
    /* Finally, free the memory occupied by del*/
    free(del);
}

// deleteAllNodes(&head)
void deleteAllNodes(struct NodeDLL** head_ref)
{
    struct NodeDLL* ptr = *head_ref;
 
    while (ptr != NULL) {
        struct NodeDLL* next = ptr->next;
        deleteNode(head_ref, ptr);
        ptr = next;
    }
}

// Function to print the doubly linked list
void printList(struct NodeDLL *head) {
    struct NodeDLL *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Function to traverse the doubly linked list 
// in forward direction
void forwardTraversal(struct NodeDLL* head) {
  
    // Start traversal from the head of the list
    struct NodeDLL* curr = head;

    // Continue until the current node is not
    // null (end of list)
    while (curr != NULL) {
      
        // Output data of the current node
        printf("%d -> ", curr->data);
      
        // Move to the next node
        curr = curr->next;
    }

    // Print newline after traversal
    printf("\n");
}

// Function to traverse the doubly linked list 
// in backward direction
void backwardTraversal(struct NodeDLL* tail) {
  
    // Start traversal from the tail of the list
    struct NodeDLL* curr = tail;

    // Continue until the current node is not 
    // null (end of list)
    while (curr != NULL) {
      
        // Output data of the current node
        printf("%d <- ", curr->data);
      
        // Move to the previous node
        curr = curr->prev;
    }

    // Print newline after traversal
    printf("\n");
}

struct NodeDLL* getHead(struct NodeDLL* curr) {

    struct NodeDLL* head = NULL;
    while (curr != NULL) {

        head = curr;

        // Move to the previous node
        curr = curr->prev;
    }

    return head;
}

struct NodeDLL* getTail(struct NodeDLL* head) {

    struct NodeDLL* curr = head;
    struct NodeDLL* tail = NULL;
    while (curr != NULL) {

        tail = curr;

        // Move to the next node
        curr = curr->next;
    }

    return tail;
}

// void printf64(int64_t my_int){
//     printf("%" PRId64 "\n", my_int);
//     printf("%ld", (long)my_int);
//     printf("%lld", (long long)my_int); // C89 didn't define `long long`;
//     printf("%f", (double)my_int);
// }