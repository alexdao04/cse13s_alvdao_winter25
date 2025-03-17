#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h" 

void main_testing(void) {
    database *dbase = database_table(100);
    // initialize the database table
    
    if (dbase == NULL) {
        printf("Failed: database_table is empty\n");
        // if the database table is empty (NULL)
        // we return an error message
        return;
    }

    // first we test the add function

    int result = add(dbase, "John Doe", "johndoe@gmail.com", "Pizza", 2);
    // we add a customer to the database

    if(result == 1) {
        printf("Pass: Customer added successfully\n");
        // if the customer was added successfully
        // we print a success message
    } else {
        printf("Failed: Customer not added\n");
        printf("Result: %d\n", result);
        // if the customer was not added
        // we print an error message
    }

    // now we test the lookup function

    result = lookup(dbase, "johndoe@gmail.com");
    // we look up the customer in the database

    if(result == 1) {
        printf("Pass: Customer found\n");
        printf("Customer name: %s\n", dbase->database_storage[0].name);
        // if the customer was found
        // we print a success message
    } else {
        printf("Failed: Customer not found\n");
        printf("Result: %d\n", result);
        // if the customer was not found
        // we print an error message
    }

    // now we test the delete function

    result = delete(dbase, "johndoe@gmail.com");
    // we delete the customer from the database

    if(result == 1) {
        printf("Pass: Customer deleted\n");
        // if the customer was deleted
        // we print a success message
    } else {
        printf("Failed: Customer not deleted\n");
        printf("Result: %d\n", result);
        // if the customer was not deleted
        // we print an error message
    }

    // now we test the list function

    result = list(dbase, "");
    // we list all customers in the database

    if(result == 1) {
        printf("Pass: Customers listed\n");
        // if the customers were listed
        // we print a success message
    } else {
        printf("Failed: Customers not listed\n");
        printf("Result: %d\n", result);
        // if the customers were not listed
        // we print an error message
    }

    // now we test the save function

    result = save(dbase, "customers.txt");
    // we save the database to a file
    
    if(result == 1) {
        printf("Pass: Database saved\n");
        // if the database was saved
        // we print a success message
    } else {
        printf("Failed: Database not saved\n");
        printf("Result: %d\n", result);
        // if the database was not saved
        // we print an error message
    }
}