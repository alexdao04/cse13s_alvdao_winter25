#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h" // Include the header file where the functions and types are declared

void main_testing(void) {
    database *dbase = database_table(100);
    // initialize the database table
    
    if (dbase == NULL) {
        printf("Error: database_table is empty\n");
        // if the database table is empty (NULL)
        // we return an error message
        return;

    }

    // first we test the add function

    int result;
    if ((result = add(dbase, "", "", "")) != 0) {
        printf("Test failed: add(dbase, \"\") != 0\n");
        printf("Result is: %d\n", result);
    } else {
        printf("Test passed: add(dbase, \"\") == 0\n");
        printf("Result is: %d\n", result);
    }

    if ((result = add(dbase, "johndoe@gmail.com", "John Doe", "Sushi")) != 0) {
        printf("Test failed: add(dbase, \"johndoe@gmail.com\", \"John Doe\", \"Sushi\") != 0\n");
        printf("Result is: %d\n", result);
    } else {
        printf("Test passed: add(dbase, \"johndoe@gmail.com\", \"John Doe\", \"Sushi\") == 0\n");
        printf("Result is: %d\n", result);
    }

    // then the lookup function
    if ((result = lookup(dbase, "")) != 0) {
        printf("Test failed: lookup(dbase, \"\") != 0\n");
        printf("Result is: %d\n", result);
    } else {
        printf("Test passed: lookup(dbase, \"\") == 0\n");
        printf("Result is: %d\n", result);
    }

    if ((result = lookup(dbase, "johndoe@gmail.com")) != 0) {
        printf("Test failed: lookup(dbase, \"johndoe@gmail.com\") != 0\n");
        printf("Result is: %d\n", result);
    } else {
        printf("Test passed: lookup(dbase, \"johndoe@gmail.com\") == 0\n");
        printf("Result is: %d\n", result);
    }

    // then we test the delete function
    if ((result = delete(dbase, "")) != 0) {
        printf("Test failed: delete(dbase, \"\") != 0\n");
        printf("Result is: %d\n", result);
    } else {
        printf("Test passed: delete(dbase, \"\") == 0\n");
        printf("Result is: %d\n", result);
    }

    // then we could test the list function by listing all customers in the database
    if ((result = list(dbase, "")) != 0) {
        printf("Test failed: list(dbase, \"\") != 0\n");
        printf("Result is: %d\n", result);
    } else {
        printf("Test passed: list(dbase, \"\") == 0\n");
        printf("Result is: %d\n", result);
    }

    // then we could test the save function by saving the database to a file
    if ((result = save(dbase, "dbase.txt")) != 0) {
        printf("Test failed: save(dbase, \"dbase.txt\") != 0\n");
        printf("Result is: %d\n", result);
    } else {
        printf("Test passed: save(dbase, \"dbase.txt\") == 0\n");
        printf("Result is: %d\n", result);
    }
}

// and well... you dont need to test the quit function
