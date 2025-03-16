#include "main.c"
#include <stdio.h>
#include <stdlib.h>

void init_database(char **dbase, char *name, char *email, char *food, int userid) {
    // initialize the database
    // we have 10 customers in the database
    // at the moment

    for(int i = 0; i < 10; i++) {
        dbase[i] = malloc(sizeof(char) * 10);
        // allocate memory for each customer in the database

        size_t userid = 10;
        // we have 10 customers in the database
    }
}

int main(void) {
    
    char dbase[10][10];
    char name[10];
    char email[10];
    char food[10];
    // we have 10 customers in the database
    // indexed by 0-9 (10 values)
    // each customer has a name, email, and food

    // ok lets think about how we could implement tests for each function
    // we could start by testing the add function

    if(add(dbase,"") != 0) {
        printf("Test failed: add(dbase, \"\") != 0\n");
        printf("Result is: %d\n", add(dbase, ""));
    } else if(add(dbase, "") == 0) {
        printf("Test passed: add(dbase, \"\") == 0\n");
        printf("Result is: %d\n", add(dbase, ""));
    }

    if(add(dbase, "johndoe@gmail.com", "John Doe", "Sushi") != 0) {
        printf("Test failed: add(dbase, \"johndoe@gmail.com\", \"John Doe\", \"Sushi\") != 0\n");
        printf("Result is: %d\n", add(dbase, "johndoe@gmail.com", "John Doe", "Sushi"));
    } else {
        printf("Test passed: add(dbase, \"johndoe@gmail.com\", \"John Doe\", \"Sushi\") == 0\n");
        printf("Result is: %d\n", add(dbase, "johndoe@gmail.com", "John Doe", "Sushi"));
    }

    // then the lookup function

    if(lookup(dbase, "") != 0) {
        printf("Test failed: lookup(dbase, \"\") != 0\n");
        printf("Result is: %d\n", lookup(dbase, ""));
    } else if(lookup(dbase, "") == 0) {
        printf("Test passed: lookup(dbase, \"\") == 0\n");
        printf("Result is: %d\n", lookup(dbase, ""));
    }

    if(lookup(dbase, "johndoe@gmail.com") != 0) {
        printf("Test failed: lookup(dbase, \"johndoe@gmail.com\") != 0\n");
        printf("Result is: %d\n", lookup(dbase, "johndoe@gmail.com"));
    } else if(lookup(dbase, "johndoe@gmail.com") == 0) {
        printf("Test passed: lookup(dbase, \"johndoe@gmail.com\") == 0\n");
        printf("Result is: %d\n", lookup(dbase, "johndoe@gmail.com"));
    }

    // lets test the delete function

    if(delete(dbase, "") != 0) {
        printf("Test failed: delete(dbase, \"\") != 0\n");
        printf("Result is: %d\n", delete(dbase, ""));
    } else if(delete(dbase, "") == 0) {
        printf("Test passed: delete(dbase, \"\") == 0\n");
        printf("Result is: %d\n", delete(dbase, ""));
    }

    // then we could test the list function by listing all customers in the database

    if(list(dbase, "") != 0) {
        printf("Test failed: list(dbase, \"\") != 0\n");
        printf("Result is: %d\n", list(dbase, ""));
    } else if(list(dbase, "") == 0) {
        printf("Test passed: list(dbase, \"\") == 0\n");
        printf("Result is: %d\n", list(dbase, ""));
    }

    // then we could test the save function by saving the database to a file

    if(save(dbase, "") != 0) {
        printf("Test failed: save(dbase, \"\") != 0\n");
        printf("Result is: %d\n", save(dbase, ""));
    } else if(save(dbase, "") == 0) {
        printf("Test passed: save(dbase, \"\") == 0\n");
        printf("Result is: %d\n", save(dbase, ""));
    }

    return 0;
}

