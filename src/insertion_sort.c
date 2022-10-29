#include <assert.h>
#include "insertion_sort.h"
#include "linked_list.h"



void sort(linked_list *llPtr)
{
 // Add your sort function here
    assert(!isempty(llPtr));  // Can't sort an empty list

    node_t* cur = llPtr->head; //Variable to keep track of current node
    node_t* where = llPtr->head; //Variable to keep track of where a node needs to be moved
    node_t* move = llPtr->head; //Pointer to the slot that needs to be moved
    node_t** prevPtr = &(llPtr->head); //Variable to save the pointer that points to the observed node.

    while(cur->next != NULL){ // While we're not at the end of the list
        if(cur->next->data < cur->data){ //If next data is less than current, we need to move the next node.
            where = llPtr->head; //Start looking for new position at the beginning
            prevPtr = &(llPtr->head); //prevPtr keeps along with where
            move = cur->next; //The node we need to move, is the next in line

            while(where->next != NULL){ //Progress through the list again, searching for where to place the move node
                if(where->data > move->data){
                    break; //If current "where" data is larger than what we're moving, this is the place
                }
                where = where->next; //If not, then progress
                prevPtr = &((*prevPtr)->next);
            }
            cur->next = cur->next->next; //Update cur to point past its next node (because we're moving this next node)
            *prevPtr = move; //The pointer that pointed to *where before, now points to the moved node
            move->next = where; //Moved node points to the "where" position.
        }
        else{ //If next node is larger than current, move along
            cur = cur->next;
        }
    }
    
    
    
}
