# Name: Alexander Dao
# CSE 13S Homework #3

# Introduction
What we have here is a template for a text editor; as the documentation stated, users don't like VIM, VSCode, Emacs, **or** Sublime Text.
We've got 5 files that make up this assignment, according to our README.md: "editor_lib.h", "editor_lib.c", "editor.c", "Makefile", and "editor_lib_test.c". Of these, we only have to open two: "editor_lib.c" and "editor.c". Anyways, let's break down this implementation:

# "editor.c"
This is basically where all our basic commands and operations within this text editor go.

# "editor_lib.c"
This is where a majority of the work I'm doing is going to go.

*"ll_text *append_text"*
A way of approaching this is a function that adds the node manually to our list using a formula. Return our new front of list afterwards.

*"ll_text *insert_text"*
Adds another node, but at a given position in the list. Return value should be the new front of the list. Similar approach to append_text.

*"ll_text *delete_text"*
Deletes a node at a given position in the list instead of adding it like we would in "*insert_text". Return value is the new front of the list.

*"ll_text *replace_text"*
Overwrites text at given node position with a different text. May require storing to heap.

*"ll_text *duplicate_ll_text"*
Copies the entire linked list.
Output should be the front of our "new" list.
Likely need to remove the old one, but how I'll implement the copy feature is going to be my challenge...

*"ll_text_stack *push_duplicate"*
Writes to the stack again with a copy of the ll_text linked list.
Same issue as duplicate_ll_text, the copy part might be my issue here

*"ll_text_stack *push_empty"*
Writes a new, empty entry to the stack instead.
Just write a null character or something lol

*"ll_text_stack *pop_stack"*
Frees memory and removes top entry in the stack. Should clean everything up and removes anything allocated.
Might be a good idea to review that reduce function that I used in hw3. The logic used there might be similar..