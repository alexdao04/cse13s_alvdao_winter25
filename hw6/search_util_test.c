// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "search_util.h"

void init_vocabulary(char **vocabulary, char words[10][6], size_t num_words) {
  // initialize the vocabulary array with the words from the words array

  for (size_t i = 0; i < num_words; i++) {
    // for each word in the vocabulary array

      vocabulary[i] = strdup(words[i]);
      // allocate memory for the words in the vocabulary array
      // using strdup, we copy to the array

  }
}


int main(void) {

  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.

  char **vocabulary = calloc(10, sizeof(char *));
  // here we allocate memory for the vocabulary array
  // we have 10 words in the array (words[10][6])
  // these are basically the words we're going to use as vocabulary examples
  
  for (int i = 0; i < 10; i++) {
    // for each word in the array (we have 10 words)

    vocabulary[i] = strdup(words[i]);
    // we allocate memory for the words in the vocabulary array
    // using strdup, we copy to the array

  }

  size_t num_words = 10;
  // we have 10 words in the vocabulary array
  
int letter_scores[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                         12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
                         22, 23, 24, 25, 26};
                        // letter scores for the alphabet (a - z)
                        
// score_word testing

if(score_word("stalk", letter_scores) != 63) {
  printf("Test failed: score_word(\"stalk\", letter_scores) != 63\n");
  printf("Result is: %d\n", score_word("stalk", letter_scores));

} else if(score_word("stalk", letter_scores) == 63) {
  printf("Test passed: score_word(\"stalk\", letter_scores) == 63\n");

}

if(score_word("scrap", letter_scores) != 57) {
  printf("Test failed: score_word(\"scrap\", letter_scores) != 57\n");
  printf("Result is: %d\n", score_word("scrap", letter_scores));

} else if(score_word("scrap", letter_scores) == 57) {
  printf("Test passed: score_word(\"scrap\", letter_scores) == 57\n");

}

if(score_word("shear", letter_scores) != 51) {
  printf("Test failed: score_word(\"shear\", letter_scores) != 51\n");
  printf("Result is: %d\n", score_word("shear", letter_scores));

} else if(score_word("shear", letter_scores) == 51) {
  printf("Test passed: score_word(\"shear\", letter_scores) == 51\n");

}

// score_letter testing
init_vocabulary(vocabulary, words, num_words);

if(score_letter('a', vocabulary, num_words) != 7) {
  printf("Test failed: score_letter('a', vocabulary, num_words) != 7\n");
  printf("Result is: %d\n", score_letter('a', vocabulary, num_words));

} else if(score_letter('a', vocabulary, num_words) == 7) {
  printf("Test passed: score_letter('a', vocabulary, num_words) == 7\n");

}

if(score_letter('b', vocabulary, num_words) != 1) {
  printf("Test failed: score_letter('b', vocabulary, num_words) != 1\n");
  printf("Result is: %d\n", score_letter('b', vocabulary, num_words));

} else if(score_letter('b', vocabulary, num_words) == 1) {
  printf("Test passed: score_letter('b', vocabulary, num_words) == 1\n");

}

if(score_letter('c', vocabulary, num_words) != 2) {
  printf("Test failed: score_letter('c', vocabulary, num_words) != 2\n");
  printf("Result is: %d\n", score_letter('c', vocabulary, num_words));

} else if(score_letter('c', vocabulary, num_words) == 2) {
  printf("Test passed: score_letter('c', vocabulary, num_words) == 2\n");

}

// filter_vocabulary_green testing
init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_green('a', 0, vocabulary, num_words) != 0) {
  printf("Test failed: filter_vocabulary_green('a', 0, vocabulary, num_words) != 0\n");
  printf("Result is: %zu\n", filter_vocabulary_green('a', 0, vocabulary, num_words));

} else if(filter_vocabulary_green('a', 0, vocabulary, num_words) == 0) {
  printf("Test passed: filter_vocabulary_green('a', 0, vocabulary, num_words) == 0\n");

}

init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_green('b', 1, vocabulary, num_words) != 1) {
  printf("Test failed: filter_vocabulary_green('b', 1, vocabulary, num_words) != 1\n");
  printf("Result is: %zu\n", filter_vocabulary_green('b', 1, vocabulary, num_words));

} else if(filter_vocabulary_green('b', 1, vocabulary, num_words) == 1) {
  printf("Test passed: filter_vocabulary_green('b', 1, vocabulary, num_words) == 1\n");

}

init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_green('b', 2, vocabulary, num_words) != 5) {
  printf("Test failed: filter_vocabulary_green('c', 2, vocabulary, num_words) != 5\n");
  printf("Result is: %zu\n", filter_vocabulary_green('b', 2, vocabulary, num_words));

} else if(filter_vocabulary_green('b', 2, vocabulary, num_words) == 5) {
  printf("Test passed: filter_vocabulary_green('c', 2, vocabulary, num_words) == 5\n");

}

// filter_vocabulary_yellow testing
init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_yellow('a', 0, vocabulary, num_words) != 6) {
  printf("Test failed: filter_vocabulary_yellow('a', 0, vocabulary, num_words) != 6\n");
  printf("Result is: %zu\n", filter_vocabulary_yellow('a', 0, vocabulary, num_words));

} else if(filter_vocabulary_yellow('a', 0, vocabulary, num_words) == 6) {
  printf("Test passed: filter_vocabulary_yellow('a', 0, vocabulary, num_words) == 6\n");

}

init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_yellow('b', 0, vocabulary, num_words) != 5) {
  printf("Test failed: filter_vocabulary_yellow('b', 0, vocabulary, num_words) != 5\n");
  printf("Result is: %zu\n", filter_vocabulary_yellow('b', 0, vocabulary, num_words));

} else if(filter_vocabulary_yellow('b', 0, vocabulary, num_words) == 5) {
  printf("Test passed: filter_vocabulary_yellow('b', 0, vocabulary, num_words) == 5\n");

}

init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_yellow('c', 0, vocabulary, num_words) != 2) {
  printf("Test failed: filter_vocabulary_yellow('c', 0, vocabulary, num_words) != 2\n");
  printf("Result is: %zu\n", filter_vocabulary_yellow('c', 0, vocabulary, num_words));

} else if(filter_vocabulary_yellow('c', 0, vocabulary, num_words) == 2) {
  printf("Test passed: filter_vocabulary_yellow('c', 0, vocabulary, num_words) == 2\n");

}

// filter_vocabulary_gray testing
init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_gray('a', vocabulary, num_words) != 4) {
  printf("Test failed: filter_vocabulary_gray('a', vocabulary, num_words) != 4\n");
  printf("Result is: %zu\n", filter_vocabulary_gray('a', vocabulary, num_words));

} else if(filter_vocabulary_gray('a', vocabulary, num_words) == 4) {
  printf("Test passed: filter_vocabulary_gray('a', vocabulary, num_words) == 4\n");

}

init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_gray('b', vocabulary, num_words) != 9) {
  printf("Test failed: filter_vocabulary_gray('b', vocabulary, num_words) != 9\n");
  printf("Result is: %zu\n", filter_vocabulary_gray('b', vocabulary, num_words));

} else if(filter_vocabulary_gray('b', vocabulary, num_words) == 9) {
  printf("Test passed: filter_vocabulary_gray('b', vocabulary, num_words) == 9\n");

}

init_vocabulary(vocabulary, words, num_words);

if(filter_vocabulary_gray('c', vocabulary, num_words) != 9) {
  printf("Test failed: filter_vocabulary_gray('c', vocabulary, num_words) != 9\n");
  printf("Result is: %zu\n", filter_vocabulary_gray('c', vocabulary, num_words));

} else if(filter_vocabulary_gray('c', vocabulary, num_words) == 9) {
  printf("Test passed: filter_vocabulary_gray('c', vocabulary, num_words) == 9\n");

}

  // ... OK we're done, clean up the vocabulary.
  free_vocabulary(vocabulary, num_words);

  return 0;
  
}
