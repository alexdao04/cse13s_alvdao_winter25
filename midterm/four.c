#include "midterm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the number of purchases
int get_n_purchases(ShoeCustomer customers) {
    return customers.num_purchases;
}

// Function to get the name of the customer
char* get_name(ShoeCustomer customers) {
    return customers.name;
}

// Function to swap two customers
void swap_customers(ShoeCustomer *a, ShoeCustomer *b) {
    ShoeCustomer temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two customers
int compare_customers(ShoeCustomer a, ShoeCustomer b) {
    int n_purchases_a = get_n_purchases(a);
    int n_purchases_b = get_n_purchases(b);

    if (n_purchases_a != n_purchases_b) {
        return n_purchases_a - n_purchases_b;
    }

    return strcmp(get_name(a), get_name(b));
}

// PROBLEM 3
void bubble_sort_customers(ShoeCustomer *customers, size_t n_customers) {
  // Your code here! Make them sorted by number of purchases, increasing!
  // If two customers have the same number of purchases, they should be sorted
  // by name, in alphabetical order.
  // You can use the swap_customers function to swap two customers.
  // You can use the compare_customers function to compare two customers.
  // You can use the get_n_purchases function to get the number of purchases of a customer.
  // You can use the get_name function to get the name of a customer.

  for(size_t i = 0; i < n_customers; i++) {
  // increments through number of customers

    for(size_t j = 0; j < n_customers - i - 1; j++) {
    // increments through number of purchases a customer has
    // subtracts i - 1 to avoid comparing the same ones
    // we're comparing them to the next customer

      if(compare_customers(customers[j], customers[j + 1]) > 0) {
      // if the comparison of the customers is greater than 0
      // then we swap the customers
      // this is because we want to sort them in ascending order

        swap_customers(&customers[j], &customers[j + 1]);
        // swap the customers

      }
    }
  }
}