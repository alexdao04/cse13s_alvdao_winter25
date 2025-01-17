# Homework 1: Design Document

  * author: Alexander Dao
  * date: January 2025

## introduction

## Functions:
area_of_disk:
Define M_PI as 3.14159... and then calculate disk area. Disk area is calculated from (A = Pi * R^2) and returns A as double value

area_of_ring:
Returns values of outer and inner ring using previous formula. Outer ring and inner ring values calculated from area_of_disk are subtracted and returned. End result is our actual ring area since we're subtracting a smaller ring from a bigger ring.

bigger_minus_smaller:
Uses a simple conditional statement to determine if one value a is greater than another b. If a is >= b, then we return (a - b), otherwise we return (b - a) using an else condition.

value_in_range:
We have a boolean function where we need a value "x" to fall between two values: "lower_bound" and "upper_bound". We can think of this like setting up an inequality on a number line using >= and <=. When "x" falls between these two values it returns True, and if it doesn't it returns False.

sum_of_greater_squares:
Think of this function like a reverse pythagorean theorem problem. Instead of finding two lesser squares to combine to find our hypotenuse, we find the two greatest squares of given values A, B, and C, and return the sum of these two greatest squares. 

If A <= B and C, then ((B^2)*(C^2))
If B <= A and C, then ((A^2)*(C^2))
If C <= A and B, then ((A^2)*(B^2))

## the caat program

Explanation: When printing characters that are vowels, we have to identify them first so that we can make sure they print twice. Every vowel, capital or lower-case, gets printed twice: aeiouAEIOU. Consonants and spacing do not.

We can achieve this using a while loop with if and else if statements which identify these characters individually, in order that they print twice in the returned output. This  will prevent any duplicating consonant characters or spacing issues.