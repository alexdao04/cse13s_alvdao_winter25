/*
 * All of your code for these five functions goes in here. These are for you to
 * finish. The code for the calculator is separate. Feel free to include more
 * headers or define helper functions if you want, but you can do this homework
 * without doing either.
 */

#include <stdio.h>
#include "hw2.h"

int next_collatz_number(int n) {
  while(n != 1) {
    if(n % 2) {
      n = (n / 2);
    } else {
      n = (3 * n + 1);
    }
      return n;
    }
}

int count_collatz_steps(int n) {
  int count = 0;
  while(n != 1) {
    if(n % 2) {
      n = (n / 2);
    } else {
      n = (3 * n + 1);
    }
    count++;
  }
  return count;
  }

int maximum(int *nums, int len) {
  int(nums);
    while(len != 0) {
      if(nums[0] > nums[1]) {
        return nums[0];
      } else {
        return nums[1];
      }
    }
}

int sum_positive(int *nums, int len) {
  int sum = 0;
    for (int i = 0; i < len; i++) {
      if(nums[i] > 0) {
        sum += nums[i];
      }
    }
    return(sum);
}

int count_negative(int *nums, int len) {
  int(nums);
  int count = 0;
    for (int i = 0; i < len; i++) {
      if(nums[i] < 0) {
        count++;
      }
    }
    return(count);
}
