#include "midterm.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t count_strings_with_property(bool (*property)(char *), char **strings,
                                   size_t len) {
  // property is a function that takes a string and returns a boolean
  // strings is an array of strings
  // len is the length of the array
  // counter counts the number of strings that have the property
  // we want to return the number of strings that have the property

  size_t counter = 0; 
  // count is the number of strings that have the property
  // we increment this value when the property is true

  for (size_t i = 0; i < len; i++) {
    // iterate through our array of strings

    if (property(strings[i])) {
      // if the property is true for the current string

      counter++;
      // increment our counter
    }
  }

  return counter;
  // and then we return our final number of strings w/ the property

}
