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

bool str_suffix(char *haystack, char *needle) {
// returns true if the string "needle" is a suffix of the string "haystack"
// what this means is, we assume the string "needle" is at the end of the string "haystack"
// this is because we assume the length of needle is <= the length of haystack
// "needle" and "haystack" are placeholders for the actual strings we're comparing

  int length_of_haystack = strlen(haystack); 
  // string length of the haystack variable

  int length_of_needle = strlen(needle); 
  // string length of the needle variable

  if(length_of_needle > length_of_haystack) { 
    // if the needle string length is greater than the haystack string

    return false; 
    // we return a false bool
    // why? because the needle string cant be greater than the haystack string 
    // and still be a suffix of it. 
    // we're doing something like index slicing in python, but not exactly.

  }

  return strcmp(haystack + length_of_haystack - length_of_needle, needle) == 0; 
  // this compares our haystack string to our needle string; 
  // is the needle string at the end of the haystack?

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

float dot_product(float *vec_a, float *vec_b, int length) { // returns the dot product of two vectors.
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
