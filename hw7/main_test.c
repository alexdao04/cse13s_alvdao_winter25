#include <customers.tsv>
#include <main.c>
#include <stdio.h>
#include <stdlib.h>

void init_database(char database, char contents, size_t userid)

    for(size_t i = 0; i < userid; i++) {
        // for each element found in userid column
        // add to database
        // then write to file

        malloc(database);
        // allocate memory for database

        malloc(contents);
        // allocate memory for contents

        database = contents;
        // assign contents to database

        write(database, contents);
        // write contents to database
        
    }

// ok lets think about how we could implement tests for each function
// we could start by testing the add function
// we could test the add function by adding a customer to the database
// then we could test the lookup function by looking up the customer we just added
// then we could test the delete function by deleting the customer we just added
// then we could test the list function by listing all customers in the database
// then we could test the save function by saving the database to a file