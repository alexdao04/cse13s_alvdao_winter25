#include "search_util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function should loop over the vocabulary (which contains num_words
// entries) and return the number of words in which that particular letter
// occurs. So if there are 15 words containing the letter 'x' for the particular
// vocabulary, then this function will return 15.
int score_letter(char letter, char **vocabulary, size_t num_words) {
  // letter tells us about which letter we are looking for

  int letter_score = 0;
  // initialize score  

  for(size_t i = 0; i < num_words; i++) {
    // for each word in the vocabulary

    if(vocabulary[i] == NULL) {
      continue;
      // if the word is null, skip to the next word and return 0
    }

    for(int j = 0; j < 5; j++) {
      // for each letter in the word

      if (vocabulary[i][j] == letter) {
        // if the letter is in the word

        letter_score++;
        // increment the score of the letter

        break;
        // if the letter is in the word, increment the score and break
        }
      }
    }
    return letter_score;
  }
      

// Calculate the score for a given word, where the letter_scores array has
// already been filled out for you and is guaranteed to be of length 26. Slot 0
// contains the score for 'a', and slot 25 contains the score for 'z'.
// The score for a word is the sum of all of the letter scores, *for unique
// letters*. So if the letter 'e' occurs three times, it only contributes to the
// score once.
int score_word(char *word, int *letter_scores) {

  int word_score = 0;
  // word_score initialize so we can track the total score of word

  bool letters_seen[26] = {false};
  // letters_seen is an array of 26 elements
  // we use this to track which letters have been seen (from a-z)
  // we initialize it to false because we haven't seen any letters yet

  for(int i = 0; i < 5; i++) {
    // for each letter in the word

    if(word[i] == '\0') {
      return word_score;
      // if the word is null, return the score

    }

    if(word[i] >= 'a' && word[i] <= 'z') {
      // if the word is between a and z

      int index = word[i] - 'a';
      // index is the position of the letter in the word (hence [i], this is an array)
      // minus the position of the letter in the alphabet (1-26 for a-z)

      if(!letters_seen[index]) {
        // if the letter has not been seen

        word_score += letter_scores[index];
        // add to the score of the word 
        // from the letter_scores array

        letters_seen[index] = true;
        // if the letter has not been seen, increment the score
        // set the letter to true
      }
    }
  }

  return word_score;
  // return the score of the word

}

// Returns the optimum guess, based on our heuristic.
// This one works, you don't have to change it.
// Note that this function allocates a new string every time it runs, and those
// strings will need to be freed!
char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for(int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for(size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if(score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *does not occur* in the secret word. So for any of the words
// in the vocabulary that do contain that letter, free their pointers and set
// the corresponding slot to NULL.
// Returns the number of words that have been filtered from the vocabulary.

size_t filter_vocabulary_gray(char letter, char **vocabulary,
                              size_t num_words) {

  size_t gray_filter = 0;
  // initialize gray_filter to count # of words filtered
  
  for(size_t i = 0; i < num_words; i++) {
     // for each word in the vocabulary

      if(vocabulary[i] == NULL) {
        // if the word is null

        continue;
        // continue to the next word

      }

      bool has_letter = false;
      // initialize has_letter to false
      // this is how we know that the letter is in the word or not

      for(int j = 0; j < 5; j++) {
        // for each letter in the word (we have 5 letters in the word)

        if(vocabulary[i][j] == letter) {
          // if the letter is in the word

          has_letter = true;
          // set has_letter to true
          // this is how we know that the letter is in the word

          break;

      }
    }

    if(!has_letter) {
      // if the letter is not in the word (at all)

      gray_filter++;
      // increment the gray_filter counter
      // this tells us how many words have been filtered

    } else {
      // if the letter is in the word

      free(vocabulary[i]);
      // free the pointer

      vocabulary[i] = NULL;
      // set the pointer to NULL
      // this is how we track which letter goes to which slot in the word

    }
  }

  return gray_filter;
  // return the number of words that have been filtered

}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word, *but not at this particular position*.
// So remove any words that either don't contain the letter at all, or do
// contain it, but at the specified position.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary,
                                size_t num_words) {
  
size_t yellow_filter = 0;
// initialize counter for # of words filtered

  for(size_t i = 0; i < num_words; i++) {
      // for each word in the vocabulary (index using i)

      if(vocabulary[i] == NULL) {
        // if the word is null, move along

        continue;
        // this is how we know that the word has been filtered

      }

      bool has_letter = false;
      // initialize has_letter to 0 (false)
  
      for(int j = 0; j < 5; j++) {
        // for each letter in the word
        // use 0 to initialize j

        if(vocabulary[i][j] == letter && j != position) {
          // if the letter is in the word (but not the right position)

          has_letter = true;
          // set the yellow_filter to true
          // this is how we know that the word has been filtered

        break;
        // break out of the loop
        
        }
      }

      if(has_letter) {
        // if the letter is in the word but not the correct position

        yellow_filter++;
        // increment the yellow_filter counter

      } else {
        // if the letter is at the position

        free(vocabulary[i]);
        // free the pointer

        vocabulary[i] = NULL;
        // set the pointer to NULL
        // this is how we track which letter goes to which slot in the word
   
    }
  }

  return yellow_filter;
  // return the number of words that have been filtered

}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *definitely* occurs as the specified position. So remove any
// word that does not contain, for the specified position, the specified letter.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary,
                               size_t num_words) {

  size_t green_matches = 0;
  // initialize counter for # of words filtered that match the letter position
  
  for(size_t i = 0; i < num_words; i++) {
    // for each word in the vocabulary

    if(vocabulary[i] != NULL) {
      printf("Checking: %s at position %d\n", vocabulary[i], position);
      // if the word is not null, print the word and the position
      
      if(position < (int)strlen(vocabulary[i]) && 
         vocabulary[i][position] == letter) {
      // if the position is less than the length of the word
      // and the letter at the position is the same as the letter we are looking for
      // this is how we know that the letter is in the word
      // and the letter is in the correct position

      green_matches++;
      // increment the green_matches counter
    }
  }
}
  return green_matches;
                               }

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {

  for(size_t i = 0; i < num_words; i++) {

    free(vocabulary[i]);
    // clear the vocabulary array

  }

  free(vocabulary);
  // clear the pointer that held the array

}
