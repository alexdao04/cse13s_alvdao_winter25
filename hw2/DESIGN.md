# Homework 2: Design Document

  * author: Alexander Vinh Dao
  * date: January 2025

## introduction

We've got five different functions to write. The first one finds a "Collatz" value, which according to our assignment's README was:

"half the input number, if that number is even, or (3 times the number) + 1, if that number is odd."

I'm thinking if I write the function iteratively we can just have the program exit as soon as we return a value of 1. I can just write an if condition that checks for that

For the second function we have to understand a core principle of Collatz numbers: repeating the aforementioned function on any positive value will eventually return a value of 1.

For the third function we take an array of ints and see which int value in the array is highest without going past the end of the array.

For the fourth function we're simply taking all the positive values in an array and summing them all up, while ignoring negative or zero values and not forgetting to terminate before the array ends.

For the fifth function we're simply counting how many negative elements there are in the array. We're not summing anything up as far as I know.

## the calculator program

Basically we have a base-10 value (aka a normal, regular number) that we then apply math operators to (aka +, -, *, /).
The final value is stored and returned as a single number with a newline, as stated in the README documentation.

I'm thinking I do a print statement implementation and combine the current running number with the number we read from our given file. The returned value gets printed to make sure we got the right value and then that's it.