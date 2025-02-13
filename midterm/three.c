#include "midterm.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t count_strings_with_property(bool (*property)(char *), char **strings,
                                   size_t len) {
  // property is a function that takes a string and returns a boolean
  // strings is an array of strings
  // len is the length of the array
  // we want to return the number of strings that have the property

  property = NULL;
  // property is a function that takes a string and returns a boolean
  // we set it to NULL because we're not using it yet
  // this is because we're not using the property function yet

  strings = NULL;
  // strings is an array of strings
  // we set it to NULL because we're not using it yet
  // this is because we're not using the strings array yet

  len = 0;
  // len is the length of the array
  // we set it to 0 because we're not using it yet

  return 0;
}
