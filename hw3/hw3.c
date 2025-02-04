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
    // if the needle string length is greater than the haystack string length

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

char *str_repeat(char *s, int n) { 
  // returns a string thats the input string "s" repeated "n" times

  int s_length = strlen(s); 
  // length of the input string "s"

  int s_repeat = s_length * n; 
  // repeats the input string "s" "n" times

  char *out = malloc(sizeof(char) * s_repeat); 
  // allocates memory for the output string
  out[0] = '\0';

  return out; 
  // returns the output string

}

bool str_is_palindrome(char *s) { // returns true if the string "s" is a palindrome
  while(*s) { 
    // while the string "s" is not empty
    int h = strlen(s); 
    // length of the string "s"

    for(int i = 0; i < h; i++) { 
      // goes through the string "s" iteratively
      
      if(s[i] != s[h - i - 1]) { 
        // if the first character of the string "s" is not equal to the last character of the string "s"
        
        return false; 
        // we return false
      }
    }

    return true; 
    // otherwise, we return true

  }

  return false; 
  // if the string is empty, return false

}

float dot_product(float *vec_a, float *vec_b, int length) { 
  // returns the dot product of two vectors.
  // our dot product is the sum of the products of the elements in each vector array

  if(length == 0) { 
    // if the length of the vectors is 0

    return 0; 
    // return 0

    } else {
      return vec_a[0] * vec_b[0] + dot_product(vec_a + 1, vec_b + 1, length - 1); 
      // return the sum of the products of the respective elements of the two arrays

  }
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) { 
  // combines all elements of an array into a single value
  // the function applies to the first element 
  // and then applies to the rest like a domino effect

  if(length == 0) { 
    // if the length of the array is 0

    return initial; 
    // return the initial value

    } else {

      return f(nums[0], reduce(nums + 1, length - 1, f, initial)); 
      return 0;
      // return the result of the function f applied to the first element of the array 
      // and the result of the function f applied to the rest of the array

  }
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!

int maximum(int a, int b) { 
  // helper function to find the maximum value

    return (a > b ? a : b); 
    // returns the maximum value

  }

int maximum_with_reduce(int *nums, int length) { 
  // does the same thing as maximum, but calls reduce

    if(length == 0) { 
      // if the length of the array is 0

      return INT_MIN; 
      // return the minimum integer value

    } else {
      return reduce(nums, length, maximum, INT_MIN); 
      // return the maximum value in the array

    }
      return 0; 
      // returns the maximum element in the array

}

int sum_positive(int a, int b) { 
  // helper function to find the sum of all positive elements in an array

  return (a > 0 ? a : 0) + b; 
  // returns the sum of all positive elements in the array

} 

int sum_positive_with_reduce(int *nums, int length) { // does the same thing as sum_positive, but calls reduce
  if(length == 0) { 
    // if the length of the array is 0

    return 0; 
    // return 0

  } else {

    return reduce(nums, length, sum_positive, 0); 
    // return the sum of all positive elements in the array

  }

  return 0; 
  // returns the sum of all positive elements in the array

}
