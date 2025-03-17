#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fyi, this is very inefficient and im aware
// i know i was supposed to use a hash table
// but i skibidi brute forced the living hell out of it with a linear search
// O(N) vs O(1) is a big difference (as shown by the fact this is 400+ lines)
// but it's too late to turn back now, sorry professor! (please dont kill me) - Alex Dao

void clear_fgets(void) {
    // clear the input buffer
    // so we can read the next line of input
    int selection;
    while ((selection = getchar()) != '\n' && selection != EOF);
    // we use getchar to read the input
    // and we use a while loop to clear the input buffer repeatedly
    // for each prompt we make to the user, that way
    // we don't get double prompts
}

typedef struct customer {
    char *name;
    char *email;
    char *food;
} customer;

typedef struct database {
    int userid;
    int contents;
    customer *database_storage; 
    // pointer to storage for database
} database;

// as you can see, i was trying to make a hash table
// and well you can see how that turned out

database *dbase;

database *database_table(int userid) {
    // initialize our database table

    dbase = malloc(sizeof(database));
    // allocate memory for the database table

    if (dbase == NULL) {
        return NULL;
        // if the memory allocation fails
        // return NULL
    }

    dbase->userid = userid;
    // set the userid to the number of customers in the database
    dbase->contents = 0;
    // set the contents to the database table
    dbase->database_storage = malloc(sizeof(customer) * userid);
    // allocate memory for the contents (separately)

    if (dbase->database_storage == NULL) {
        free(dbase);
        return NULL;
        // again, we return a NULL
        // if we don't allocate memory correctly
    }

    return dbase;
}

// probably the most bloated function that doesnt even work
// this is cooked, i apologize in advance
int add(database *dbase, char *name, char *email, char *food) {
    // add a customer to the database (basic I/O operations)

    printf("Enter the email of the customer: \n");
    fgets(email, 100, stdin);
    email[strlen(email) - 1] = '\0';

    printf("Enter the name of the customer: \n");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';

    printf("Enter the customer's favorite food: \n");
    fgets(food, 100, stdin);
    food[strlen(food) - 1] = '\0';

    // allocate memory for the name, email, and favorite food
    // after this we scan the database for the customer
    // if the customer is not found, we add them to the database

    for (int i = 0; i < dbase->contents; i++) {
        // for each element found in userid

        if (dbase->database_storage[i].email != NULL &&
            strcmp(email, dbase->database_storage[i].email) == 0) {
            // if the email is in the database

            printf("Customer already exists\n");
            printf("Customer found: %s, %s, %s\n", dbase->database_storage[i].name, 
                dbase->database_storage[i].email, dbase->database_storage[i].food);
            // we print the customer info

            printf("Would you like to update this customer's information? (y/n)\n");
            // prompt user to update customer info
            // if y then we update, n we exit instead
            
            char answer;
            scanf(" %c", &answer);
            clear_fgets();
            // we scan the answer from the user

            if (answer == 'y') {
                // if the user wants to update the customer info

                free(dbase->database_storage[i].name);
                free(dbase->database_storage[i].email);
                free(dbase->database_storage[i].food);

                dbase->database_storage[i].name = malloc(strlen(name) + 1);
                strcpy(dbase->database_storage[i].name, name);

                dbase->database_storage[i].email = malloc(strlen(email) + 1);
                strcpy(dbase->database_storage[i].email, email);

                dbase->database_storage[i].food = malloc(strlen(food) + 1);
                strcpy(dbase->database_storage[i].food, food);
                // basically, we're allocating memory for each field
                // + 1 byte for a null terminator. marks where to stop indexing

                printf("Customer updated\n");
                return 1;

            } else if (answer == 'n') {
                printf("Exiting...\n");
                return 0;

            }
        }
    }

    printf("Customer does not exist\n");
    printf("Would you like to add this customer? (y/n)\n");

    char answer;
    scanf(" %c", &answer);
    clear_fgets();
    // scan the answer and clear the buffer for the next prompt

    if (answer == 'y') {
        // if the customer is not found
        // we add them to the database

        dbase->database_storage[dbase->contents].name = malloc(strlen(name) + 1);
        strcpy(dbase->database_storage[dbase->contents].name, name);

        dbase->database_storage[dbase->contents].email = malloc(strlen(email) + 1);
        strcpy(dbase->database_storage[dbase->contents].email, email);

        dbase->database_storage[dbase->contents].food = malloc(strlen(food) + 1);
        strcpy(dbase->database_storage[dbase->contents].food, food);
        // basically, we're allocating memory for each field
        // + 1 byte for a null terminator. marks where to stop indexing

        dbase->contents++;
        printf("Customer added\n");
        return 1;
        // we return 1 since the email is there

    } else {
        printf("Invalid: Customer not found\n");
        // happens if the email is not found
    }

    return 0;
    // we return 0 (false)
}

// least bloated function in the program btw
int lookup(database *dbase, char *email) {
    // looks up a specific customer in the database (in this case by email)

    printf("Enter the email of the customer: ");
    scanf("%s", email);

    // after this we scan the database for the customer
    for (int i = 0; i < dbase->contents; i++) {
        if (dbase->database_storage[i].email != NULL && 
            strcmp(email, dbase->database_storage[i].email) == 0) {
            // if the email is in the database
            printf("Customer found: %s, %s, %s\n", dbase->database_storage[i].name, 
                dbase->database_storage[i].email, dbase->database_storage[i].food);
            // we print the customer info
            return 1;
            // we return 1 since the email is there
        }
    }

    printf("Customer not found in the database\n");
    // this happens if the email isn't in our database
    return 0;
    // we return 0 (false)
}

// this has to be like the second longest function besides add (yikes)
int delete(database *dbase, char *email) {
    // delete a customer from the database

    printf("Enter the email of the customer: ");
    scanf("%s", email);
    char answer;
    // again, read the email input

    for (int i = 0; i < dbase->contents; i++) {
        // for each element found in userid column

        if (dbase->database_storage[i].email != NULL && 
            strcmp(email, dbase->database_storage[i].email) == 0) {
            // if the email is in the database

            printf("Customer found: %s, %s, %s\n", dbase->database_storage[i].name, 
                dbase->database_storage[i].email, dbase->database_storage[i].food);
            // we print the customer info 

            printf("Would you like to delete this customer? (y/n)\n");
            // prompt user to delete customer info
            // if y then we delete, n we exit instead
            
            scanf(" %c", &answer);
            // check the answer, y or n?

            if (answer == 'y') {
                free(dbase->database_storage[i].name);
                free(dbase->database_storage[i].email);
                free(dbase->database_storage[i].food);
                // free memory for the following fields

                dbase->database_storage[i].name = NULL;
                dbase->database_storage[i].email = NULL;
                dbase->database_storage[i].food = NULL;
                // set them to NULL after we free them

                printf("Customer deleted\n");
                return 1;
                // self explanatory

            }
        }
    }

    if (answer == 'n') {
        printf("Customer not deleted\n");
        printf("Exiting...\n");
        return 0;
        // if the user inputs n
        // we exit instead

    } else {
        printf("Customer not found\n");
        // if the email is not in the database
        return 0;

    }
}

// this function is also bloated but not as bad as some of the others
int list(database *dbase) {
    // list all customers in the database

    printf("Would you like to list all customers? (y/n)\n");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y') {
        for (int i = 0; i < dbase->contents; i++) {
            if(dbase->database_storage[i].email != NULL &&
                dbase->database_storage[i].name != NULL &&
                dbase->database_storage[i].food != NULL) {
                // if the name, email, and food are not NULL
                // we print the customer information
                printf("Customer %d: %s, %s, %s\n", i, dbase->database_storage[i].name, 
                    dbase->database_storage[i].email, dbase->database_storage[i].food);
            }
        }

    } else if (answer == 'n') {
        printf("Exiting...\n");
    }

    return 0;
    // since the email isn't there
    // it can't be listed
}

// and we do a little bit of saving
int save(database *dbase, const char *filename) {
    // saves database to customers.tsv (in theory)
    printf("Do you want to save to %s?\n", filename);
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y') {
        FILE *file = fopen(filename, "w");
        // open the file for writing (hence the w)

        if (file == NULL) {
            printf("Error opening file\n");
            // if the file cannot be opened
            return 0;

        } else {
            for (int i = 0; i < dbase->contents; i++) {
                fprintf(file, "%s, %s, %s, %d\n", dbase->database_storage[i].name, 
                    dbase->database_storage[i].email, dbase->database_storage[i].food, i);
            }

            fclose(file);
            // close the file
            printf("Save successful\n");
            // if the file is successfully written to:
            return 1;
        }
    } else if (answer == 'n') {
        printf("Exiting...\n");
        return 0;
    }

    return 0;
    // since the email isn't there
    // it can't be saved
}

// this ones self explanatory
int quit(database *dbase) {
    printf("Would you like to exit the program?\n");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y') {
        for (int i = 0; i < dbase->contents; i++) {
            // for each element found in userid column

            if(dbase->database_storage[i].name != NULL) {
                free(dbase->database_storage[i].name);
                dbase->database_storage[i].name = NULL;
            // free our memory allocated for the following fields:
            }

            if(dbase->database_storage[i].email != NULL) {
                free(dbase->database_storage[i].email);
                dbase->database_storage[i].email = NULL;
            }
            // clear the memory allocated from earlier...

            if(dbase->database_storage[i].food != NULL) {
                free(dbase->database_storage[i].food);
                dbase->database_storage[i].food = NULL;
            }
        }

        free(dbase->database_storage);
        // free the memory allocated for the database storage
        free(dbase);
        // free the memory allocated for the database table
        dbase = NULL;
        // set the database table itself to NULL
        printf("Database cleared, exiting...\n");
        // prints a success message to the user
        exit(0); 
        // quit

    } else if (answer == 'n') {
        printf("Return to main menu\n");
        return 1; // false

    }

    return 0;
}

// backbone of the program
int main(void) {
    database *dbase = database_table(100);

    if (dbase == NULL) {
        printf("Error: database_table has nothing in it\n");
        // if the database table is empty (NULL)
        // we return an error message
        return 1;
    }

    char name[100];
    char email[100];
    char food[100];
    // we have up to 100 customers in the database

    while (1) { // while loop, runs our main menu
        printf("What would you like to do? (add, lookup, delete, list, save, quit)\n");
        // prompt user to choose an action
        char selection[6];
        // we have 6 actions to choose from
        scanf("%s", selection);
        // scanf to read the user's selection
        clear_fgets();
        // clears the input buffer (so we can read the next lines)

        if (strcmp(selection, "add") == 0) {
            add(dbase, name, email, food);

        } else if (strcmp(selection, "lookup") == 0) {
            lookup(dbase, email);
       
        } else if (strcmp(selection, "delete") == 0) {
            delete(dbase, email);
          
        } else if (strcmp(selection, "list") == 0) {
            list(dbase);
            
        } else if (strcmp(selection, "save") == 0) {
            save(dbase, "customers.tsv");
            
        } else if (strcmp(selection, "quit") == 0) {
            quit(dbase);
          
        } else {
            printf("Invalid entry!\n");
            // if the user chooses an invalid action
            // print a generic error message
            // and return to the main menu
        }
    }

    return 0;
}
