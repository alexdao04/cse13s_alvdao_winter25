# Homework #7: Customer Database
# Author: Alexander Dao
# Class: CSE 13S, Prof. Rudnick
# Date: 2025-03-10

# Description: 
This program creates a customer database using a dictionary and allows the user to add, update, delete, search, and list customers. Ideally should've been done using a hashtable for O(1) efficiency, but I ended up doing a O(N) implementation with linear search.

# customers.tsv:
Where our customer database is located. Contains customer info such as email address, display name, shoe size, favorite food.

# main.c (nain interaction loop):
Should read customers.tsv and store all the customers in a hash table. Will have the following functions:
- add:
    - Prompts the user for their personal information. Stores this in a hash table. We'll need to use malloc functions to store this info. This can be handled with basic I/O operations (printf(), scanf()).
    - Oh dear. I guess I'm gonna have to explain this all away. I decided to brute force linear search my way through this and use a bunch of printf()'s, scanf()'s and fgets()'s to make this all come together. Using a for loop and a bunch of conditional statements, I did a prompt based process and stored the data contents away based on the user's scanned input. We asked for name, email, and a favorite food, then assigned them a userid in order of how they were added. Then we save them to customers.tsv later with our save function. We just exit to the main menu if the user answers no.
    - Also included an option to update customer info if it already exists when we scan it. Entries are all stored in individual elements of an array (100 entries).
- lookup:
    - Prompt user for email address, find that entry in the hash table. Find the info of that customer and display the information about them.
        - We could do a search based on regex fields; we format our search to recognize any email format regardless of domain (gmail, ucsc.edu, etc.) as well as separately handle the user id portion of the email (e.g. sammy in sammy@ucsc.edu)
        - We didn't use regex. I don't know what on earth I was thinking when I was saying that, but maybe it was because my dad's a linguist and that's something I'm curious about. We prompt the user for an email address and linear search through the database, which is an array with a bunch of individual entries. If it's in there, we print the specific customer info, if not, we give them a generic error message (e.g. "Customer not found!")
- delete:
    - Prompt user for email address, find that entry in the hash table. Deletes user info if found, and throws a generic error message (e.g. "there's no matching email address") if no matches are found.
        - Could be handled similarly to the quit function; only thing is, we don't break the loop afterward and continue on. 
        - Ignore what I said up there. In reality, I did the exact same thing. Prompt for an email, scan the database, if there's data there we print it and ask if we want to delete the customer: if yes, delete, if not, print a generic error message, return to main menu. 

- list:
    - List every user in the database, in order.
        - We'll likely use strdup or strcpy, then print the last saved data in customers.tsv. That file will have all of the data that we're supposed to work with.
        - Program asks using simple input/output: printf(), scanf(). If user answers yes, print whatever we have stored in memory at the moment, if not, exit to the main menu. 
- save:
    - Writes the current state (stored to memory) of the database to customers.tsv
        - Again, we'll likely use strdup or strcpy to transfer existing data from memory to customers.tsv.
        - Nah, I lied, we prompt the user for a yes/no answer using printf and scanf, then we check a few things: if the file can't be opened then we print an error, otherwise we scan whatever's stored in memory and write it to (which we use fprintf() and fopen() for). The main function at the bottom specifies which file that we'll save to (customers.tsv).
- quit:
    - Clears stored memory and exits program.
        - Should be self-explanatory. free(), implement with a break loop or something of the sort. Clear the pointers too when we're done.
        - Yeah, we free everything and close the program. This is pretty straightforward, 'y' if you want to exit, 'n' and you go back to the main menu. There's a lot of free()'s and a basic linear search for the name, email, and food fields: if they have anything in them, we'll set all these fields to null and then get rid of any pointers that were stored in memory.

- main():
    - The backbone that makes up everything here. Defines all the functions that I have in my code and also is the reason why my save function actually saves to "customers.tsv".
    - Uses a while loop for the main menu: we prompt 6 actions (add, lookup, delete, list, save, quit). We scan the user's input like we do with all the other functions and then direct them to the proper action they selected.

# main_test.c
It should have tested the program, but for some reason my makefile (regardless of whether it's main or main_test) only runs the main program and not the test program.

# MAKEFILE
Was mostly based on the makefile from hw6, adapted for the customer database. Has similar flags for testing purposes as well. This is the part where I had a little bit of trouble, to be honest.
- Wall: gives us warnings for bad practice in our code
- Wpedantic: enforces C standard rules
- Werror: All warnings will be treated as errors
- Wextra: extra warning messages that Wall doesn't cover