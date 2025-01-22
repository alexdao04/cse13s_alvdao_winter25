#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int num_lines = 0;
  int num_es = 0;
  int num_vowels = 0;
  int num_non_e = 0;
  int num_a = 0;

  while (1) {
    int c = getchar();

    // check for the end of the input
    if (c == EOF) {
      break;
    }

    switch (c) {
      case 'a':
      case 'A':
        num_a++;
        break;
      case 'z':
        // do something for z
        break;
    }

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      num_vowels += 1;
    }

    // check for a newline
    if (c == '\n') {
      num_lines++;
    } else if (c == 'e') {
      num_es++;
    } else {
      num_non_e++;
    }
  }

  printf("here's how many lines: %d\n", num_lines);
  printf("here's how many letter e: %d\n", num_es);
  printf("here's how many not-e: %d\n", num_non_e);
  printf("here's how many vowels: %d\n", num_vowels);

  return 0;
}
