#include <stdio.h>

int main(void) {
  // Finish this program. You'll almost certainly want to use a loop of some
  // kind, getchar() and putchar(). Remember that the output of getchar() is the
  // symbol EOF when you get to the end of the input.
  int vowel_char = getchar();
  int num_vowels = 0;
    while ((vowel_char = getchar()) != EOF) { // this is the loop that will duplicate all vowel characters regardless of capitalization
    if (vowel_char == 'a' || vowel_char == 'e' || vowel_char == 'i' || vowel_char == 'o' || vowel_char == 'u'
        || vowel_char == 'A' || vowel_char == 'E' || vowel_char == 'I' || vowel_char == 'O' || vowel_char == 'U') {
      num_vowels += 1;
      putchar(vowel_char);
      return 0;
    }
}
}