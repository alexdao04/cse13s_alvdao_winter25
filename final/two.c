#include "final.h"

#include <stdio.h>

#include <string.h>

char *remove_characters(char *text, char *toremove) {
  // we need to remove characters from a string
  // we can do this by reading the string
  // if a matching character is found, we can remove it

    char *updated_text = malloc(strlen(text) + 1);
      // start by allocating memory

    if (!updated_text) {
        return NULL; 
        // just in case our string didnt get updated
    }

    char *updated_text_ptr = updated_text;
    // stores the updated string
    char *temp = text;
    // stores the original string

    while (*temp) {
      // while loop to read the string
        char *toremove_temp = toremove;
          // initialize check to toremove

        while (*toremove_temp) {
          // check if the character is in the string
            if (*temp == *toremove_temp) {
              // if it is
                break;
                  // break out of the loop
            }

            toremove_temp++;
              // increment check (because we're checking the next character)
        }

        if (!*toremove_temp) {
          // if the pointer to check is empty
            *updated_text_ptr++ = *temp;
              // add the character to the new string
        }

        temp++;
          // increment temp (because we're moving to the next character)
      }          

    *updated_text_ptr = '\0';
    return updated_text;
    // return the final result
}
