#include "midterm.h"

long long *factorial_numbers(size_t n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 6, 24, 120...
  // factorial is a function that takes a number in an array
  // and returns the factorial of that number in the array

  long long *factorial = malloc(n * sizeof(long long)); 
  // allocate our memory for the array

  if (factorial == NULL) {
  // when the array is NULL

    return NULL;
    // return NULL because theres no elements in the array

  }

  factorial[0] = 1;
  // first entry is 1 (0! = 1)

  for (size_t i = 1; i < n; i++) {
    // iterate through the array

    factorial[i] = factorial[i - 1] * (i);
    // fill in the rest of the array with our next factorial number

  }

  return factorial;
  // return the values of the array

}
