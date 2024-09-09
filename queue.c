//=============================================
// ERIC LICEA TAPIA
//=============================================

// This program implements a queue supporting both FIFO and LIFO operations.
// It uses a singly-linked list to represent the set of queue elements


//=============================================
// Includes and Defines
//=============================================
#include <stdlib.h>
#include <stdio.h>
#include "harness.h"
#include "queue.h"


//=============================================
// Queue New Function
//
// Create empty queue.
// Return NULL if could not allocate space.
//=============================================
Queue_t *q_new()
{
    Queue_t *q =  malloc(sizeof(Queue_t));

    if(q == NULL) {
	return NULL;
    }

    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
    return q;
}


//=============================================
// Queue Free Function
//
/* Free all storage used by queue */
//=============================================
void q_free(Queue_t *q)
{
    if(q == NULL) {
	return;
    }

    Node_t *current = q->head;

    while(current != NULL) {
	Node_t *next_node = current->next;
	free(current);
	current = next_node;
    }

    /* Free queue structure */
    free(q);
}


//=============================================
// Queue Insert Head Function
//
// Attempt to insert element at head of queue.
// Return true if successful.
// Return false if q is NULL or could not allocate space.
//=============================================
bool q_insert_head(Queue_t *q, int v)
{
    if(q == NULL) {
	return false;
    }

    Node_t *newh = malloc(sizeof(Node_t));

    if(newh == NULL) {
	return false;
    }

    newh->value = v;
    newh->next = q->head;
    q->head = newh;

    if(q->tail == NULL) {
	q->tail = newh;
    }

    q->count++;
    return true;
}


//=============================================
// Queue Insert Tail Function
//
// Attempt to insert element at tail of queue.
// Return true if successful.
// Return false if q is NULL or could not allocate space.
//=============================================
bool q_insert_tail(Queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */

    if(q == NULL) {
	return false;
    }

    Node_t *newt = malloc(sizeof(Node_t));

    if(newt == NULL) {
	return false;
    }

    newt->value = v;
    newt->next = NULL;

    if(q->tail == NULL) {
	q->head = newt;
    }
    else {
	q->tail->next = newt;
    }

    q->tail = newt;

    q->count++;
    return true;
}


//=============================================
// Queue Remove Head Function
//
// Attempt to remove element from head of queue.
// Return true if successful.
// Return false if queue is NULL or empty.
// If vp non-NULL and element removed, store removed value at *vp.
// Any unused storage should be freed
//=============================================
bool q_remove_head(Queue_t *q, int *vp)
{
    if(q == NULL || q->head == NULL || vp == NULL) {
	return false;
    }

    *vp = q->head->value;

    Node_t *remove_head = q->head;
    q->head = remove_head->next;

    free(remove_head);

    q->count--;
    return true;
}


//=============================================
// Queue Size Function
//
// Return number of elements in queue.
// Return 0 if q is NULL or empty
//=============================================
int q_size(Queue_t *q)
{
    if(q == NULL || q->head == NULL) {
	return 0;
    }
    return q->count;
}


//=============================================
// Queue Reverse Function
//
// Reverse elements in queue.
// No effect if q is NULL or empty.
// No effect if q has only one element.
// Your implementation must not allocate or free any elements (e.g., by
// calling q_insert_head or q_remove_head).  Instead, it should modify
// the pointers in the existing data structure.
//=============================================
void q_reverse(Queue_t *q)
{
    if(q == NULL || q->head == NULL || q->count == 1) {
	return;
    }

    Node_t *prev = NULL;
    Node_t *current = q->head;
    Node_t *next = NULL;

    while(current != NULL) {
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
    }

    q->tail = q->head;
    q->head = prev;
}
