#include "wordle_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Most of the code that you're going to have to implement goes in here.
// Feel free to add more helper functions if necessary.

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {  
  // secret represents the word we are trying to guess
  // guess tells us where our letters are (in)correct
  // result represents the result of our guess
    // this is what we're going to return

  for (int i = 0; i < 5; i++) {
    // we iterate through the guess

    if (guess[i] == secret[i]) {
      // if the guess is equal to the secret

      result[i] = 'g';
      // we set the result to 'g'

    } else if (strchr(secret, guess[i]) != NULL) {
      // if the guess is not equal to the secret

      result[i] = 'y';
      // we set the result to 'y'

    } else {
      // if the guess is not equal to the secret

      result[i] = 'x';
      // otherwise, we set the result to 'x'

    }

    guess++;
    // we increment the guess

  }

  result[5] = '\0'; 
  // result null to signify EOF

  return strcmp(secret, guess) == 0;
  // we return whether the guess is equal to the secret

}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  
  // guess tells us where our letters are (in)correct
  // vocabulary is the list of words we can guess from
  // num_words is the length of the vocabulary (and size_t is an unsigned int)

  for(size_t i = 0; i < num_words; i++) {
    // we iterate through the vocabulary

    if(strcmp(guess, vocabulary[i]) == 0) {
      // if the guess is in the vocabulary

      return true;
      // we return true

    }
  }

  return false;
  // otherwise, we return false

}


// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {

  char **out = NULL;
  // set to null

  *num_words = 0;
  // out is the list of words we can guess from

  // filename is going to be the file that we are reading from.
  // num_words is going to be the number of words in the file
  // we can determine this from the line count of the file
  FILE *file = fopen(filename, "r");
  // we open the file for reading

  if(file == NULL) {
    // if the file is NULL

    return NULL;
    // we return NULL
  }
  char *line = NULL;
  // line is the line we are reading from

  size_t len = 0;
  // len is the length of the line

  ssize_t read;
  // read is the number of characters read
  // we set this as a signed data type because:
  // getline returns -1 when we reach EOF

  while((read = getline(&line, &len, file)) != -1) {
    // we read the line from the file

    if (read == 6) {
      // if the line is 6 characters long (we count the null too)

      out = realloc(out, (*num_words + 1) * sizeof(char *));
      // we reallocate the memory for the list of words

      if(out == NULL) {
        // if the list of words is NULL

        free(line);
        // we free the line

        fclose(file);
        // we close the file

        return NULL;
        // we return NULL
      }

      out[*num_words] = strndup(line, 5);
      // we set the list of words to be the line we read
      
      if(out[*num_words] == NULL) {
        // if the list of words is NULL

        free(line);
        // we free the line

        fclose(file);
        // we close the file

        return NULL;
        // we return NULL
      }

      (*num_words)++;
      // we increment the number of words

    }
  }
  free(line);
  // we free the line

  fclose(file);
  // and close the file.

  return out;
  // finally, conclude by returning out (our list of words)

}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // vocabulary is the list of words we can guess from
  // num_words is the length of the vocabulary (and size_t is an unsigned int)

  for(size_t i = 0; i < num_words; i++) {
    // we iterate through the vocabulary
    free(vocabulary[i]);
    // and free the list of words
  }

  free(vocabulary);
}
