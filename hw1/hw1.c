#include "hw1.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
  #define M_PI 3.14159265358979323846 // Defined Pi value

  double area = M_PI * (radius * radius); // A = pi * r^2
  return area; // Store area value
}

double area_of_ring(double outer_radius, double inner_radius) {
  double outer_area = area_of_disk(outer_radius);
  double inner_area = area_of_disk(inner_radius);
  return outer_area - inner_area; // Idea is to calculate the outer and inner ring area separately, then subtract the outer value from the inner to get the ring area.
}

int bigger_minus_smaller(int a, int b) {
  if (a > b)  { // If a is greater than b
    return a - b; // Return a - b
  } else {
    return b - a; // Otherwise, return b - a
  }
}

bool value_in_range(int lower_bound, int x, int upper_bound) {
  if (x >= lower_bound && x <= upper_bound) {
    return true; // If x is between the lower and upper bounds, return True
  } else {
    return false; // Otherwise, return False
  }
}

int sum_of_greater_squares(int a, int b, int c) { // reverse pythagorean theorem lol
  if (a <= b && a <= c) {
    return ((b * b) + (c * c)); // If a <= b and a <= c, return b^2 + c^2 (sum of two bigger numbers)
  } 
  else if (b <= a && b <= c) {
    return ((a * a) + (c * c)); // If b <= a and b <= c, return a^2 + c^2 (sum of two bigger numbers, again)
  }
  else; { 
    return ((a * a) + (b * b)); // If c <= a and c <= b, return a^2 + b^2 (sum of two bigger numbers, yet again)
  }
}
