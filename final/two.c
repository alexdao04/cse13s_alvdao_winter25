#include "final.h"

#include <stdio.h>

#include <string.h>

char *remove_characters(char *text, char *toremove) {
  // we need to remove characters from a string
  // we can do this by reading the string
  // if a matching character is found, we can remove it
  char *result = text;
  char *temp = text;

  while (*text) {
    char *toremove_temp = toremove;
    while (*toremove_temp) {
      if (*text == *toremove_temp) {
        break;
      }
      toremove_temp++;
    }
    if (!*toremove_temp) {
      *temp = *text;
      temp++;
    }
    text++;
  }
return result;
}
