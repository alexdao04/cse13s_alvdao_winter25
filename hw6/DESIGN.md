# Homework #6: Wordle Part 2
# Author: Alexander Dao
# CSE 13S, Prof. Alex Rudnick

In this homework assignment, we're given a partially completed version of wordle (similarly to the assignment from the previous week), where we need to implement a solver. This solver, as the README.md described, works in two different ways; either the secret word is known to the user and specified to the program already, or the solver iteratively suggests guesses to help search for potential matches that solve our wordle. 

# Main: search_util.c
search_util.c is a program containing functions key to searching our vocabulary. This program is partially written for us, but there's a number of functions within it that we're going to have to write and implement ourselves. Let's start with score_letter.

# score_letter
score_letter is a function that loops over our vocabulary list and returns a count of words that match the provided letter in the given slot.

# score_word
score_word is a function that calculates a total score from all 5 letter listed in the array (and only unique ones, so any repeating letters are counted only once). We tally this up and this is how we index what letters are really what; 0 represents A while 25 represents Z. 

# filter_vocabulary_gray
filter_vocabulary_gray is a function that goes through our vocabulary list and eliminates words (sets them to NULL) based on whether the guessed letter appears at any given position in our secret word or not. We ignore anything that's null, and tally anything that matches our vocabulary filters with an increment counter.

# filter_vocabulary_yellow
filter_vocabulary_yellow is a function that similarly goes through our vocabulary list and eliminates words, however it looks for words where the letter appears in the word but not at the given position in the word. This further filters out any words that don't have letter matches, or do but don't match our secret word. Again, see above: ignore marked NULLs, tally anything that matches, and increment our counter 

# filter_vocabulary_green
filter_vocabulary_green is a function that filters through our vocabulary list for words that match the letter position of the secret word. Tally anything that matches, increment counter, ignore marked NULLs.

# free_vocabulary
free_vocabulary is a function that nullifies our vocab values that don't match the given secret word, whether in letter position or the letters themselves. 
Set anything that doesn't match our filters to NULL and then tally everything else.

# Test Writing: "search_util_test.c"
The next challenge we're going to have here is writing our test cases. This is the first time that we're doing this in our class, so this might be a little finicky the first time.

We want to write cases for the following functions:

score_letter, score_word, filter_vocabulary_green, filter_vocabulary_yellow, and  filter_vocabulary_gray. Also, maybe free_vocabulary to make sure we're actually handling that correctly.

# score_letter:
If we have a base case where we know that there's a certain amount of words that contain the letter "s" in our vocabulary, and particularly in a certain position, we'll know how many words should appear in there. This might be simplifiable with a bit of regex and some Ctrl+F, but if we return different values from what we calculated through our base case, something's for sure wrong with my implementation.

# score_word
Basically, so long as we can map each letter to a value between 0 and 26 (given that 0 is A and 26 is Z), we can simply tally these values up and return our score to know whether what we guessed matches the given secret word's score (assuming we had it calculated before guessing). We're going to use base cases to help us determine whether our implementation works or not.

# filter_vocabulary_green, yellow, gray
These are super important, it's the backbone that helps us really figure out whether we have correct matches or not. 
A good way to go about this is to write test conditions that return the number of words filtered; if we have a known value from a base case, that'll help us figure out whether our implementation is properly working or not. 

# free_vocabulary
This one, I figure it would be best to test whether we're actually setting our non-matching values to NULL properly, or not. This will tell us whether we're excluding the correct values, and is key for our filter_vocabulary functions (green, yellow, and gray).
