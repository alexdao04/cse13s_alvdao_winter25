# Homework #7: Customer Database
# Author: Alexander Dao
# Class: CSE 13S, Prof. Rudnick
# Date: 2025-03-10

# Description: 
This program creates a customer database using a dictionary and allows the user to add, update, delete, search, and list customers. Ideally should be done using a hashtable for O(1) efficiency.

# customers.tsv:
Where our customer database is located. Contains customer info such as email address, display name, shoe size, favorite food.

# main.c (nain interaction loop):
Should read customers.tsv and store all the customers in a hash table. Will have the following functions:
- add:
    - Prompts the user for their personal information. Stores this in a hash table. We'll need to use malloc functions to store this info. This can be handled with basic I/O operations (printf(), scanf()).
- lookup:
    - Prompt user for email address, find that entry in the hash table. Find the info of that customer and display the information about them.
        - We could do a search based on regex fields; we format our search to recognize any email format regardless of domain (gmail, ucsc.edu, etc.) as well as separately handle the user id portion of the email (e.g. sammy in sammy@ucsc.edu)
- delete:
    - Prompt user for email address, find that entry in the hash table. Deletes user info if found, and throws a generic error message (e.g. "there's no matching email address") if no matches are found.
        - Could be handled similarly to the quit function; only thing is, we don't break the loop afterward and continue on. Clear the entry though, instead of clearing the memory
- list:
    - List every user in the database, in order.
        - We'll likely use strdup or strcpy, then print the last saved data in customers.tsv. That file will have all of the data that we're supposed to work with.
- save:
    - Writes the current state (stored to memory) of the database to customers.tsv
        - Again, we'll likely use strdup or strcpy to transfer existing data from memory to customers.tsv.
- quit:
    - Clears stored memory and exits program.
        - Should be self-explanatory. free(), implement with a break loop or something of the sort. Clear the pointers too when we're done.

