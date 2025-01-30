#pragma once
#include <stdbool.h>

bool str_suffix(char *haystack, char *needle); // function to check if a string ends with a suffix

char *str_repeat(char *s, int n); // function to repeat a string n times

bool str_is_palindrome(char *s); // function to check if a string is a palindrome

float dot_product(float *vec_a, float *vec_b, int length); // function to calculate the dot product of two vectors

int reduce(int *nums, int length, int (*f)(int, int), int initial); // function to reduce an array of integers

int maximum_with_reduce(int *nums, int length); // function to find the maximum value in an array of integers

int sum_positive_with_reduce(int *nums, int length); // function to find the sum of positive values in an array of integers

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
