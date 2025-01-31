#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_newline(char *s, int maxsize) { // function to remove newline characters
  for (int i = 0; i < maxsize && s[i]; i++) { // goes through the string
    if (s[i] == '\n') { // if we find a newline
      s[i] = '\0'; // we change it to a null
      return; // then we return
    }
  }
}

int main(int argc, char *argv[]) { // the main function
  const int BUFSIZE = 80; // buffer size
  char buffer[BUFSIZE]; // buffer for reading input file lines
  FILE *infile = NULL; // file i/o pointer?

  if (argc != 2) { // this makes sure we only have one input file when running the program
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n"); // generic error msg
    return 1; // returns error if we have more than one input file
  }
  infile = fopen(argv[1], "r"); // open the file for reading
  if (!infile) { // what if the file in question doesn't exist?
    fprintf(stderr, "input file %s not found\n", argv[1]); // another generic error msg
    return 1; // and we return a missing input file error
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

            if(operator == '\0') { // if we don't have an operator
              operator = buffer[0]; // we set the operator to the first character of the line

            } else {
                long number = strtol(buffer, NULL, 10); // converts the string to a long integer
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
                    fprintf(stderr, "ERROR\n"); // print an error message
                    return 1; // and return

                  }

                  running_number /= number; // otherwise, we divide
                  break;

                default: // if we have an invalid operator
                  printf("ERROR\n"); // print an error message
                  return 1; // and we return

          }

        operator = '\0'; // resets our operator

        }
      }
    }

    printf("%ld\n", running_number); // prints our final result
    return 0; // we return our final result
    
}