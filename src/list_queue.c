#include "list_queue.h"
#include <assert.h>

void init_queue(queue *q)
{
  q->size = 0; //Set size to 0
  q->front = NULL; //Define front to point to nothing
  q->rear = NULL; //Define rear to point to nothing
}

int empty(queue *q)
{
  return (q->size == 0); //Check if queue size is 0
}

void enqueue(queue *q, int x)
{
  qnode *add = malloc(sizeof(qnode)); //Create a new node somewhere
  add->data = x; //Add data to the new node
  add->next = q->rear; //New node points to previous last node
  q->rear = add; //New node becomes q's last node
  if(q->front == NULL) q->front = q->rear; //If this is the first node, make sure to update q->front as well.
  (q->size)++;
}

int dequeue(queue *q)
{
  int data = q->front->data;
  if(q->front == q->rear){ //If there's only one item left, reset the queue
    free(q->front); 
    q->front = NULL;
    q->rear = NULL;
    (q->size)--;
    return data; //Return the data from the freed up first slot
  }
  qnode* cur = q->rear; //Variable to start at the rear of the queue
  while(cur->next->next != NULL){
    cur = cur->next; //Go to the second-to-last node in queue
  }
  free(q->front);
  q->front = cur; //Make the first-in-line node what was second in line before.
  q->front->next = NULL; //Make sure the new front points to nothing as next
  (q->size)--;
  return data; //Return the data from dequeued item.
}
