// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;
  
int letter_scores[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                         12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
                         22, 23, 24, 25, 26};

// score_word testing
  assert(score_word("stalk", letter_scores) == 55);
  assert(score_word("scrap", letter_scores) == 55);
  assert(score_word("shear", letter_scores) == 55);
  
// score_letter testing

  assert(score_letter('a', vocabulary, num_words) == 2);
  assert(score_letter('b', vocabulary, num_words) == 2);
  assert(score_letter('c', vocabulary, num_words) == 2);
  
// filter_vocabulary_green testing

  assert(filter_vocabulary_green('a', 0, vocabulary, num_words) == 2);
  assert(filter_vocabulary_green('a', 1, vocabulary, num_words) == 2);
  assert(filter_vocabulary_green('a', 2, vocabulary, num_words) == 2);
  
// filter_vocabulary_yellow testing

  assert(filter_vocabulary_yellow('a', 0, vocabulary, num_words) == 2);
  assert(filter_vocabulary_yellow('a', 1, vocabulary, num_words) == 2);
  assert(filter_vocabulary_yellow('a', 2, vocabulary, num_words) == 2);
  
// filter_vocabulary_gray testing

  assert(filter_vocabulary_gray('a', vocabulary, num_words) == 1);
  assert(filter_vocabulary_gray('b', vocabulary, num_words) == 1);
  assert(filter_vocabulary_gray('c', vocabulary, num_words) == 1);

  // ... OK we're done, clean up the vocabulary.
  free_vocabulary(vocabulary, num_words);

  return 0;
}
