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
  // vocabulary tells us where the words are 
  // num_words tells us how many words are in the vocabulary

  int score = 0;
  // initialize score  

  for(size_t i = 0; i < num_words; i++) {
    // for each word in the vocabulary

    if(vocabulary[i] == NULL) {
      return 0;
      // if the word is null, skip to the next word and return 0
    }

    for(int j = 0; j < 6; j++) {
      // for each letter in the word
      if (vocabulary[i][j] == letter) {
        score++;
        break;
        // if the letter is in the word, increment the score and break
        }
      }
    }
    return score;
  }
      

// Calculate the score for a given word, where the letter_scores array has
// already been filled out for you and is guaranteed to be of length 26. Slot 0
// contains the score for 'a', and slot 25 contains the score for 'z'.
// The score for a word is the sum of all of the letter scores, *for unique
// letters*. So if the letter 'e' occurs three times, it only contributes to the
// score once.
int score_word(char *word, int *letter_scores) {

  int score = 0;
  // initialize score to track the score of the word

  for(int i = 0; i < 6; i++) {
    // for each letter in the word

    if(word[i] == '\0') {
      return score;
      // if the word is null, return the score

    }

    if(word[i] >= 'a' && word[i] <= 'z') {
      score += letter_scores[word[i] - 'a'];
      // if the word is in the alphabet, increment the score
      // subtracting 'a' from the word gives us the index of the letter in the alphabet

    }
  }

  return score;
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
  
  for(size_t i = 0; i < num_words; i++) {
     // for each word in the vocabulary

      if(vocabulary[i] == NULL) {
        continue;
        // if the word is null, continue to the next word

      }

      for(int j = 0; j < 6; j++) {
        // for each letter in the word

        if(vocabulary[i][j] == letter) {
          // if the letter is in the word

          free(vocabulary[i]);
          // free the vocabulary pointer

          vocabulary[i] = NULL;
          // set the pointer to NULL to track which letter goes to which slot in the word

          gray_filter++;
          // increment the gray_filter counter (tells us how many words have been filtered)

          break;
          // break out of the loop

      }
    }
  }

  return gray_filter;

}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word, *but not at this particular position*.
// So remove any words that either don't contain the letter at all, or do
// contain it, but at the specified position.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary,
                                size_t num_words) {
  
size_t yellow_filter = 0;

  for(size_t i = 0; i < num_words; i++) {
      // for each word in the vocabulary (index using i)

      if(vocabulary[i] == NULL) {
        continue;
        // if the word is null, return 0
        // this is how we know that the word has been filtered

      }

      bool yellow_filter = false;
      // initialize the yellow_filter to 0 (false)
  
      for(int j = 0; j < 6; j++) {
        // for each letter in the word
        // use 0 to initialize j

        if(vocabulary[i][j] == letter) {
          yellow_filter = true;
          // if the letter is in the word, set the yellow_filter to true
          // this is how we know that the word has been filtered

        break;
        // break out of the loop
           
      }

      if(!yellow_filter || vocabulary[i][position] == letter) {
        free(vocabulary[i]);
        vocabulary[i] = NULL;
        // if the letter is in the word or the letter is at the position
        // free the pointer and set it to NULL
        // this is how we track which letter goes to which slot in the word

      }
    }
  }

  return yellow_filter;

}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *definitely* occurs as the specified position. So remove any
// word that does not contain, for the specified position, the specified letter.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary,
                               size_t num_words) {

  size_t green_filter = 0;

  for(size_t i = 0; i < num_words; i++) {
    // for each word in the vocabulary

    if(vocabulary[i] == NULL) {
      return 0;
      // if the word is null, return 0
      // this is how we know that the word has been filtered

      }

    for(int j = 0; j < 6; j++) {
      // for each letter in the word

      if(vocabulary[i][position] != letter) {
        free(vocabulary[i]);
        vocabulary[i] = NULL;
        green_filter++;
          // if the letter is in the word 
          // free the pointer and set it to NULL
          // position is the index of the letter in the word
          // this is how we track which letter goes to which slot in the word

      }
    }
  } 

  return green_filter;
  // return the number of words that have been filtered
   
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {

  for (size_t i = 0; i < num_words; i++) {

    free(vocabulary[i]);
    // clear the vocabulary array

  }

  free(vocabulary);
  // clear the pointer that held the array

}
