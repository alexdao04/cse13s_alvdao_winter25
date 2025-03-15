#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char *name;
    char *email;
    char *food;

} customer;

typedef struct database {
    int userid;
    char database;
    char contents;
    customer *database_storage; 
    // pointer to storage for database

} database;

database *database_table(int userid, char database) {
    // initialize our database table

    struct database *dbase;
    dbase = malloc(sizeof(database));
    // allocate memory for the database itself

    dbase -> database_storage = malloc(sizeof(customer) * userid);
    // allocate memory for the contents (separately)

    return dbase;
}

int add(char *name, char *email, char *food, int userid) {
// add a customer to the database (basic I/O operations)

    printf("Enter the name of the customer: ");

    scanf("%s", name);

    // allocate memory for name

    printf("Enter the email of the customer: ");

    scanf("%s", email);

    // allocate memory for email

    printf("Enter the customer's favorite food: ");

    scanf("%s", food);

    // allocate memory for phone
    // after this we scan the database for the customer
    // if the customer is not found, we add them to the database


    for(int i = 0; i < userid; i++) {
        if(email != NULL) {

            return 0; 
            // email not found thus customer not found.
            // set to 0 (false)
        }
    
        else {

            return 1;
            // email found thus customer found.
            // set to 1 (true)
        }
    }
}

int lookup(database *dbase, char *name, char *email, char *food, int userid) {
// looks up a specific customer in the database (in this case by email)

    printf("Enter the email of the customer: ");

    scanf("%s", email);

    // after this we scan the database for the customer

    for(int i = 0; i < userid; i++) {
        // for each element found in userid column 
        // since we want to look up a customer
        // we need to search the hash table

        if(strcmp(email, dbase -> database_storage[i].email) == 0) {

            printf("Customer found: %s, %s, %s\n", dbase->database_storage[i].name, 
                dbase->database_storage[i].email, dbase->database_storage[i].food);
            // happens if the email is found
        }

        else {

            printf("Customer not found\n");
            // happens if the email is not found

            return 0;

        }
        



    }
}

int delete(database *dbase, char *name, char *email, char *food, int userid) {
    // delete a customer from the database
    // thoughts; maybe we could start with some i/o operations (from customers.tsv)
    // prompt then search hash table
    // then write to file

    printf("Enter the email of the customer: ");
    scanf("%s", email);

    // this is the part where we scan the database for the customer email
    if(strcmp(email, dbase->database_storage[userid].email) == 0) {

        printf("Customer found: %s, %s, %s\n", dbase->database_storage[userid].name, 
            dbase->database_storage[userid].email, dbase->database_storage[userid].food);
        // happens if the email is found

        printf("Would you like to delete this customer? (y/n)\n");

        char answer;

        scanf("%c", &answer);

        if(answer == 'y') {
            free(dbase -> database_storage[userid].name);
            free(dbase -> database_storage[userid].email);
            free(dbase -> database_storage[userid].food);

            printf("Customer deleted\n");

         } else {
            printf("Invalid: Customer not found\n");
            // happens if the email is not found

            return 0;

            }
        }
    }


int list(database *dbase, char *email, int userid) {
    // list all customers in the database
    // thoughts; maybe we could start with some i/o operations (from customers.tsv)
    // prompt: would you like to list all customers? (y/n)

    printf("Would you like to list all customers? (y/n)\n");
        char answer;
        scanf("%c", &answer);

        if(answer == 'y') {
            for(size_t i = 0; i < userid; i++) {

                printf("Customer %zu: %s, %s, %s\n", i, dbase->database_storage[i].name, 
                    dbase->database_storage[i].email, dbase->database_storage[i].food);
                // for each element found in userid column
                // print the customer information
            }

        if(answer == 'n') {
            printf("Exiting program\n");

            }
        }
    }


int save(database *dbase, char file[], int userid) {

    printf("Do you want to save to customers.tsv?\n");
    char answer;
    scanf("%c", &answer);

    if(answer == 'y') {
        FILE *file = fopen("customers.tsv", "w");
        // open the file for writing

        if(file == NULL) {
            printf("Error opening file\n");
            // if the file cannot be opened

        }
        else {

            for(size_t i = 0; i < userid; i++) {
                fprintf(file, "%s\t%s\t%s", dbase->database_storage[i].name, 
                    dbase->database_storage[i].email, dbase->database_storage[i].food);
                // output gets printed to the file

                printf("Save successful\n");
                // if the file is successfully written to:

                fclose(file);
                // close the file

            }
        }
    }

    if(answer == 'n') {

        printf("Exiting program\n");

    }
}

int quit(database *dbase, int userid) {

    printf("Would you like to exit the program?")
    // to be continued here..

    for (int i = 0; i < userid; i++) {
        // for each element found in userid column

        free(dbase -> database_storage[i].name);
        free(dbase -> database_storage[i].email);
        free(dbase -> database_storage[i].food);

    }

    free(dbase -> database_storage);
    free(dbase);


}
