#include "midterm.h"

#include <stdio.h>

ll_float *delete_range(ll_float *list, float start, float end) {
  // list is the head of the linked list
  // start is the beginning of the range to delete
  // end is the end of the range to delete
  // we want to return the resulting linked list

  list = NULL;
  // we're deleting the range, so we set it to NULL

  start = 0;
  // start is the beginning of the range to delete

  end = 0;
  // end is the end of the range to delete
 
  while(list != NULL) {
    // while the list is not empty

    if(list->value >= start && list->value <= end) {
      // if the value is within both start and end range

      list = list->next;
      // move to the next value

    } else {
      // if the value is not within the range
      list = list->next;
      // move to the next value
    }

      list = list->next;
      // move to the next value

    }

    return list;
    // return the resulting linked list
}