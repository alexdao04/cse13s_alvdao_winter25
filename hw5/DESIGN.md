# Name: Alexander Dao
# CSE 13S Homework #3

# Introduction:
For this assignment, we're going to be creating the famous word game "Wordle". As the README.md stated, most of the game has been built for us already. That being said, the portion that we are going to write today is a series of functions in "wordle_lib.c". Completing this portion should give us a playable version of the game.

# "wordle_lib.c"
    // score_guess
        This function returns true when the guess we make is an exact match with the secret word in question. 
        We return a value "result" which we could think of as the result of our guess. 
        Perhaps we could just treat this as a bool "True".

    // valid_guess
        This function will return true when the guess we make matches some strings with the secret word. 
        Otherwise it returns False (because why would it return True if the guess had no strings in common?). 

    // load_vocabulary
        This function returns an array of strings where each string has a 5-letter word. 
        We will be dynamically allocating memory which would require us to use realloc().

    // free_vocabulary
        This function frees all of the strings from the array (essentially, clearing the memory). 
        It's the opposite of load_vocabulary so we would ideally just take that solution and reverse the steps.
