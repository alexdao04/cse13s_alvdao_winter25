#include "midterm.h"

long long *factorial_numbers(size_t n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 6, 24, 120...

  if (n == 0) {
    // when n is 0 (false)

    return NULL;
    // return NULL

  }

  long long *factorial = malloc(n * sizeof(long long)); 
  // allocate our memory for the array

  if (factorial == NULL) {
    // when the array is NULL

    return NULL;
    // return NULL

  }

  factorial[0] = 1;
  // first entry is 1

  for (size_t i = 1; i < n; i++) {
    // iterate through the array

    factorial[i] = factorial[i - 1] * (i + 1);
    // fill in the rest of the array

  }

  return factorial;
    // return the array
    
}
