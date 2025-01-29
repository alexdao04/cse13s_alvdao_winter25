#include <stdio.h>
#include <stdlib.h>

void remove_newline(char *s, int maxsize) { // function to remove newline characters
  for (int i = 0; i < maxsize && s[i]; i++) { // iterates through the string
    if (s[i] == '\n') { // if we find a newline character
      s[i] = '\0'; // we replace it with a null terminator
      return; // and return
    }
  }
}

int main(int argc, char *argv[]) { // main function
  const int BUFSIZE = 80; // buffer size
  char buffer[BUFSIZE]; // buffer to store input
  FILE *infile = NULL; // file pointer

  if (argc != 2) { // if we don't have exactly 2 arguments
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
    return 1; // return an error
  }
  infile = fopen(argv[1], "r"); // open the file for reading
  if (!infile) { // if the file doesn't exist
    fprintf(stderr, "input file %s not found\n", argv[1]); // print an error message
    return 1; // return an error
  }

  // code starts about here**
  long running_number = 0; // initializes the running number to 0
  char operator = '\0'; // null operator character
  int first_line = 1; // we start on the first line

  while (fgets(buffer, BUFSIZE, infile)) { // reads the file line by line
    remove_newline(buffer, BUFSIZE); // removes newline characters
      if(first_line) { // the first line is a base-10 integer
        running_number = strtol(buffer, NULL, 10); // converts the string to a long integer
        first_line = 0;
      } else { // the rest of the lines are operations
          long number = 0; // initializes the number to 0
          if(sscanf(buffer, "%c %ld", &operator, &number) != 2) { // if we have a valid operator and number
            printf("ERROR\n"); // print an error message
            fclose(infile); // close the file
              return 1; // and return
          }
          switch(operator) {
            case '+': // addition
              running_number += number;
              break;
            case '-': // subtraction
              running_number -= number;
              break;
            case '*': // multiplication
              running_number *= number;
              break;
            case '/': // division
              if(number == 0) { // if we're dividing by zero
                printf("ERROR\n"); // print an error message
                fclose(infile); // close the file
                return 1; // and return
              }
              running_number /= number;
              break;
            default: // if we have an invalid operator
              printf("ERROR\n"); // print an error message
              fclose(infile); // close the file
              return 1; // and return
        }
      }
  }
  printf("%ld\n", running_number); // prints the running number
  fclose(infile); // closes the file
  return 0;
}
