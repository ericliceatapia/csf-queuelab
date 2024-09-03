//=============================================
// PUT YOUR NAME HERE
//=============================================
/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */


//=============================================
// Includes and Defines
//=============================================
#include <stdbool.h>


//=============================================
// Data Structure Declarations
//=============================================
/* Linked list element (You will not need to change this) */
typedef struct node_t {
    int value;
    struct node_t *next;
} Node_t;


/* Queue structure */
typedef struct {
    Node_t *head;  /* Linked list of elements */
  /*
      You will need to add more fields to this structure
      to efficiently implement q_size and q_insert_tail
    */
} Queue_t;


//=============================================
// Function Prototypes
//=============================================
Queue_t *q_new(); // Create empty queue. Return NULL if could not allocate space.
void q_free(Queue_t *q); // Free all storage used by queue. No effect if q is NULL
bool q_insert_head(Queue_t *q, int v); // Attempt to insert element at head of queue. Return true if successful. Return false if q is NULL or could not allocate space.
bool q_insert_tail(Queue_t *q, int v); // Attempt to insert element at tail of queue. Return true if successful. Return false if q is NULL or could not allocate space.
bool q_remove_head(Queue_t *q, int *vp); // Attempt to remove element from head of queue. Return true if successful. Return false if q is NULL or empty.
int q_size(Queue_t *q); // Return number of elements in queue. Return 0 if q is NULL or empty
void q_reverse(Queue_t *q); // Reverse elements in queue. No effect if q is NULL or empty
