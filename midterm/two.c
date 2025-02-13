#include "midterm.h"

#include <stdio.h>

ll_float *delete_range(ll_float *list, float start, float end) {
  // list is the head of the linked list
  // start is the beginning of the range to delete
  // end is the end of the range to delete
  // we want to return the resulting linked list

  ll_float *previous = NULL;
  // previous is the previous value in the linked list
  // we set it to NULL because we're not using it yet (initializing)

  ll_float *current_value = list;
  // current_value is the current value in the linked list
  // we set it to the head of the linked list
  // which returns as our final resulting linked list
 
  while(current_value != NULL) {
    // while the list is not empty

    if(current_value-> value >= start && current_value -> value <= end) {
      // if the current value is within the range

      if(previous == NULL) {
        // if the previous value is NULL

        list = current_value -> next;
        // set the list to the next value

      } else {
        // if the previous value is not NULL

        previous -> next = current_value -> next;
        // set the next value of the previous value to the next value of the current value

      }

      ll_float *temp_value = current_value;
      // temp_value is the current value

      current_value = current_value -> next;
      // set the current value to the next value

      free(temp_value);
      // free the memory of the current value

    } else {
      // if the current value is not within the range

      previous = current_value;
      // set the previous value to the current value

    }

    return list;
  }
}