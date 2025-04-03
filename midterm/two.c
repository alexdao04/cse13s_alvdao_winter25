#include "midterm.h"
#include <stdio.h>

ll_float *delete_range(ll_float *list, float start, float end) {
    // list is a pointer to the head of a linked list of floats
    // start is the start of the range to delete
    // end is the end of the range to delete
    
    // this function deletes all nodes in the linked list
    // with values between start and end (inclusive)
    // the function should return the head of the resulting linked list. 
    // if the head of the linked list is deleted,
    // the function should return the new head of the linked list.

    ll_float *previous = NULL;
    // previous node is NULL to start with

    ll_float *current_value = list;
    // current value is the head of the linked list
    // we're going to iterate through the linked list
    // and eventually return its final value

    while (current_value != NULL) {
    // while the current value is not NULL
    // we're going to iterate through the linked list
    // and delete the nodes that are within the range

        if (current_value -> value >= start && current_value -> value <= end) {
        // if the current value is within the range
        // we're going to delete it

            if (previous == NULL) {
            // if the previous node is NULL

                list = current_value -> next;
                // the new head of the linked list 
                // is the next node after the current value

            } else { 
            // if the previous node is not NULL
                previous->next = current_value -> next;
                // the previous node's next value

            }

            ll_float *temp_value = current_value;
            // temporary value is the current value

            current_value = current_value -> next;
            // the current value is the next value

            free(temp_value);
            // this frees the temporary value 
            // (which is our current value) from memory

        } else {
        // if the current value is not within the range

            previous = current_value;
            // previous value is now the current value

            current_value = current_value -> next;
            // current value is now the next value
        }
    }

    return list; 
    // return our resulting linked list
  }
