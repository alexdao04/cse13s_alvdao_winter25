#include "final.h"

#include <stdio.h>

#include <string.h>

char *remove_characters(char *text, char *toremove) {
  // we need to remove characters from a string
  // we can do this by reading the string
  // if a matching character is found, we can remove it
  char* result = text;

  while(*text) {
    if(strchr(toremove, *text)) {
      // if we find a matching character, remove it
      strcpy(text, (text + 1));
      // text + 1 is the next character over that we're copying
      // we go through the alphabet character by character
      // until we get a match
    } 
    
    else {
      text++;
      // if we don't find a matching character, move to the next one
      }
    }

    return result;
    // returns the final string
  }

