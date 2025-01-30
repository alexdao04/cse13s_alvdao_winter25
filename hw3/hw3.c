/*
 * All of your code for hw3 goes in here. Your goal is to finish these
 * functions.
 */

#include "hw3.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool str_suffix(char *haystack, char *needle) { // returns true if the string "needle" is a suffix of the string "haystack"
  UNUSED(haystack);
  UNUSED(needle);
  return false;
}

char *str_repeat(char *s, int n) { // returns a string thats the input string "s" repeated "n" times
  UNUSED(s);
  UNUSED(n);

  char *out = malloc(sizeof(char) * 1); // allocates memory for the output string
  out[0] = '\0';

  return out; // returns the output string
}

bool str_is_palindrome(char *s) { // returns true if the string "s" is a palindrome
  UNUSED(s);
  return false;
}

float dot_product(float *vec_a, float *vec_b, int length) { // returns the dot product of two vectors
  UNUSED(vec_a);
  UNUSED(vec_b);
  UNUSED(length);
  return 0; // sum of the products of the respective elements of the two arrays
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) { // combines all elements of an array into a single value
  UNUSED(nums);
  UNUSED(length);
  UNUSED(f);
  UNUSED(initial);
  return 0; // returns the final value
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!

int maximum_with_reduce(int *nums, int length) { // does the same thing as maximum, but calls reduce
  UNUSED(nums);
  UNUSED(length);
  return 0; // returns the maximum element in the array
}

int sum_positive_with_reduce(int *nums, int length) { // does the same thing as sum_positive, but calls reduce
  UNUSED(nums);
  UNUSED(length);
  return 0; // returns the sum of all positive elements in the array
}
