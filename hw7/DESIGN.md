# Homework #7: Customer Database
# Author: Alexander Dao
# Class: CSE 13S, Prof. Rudnick
# Date: 2025-03-10

# Description: 
This program creates a customer database using a dictionary and allows the user to add, update, delete, and search for customers.

# customers.tsv:
Where our customer database is located. Contains customer info such as email address, display name, shoe size, favorite food.

# main.c (nain interaction loop):
Should read customers.tsv and store all the customers in a hash table. Will have the following functions:
- add:
    - Prompts the user for their personal information. Stores this in a hash table. We'll need to use malloc functions to store this info.
- lookup:
    - Prompt user for email address, find that entry in the hash table. Find the info of that customer and display the information about them.
- delete:
    - Prompt user for email address, find that entry in the hash table. Deletes user info if found, and throws a generic error message (e.g. "there's no matching email address") if no matches are found.
- list:
    - List every user in the database, in order.
- save:
    - Writes the current state (stored to memory) of the database to customers.tsv
- quit:
    - Clears stored memory and exits program.
        - Should be self-explanatory. free(), implement with a break loop or something of the sort. 

