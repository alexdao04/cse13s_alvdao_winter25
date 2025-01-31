# Name: Alexander Dao
# CSE 13S Homework #3

# Introduction
*Here, we have seven different functions to complete, similarly to our previous assignments.*
*We're gonna run through each individually, in order from first to last, and break down how we're going to approach this.*

# Function 1: "str_suffix"
This function returns a True boolean if the string "needle" is a suffix of the string "haystack". 
This assumes that "needle" and "haystack" are really just placeholder variables for the actual strings we're going to be comparing. 
The approach I plan to take is to declare my needle and haystack length as an int, then compare the two to determine which is the bigger word. At the same time I'm comparing the actual string values themselves for needle and haystack too, in order to determine whether needle slices into a suffix of "haystack". The value returned tells us whether "needle" is or is not a suffix of "haystack".

# Function 2: "str_repeat"
This function returns a string thats the input string "s" repeated "n" amount of times. We call malloc() to allocate memory for the resulting output string, and then return the value.
What I'm thinking here is that we initialize our input string and have it return our given string s, and at the same time initialize our int counter so that our n value repeats n amount of times. We allocate some memory to the heap using malloc() (we need a place to store our output string) and then return our resulting output string. 

# Function 3: "str_is_palindrome"
This function returns a True boolean is the string "s" is a palindrome.
It's pretty self explanatory; all we really need to do is set up some while and if-conditions to catch certain conditions that indicate we're working with a palindrome. Initialize with a string and then set up a bunch of criteria to evaluate whether we have a palindrome. If we do, we return True; if not, False.

# Function 4: "dot_product"
This function returns the dot product of two vectors.
Our resulting value should be the sum of the products of the elements within the two arrays. 
For this one we have to find the value of each vector and return it separately. We're given two float values declared in the function, vec_a and vec_b. We ideally want to combine these two arrays to get our final product. At the same time, we have length which tells us how many elements we have in the array at the moment. length tells us how many times we need to iterate over before we get our final product from our two arrays; the amount of elements is the amount of times that we will end up iterating. With all conditions satisfied, all we have to do is return our final dot product. 

# Function 5: "reduce"
This function combines all elements of an array into a single value, hence the name "reduce".
Our final value returned is the product obtained after applying a given function to all elements making up the array.
The real challenge is figuring out how to combine all these elements together. The function declares them all as int values meaning that I could probably use math operators to concatenate the values in the array into one final value.
What we could do is approach this iteratively. Add one element and then move to the next until we've approached the end of the array (which we could catch with a conditional).

# Function 6: "maximum_with_reduce"
This function finds the largest element in an array and returns a final value, while still calling "reduce".
We can basically implement this by setting up criteria in aseries of conditional statements to catch elements that match what we're looking for; the largest one in the array. I imagine a while loop might be a way of implementing this.

# Function 7: "sum_positive_with_reduce"
This function sums all positive elements in the array and returns a final value, while again still calling "reduce".
Again, we're using a similar methodology to Function #6; setting up a series of conditionals in a loop, possibly using a while loop with further if-conditions. This will help us catch elements that are positive, and exclude any elements from the array that are negative or zero.



