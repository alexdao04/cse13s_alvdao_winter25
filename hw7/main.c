#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char *name;
    char *email;
    char *phone;
} customer;

typedef struct database {
    size_t userid;
    size_t database;
    size_t contents;
    customer *database_contents;
} database;

database *database_table(size_t userid) {
    // initialize the database table

    database *database_table = malloc(sizeof(database));
    // allocate memory for the database

    database *database_contents = malloc(sizeof(database) * userid);
    // allocate memory for the contents

    database_table = database_contents;
    // assign contents to database

    write(database_table, database_contents);
    // write contents to database
    
}


int(add)(char *name, char *email, char *phone); {
// add a customer to the database (basic I/O operations)

    printf("Enter the name of the customer: ");

    scanf("%s", name);

    printf("Enter the email of the customer: ");

    scanf("%s", email);

    printf("Enter the phone number of the customer: ");

    scanf("%ld", phone);
    // after this we take this data and write it to the database

    for(size_t i = 0; i < userid; i++) {

        malloc(customer);

        malloc(database);


    }


    }

int(lookup)(char *name, char *email, char *phone) {
// looks up a specific customer in the database (in this case by email)

    printf("Enter the email of the customer: ");

    scanf("%s", email);

    // after this we scan the database for the customer

    for(email = 0; email < userid; email++) {
        // for each element found in userid column 
        // since we want to look up a customer
        // we need to search the hash table

        if(email != NULL) {
            // if the email is not found
            // then we return 0
            return 0;
        }
        else {
            // if the email is found
            // then we return 1
            return 1;
        }



    }

int(delete)(char *name, char *email, char *phone) {
    // delete a customer from the database
    // thoughts; maybe we could start with some i/o operations (from customers.tsv)
    // prompt then search hash table
    // then write to file

    printf("Enter the email of the customer: ");
    scanf("%s", email);

    // this is the part where we scan the database for the customer email

    }


int(list)(void) {
    // list all customers in the database
    // thoughts; maybe we could start with some i/o operations (from customers.tsv)
    // prompt then search hash table
    // then write to file



}

int(save)(void) {

    for(email = 0; email < userid; email++) {
        // for each element found in userid column

        malloc(database);
        // allocate memory for database

        malloc(contents);
        // allocate memory for contents

        database = contents;
        // assign contents to database

        strdup(database, contents);
        // duplicate contents to database

        write(database, contents);

    }
}

int(quit)(void) {
    
    for(size_t i = 0; i < userid); i++ {

        free(database);
        // free memory for database

        free(contents);
        // free memory for contents

        database = NULL;
        // assign NULL to database

        contents = NULL;
        // assign NULL to contents

        return 0;
        // return nothing since we cleared the entry

        break;

    }
}