#include "linked_list.h"

node_t *createNode(int value) //Create new node with a given value, return pointer to the new node.
{
  node_t *nodePtr = malloc(sizeof(node_t));
  nodePtr->data = value;
  nodePtr->next = NULL;
  return nodePtr;
}

linked_list *createLinkedList() //Create an empty linked list, return pointer to it 
{
  linked_list *llPtr = malloc(sizeof(linked_list));
  llPtr->head = NULL;
  return llPtr;
}

void insertFront(node_t *nodePtr, linked_list *llPtr) //Insert new node to the front of the list
{
  nodePtr->next = llPtr->head;
  llPtr->head = nodePtr;
}

node_t *swap(node_t *x, node_t *y) //Assuming x->y, it swaps their position in the queue, and returns pointer to y, which is now before x
{
  x->next = y->next;
  y->next = x;
  return y;
}

bool isempty(linked_list *llPtr) //Returns bool of whether or not list is empty
{
  return llPtr->head == NULL; //Corrected from != to ==
}

void printLL(linked_list *llPtr) //Print the whole list
{
  node_t *n = llPtr->head;
  while (n != NULL)
  {
    printf("| %d ", n->data);
    n = n->next;
  }
  printf("|\n");
}
