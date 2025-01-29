/*
 * All of your code for these five functions goes in here. These are for you to
 * finish. The code for the calculator is separate. Feel free to include more
 * headers or define helper functions if you want, but you can do this homework
 * without doing either.
 */

#include <stdio.h>
#include "hw2.h"

int next_collatz_number(int n) { // basic collatz formula as described in assignment doc
    if(n % 2 == 0) {
      return(n / 2); // if n is even, divide by 2
    } else {
      n = (3 * n + 1); // if n is odd, multiply by 3 and add 1
    }
}

int count_collatz_steps(int n) { // step counter
  int count = 0; // we start at 0
  while(n != 1) { // keep going until n, our number, is equal to 1
    n = next_collatz_number(n); // calls the next_collatz_number function to return the next number
    count++; // increment another step in our count
  }
  return count; // returns the number of steps we took to get to 1
}

int maximum(int *nums, int len) {
  int max = nums[0]; // max represents the first value in the array
    for (int i = 0; i < len; i++) { // we're comparing each value in the array to the max
      if(nums[i] > max) {
        max = nums[i]; // if the value is greater than the max, we set the max to that value
      }
    }
    return max; // return our highest value in the array
}

int sum_positive(int *nums, int len) { // sum of positive numbers in the array
  int sum = 0; // we start at 0
    for (int i = 0; i < len; i++) { // goes through each value of the array iteratively
      if(nums[i] > 0) { // if our value is > 0
        sum += nums[i]; // if our value is positive, we add it to the sum
      }
    }
    return(sum); // returns our sum
}

int count_negative(int *nums, int len) { // count the negative numbers
    int count = 0; // again, start from 0
      for (int i = 0; i < len; i++) { // goes through each value in the array iteratively
        if(nums[i] < 0) { // if our value is < 0
          count++; // we tally another negative value found in the array
        }
      }
        return(count); // returns the count of negative numbers
}
