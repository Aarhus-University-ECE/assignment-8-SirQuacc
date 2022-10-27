#include <assert.h>
#include "insertion_sort.h"
#include "linked_list.h"



void sort(linked_list *llPtr)
{
 // Add your sort function here
    assert(!isempty(llPtr));

    node_t* cur = llPtr->head; //Variable to keep track of current node
    node_t** prevPtr = &(llPtr->head); //Variable to save the pointer that points to the current node.

    while(cur->next != NULL){ //Run until the end
        if(cur->data > cur->next->data){ //If the next number is smaller than the current, swap the two
            *prevPtr = swap(cur, cur->next); //swap, and reassign the pointer to the current node, to the new node in "current"'s position
        }
        else{
            cur = cur->next; //If the numbers were fine in order, move on.
        }
        prevPtr = &((*prevPtr)->next); //Progress the double pointer variable as well.

        if(cur->next == NULL){ //If at the end of the list, check wether they are sorted.
            cur = llPtr->head; //Check from the beginning
            prevPtr = &(llPtr->head);
            while(cur->next != NULL){
                if(cur->data > cur->next->data){ //If it's NOT sorted, try run outer loop again, from this position.
                    break;
                }
                cur = cur->next; //Otherwise, move on
                prevPtr = &((*prevPtr)->next);
            }
        }
    }
}
