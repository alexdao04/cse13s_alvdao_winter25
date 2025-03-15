#include <customers.tsv>
#include <main.c>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // create a database
    database *db = database_table(1);
    // add a customer to the database
    add(db, "John Doe", "6503903823", "");
}


// ok lets think about how we could implement tests for each function
// we could start by testing the add function
// we could test the add function by adding a customer to the database
// then we could test the lookup function by looking up the customer we just added
// then we could test the delete function by deleting the customer we just added
// then we could test the list function by listing all customers in the database
// then we could test the save function by saving the database to a file