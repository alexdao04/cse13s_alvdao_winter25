#include "editor_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions about ll_text...
// append a line: add to the end of the linked list

ll_text *append_text(ll_text *list, char *text) { 
  // append a line: add to the end of the linked list

  ll_text *element = malloc(sizeof(ll_text));
  // allocate memory for the element
  // this is the element we're going to add to the linked list

  if (element == NULL) {
  // if the element is NULL

    return NULL;
    // return NULL (since theres nothing to add)

  }

  element->text = strdup(text);
  // duplicate the input text and assign it to the element
  // this is the text we're going to add to the linked list

  if (element->text == NULL) {
  // if the element text is NULL

    free(element);
    // free the element from memory

    return NULL;
    // return NULL (again theres nothing to add)
  }

  element->next = list;
  // the next element is the current list

  return element;
  // return the element

}

void save_to_file(ll_text *list, const char *filename) {
  // save the linked list to a file

  FILE *outfile = fopen(filename, "w");
  // open the file for writing

  for (ll_text *here = list; here; here = here->next) {
  // iterate through the linked list

    fprintf(outfile, "%s\n", here->text);
    // print the text of the current element to the file

  }

  fclose(outfile);
  // close the file

}

int ll_text_length(ll_text *list) { 
// return the length of the linked list

  int text_length = 0;
  // initialize the text length to 0

  for (ll_text *here = list; here; here = here->next) {
  // iterate through the linked list

    text_length++;
    // increment the text length

  }

  return text_length;
  // return the text length

}

ll_text *insert_text(ll_text *list, char *text, int position) {
// insert a line at a specific position

  ll_text *new_element = malloc(sizeof(ll_text));
  // allocate memory for the new element

  if (new_element == NULL) {
  // if the new element is NULL

    return NULL;
    // return NULL (again, theres nothing to add)

  }

  new_element->text = strdup(text);
  // duplicate the input text and assign it to the new element

  if (new_element->text == NULL) {
  // if the new element text is NULL

    free(new_element);
    // free the new element from memory

    return NULL;
    // return NULL (again, theres nothing to add)
  }
  if (position == 0) {
  // if the position is 0

    new_element->next = list;
    // the next element is the current list

    return new_element;
    // return the new element
  }
  ll_text *current = list;
  // initialize the current element to the list

  for (int i = 0; i < position - 1 && current != NULL; i++) {
  // iterate through the linked list until the position before the desired position

    current = current->next;
    // move to the next element

  }

  if (current == NULL) {
  // if the current element is NULL

    free(new_element->text);
    // free the new element text from memory

    free(new_element);
    // free the new element from memory

    return list;
    // return the list (again, theres nothing to add)

  }

  new_element->next = current->next;
  // the next element is the next element of the current element

  current->next = new_element;
  // the next element of the current element is the new element

  return list;
  // then return the list

}

ll_text *delete_text(ll_text *list, int position) {
  // delete a line at a specific position

  if (list == NULL) {
  // if the list is NULL

    return NULL;
    // return NULL (theres nothing there to delete)

  }
  if (position == 0) {
  // if the position is 0

    ll_text *next = list->next;
    // the next element is the next element of the list

    free(list->text);
    // free the text of the list

    free(list);
    // free the list

    return next;
    // return the next element

  }

  ll_text *current = list;
  // initialize the current element to the list

  for (int i = 0; i < position - 1 && current->next != NULL; i++) {
  // iterate through the linked list until the position before the desired position

    current = current->next;
    // move to the next element

  }
  if (current->next == NULL) {
  // if the next element of the current element is NULL

    return list;
    // return the list (theres nothing to delete)

  }
  ll_text *to_delete = current->next;
  // the element to delete is the next element of the current element

  current->next = to_delete->next;
  // the next element of the current element is the next element of the element to delete

  free(to_delete->text);
  // free the text of the element to delete from memory

  free(to_delete);
  // free the element to delete from memory

  return list;
  // return the list

}

ll_text *replace_text(ll_text *list, char *text, int position) {
// replace a line at a specific position

  ll_text *current = list;
  // initialize the current element to the list

  for (int i = 0; i < position && current != NULL; i++) {
  // iterate through the linked list until the desired position

    current = current->next;
    // move to the next element

  }
  if (current != NULL) {
  // if the current element is not NULL

    free(current->text);
    // free the text of the current element

    current->text = strdup(text);
    // duplicate the input text and assign it to the text of the current element

  }

  return list;
  // return the list

}

ll_text *duplicate_ll_text(ll_text *list) {
// duplicate a linked list

  if (list == NULL) {
  // if the list is NULL

    return NULL;
    // return NULL (theres nothing to duplicate)

  }
  ll_text *new_list = NULL;
  // initialize the new list to NULL

  ll_text *tail = NULL;
  // initialize the tail to NULL

  for (ll_text *current = list; current != NULL; current = current->next) {
  // iterate through the linked list

    ll_text *new_element = malloc(sizeof(ll_text));
    // allocate memory for the new element

    new_element->text = strdup(current->text);
    // duplicate the text of the current element and assign it to the new element

    new_element->next = NULL;
    // the next element is NULL

    if (new_list == NULL) {
    // if the new list is NULL

      new_list = new_element;
      // the new list is the new element

    } else {
    // if the new list is not NULL

      tail->next = new_element;
      // the next element of the tail is the new element

    }

    tail = new_element;
    // the tail is the new element

  }

  return new_list;
  // return the new list

}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
// load a file into a stack

  ll_text *lines = NULL;
  // initialize the lines to NULL

  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  // allocate memory for the stack

  char buf[1024];
  // initialize a buffer to 1024

  FILE *infile = fopen(filename, "r");
  // open the file for reading

  while (fgets(buf, 1024, infile)) {
  // iterate through the file

    chomp(buf);
    // remove newline characters

    lines = append_text(lines, buf);
    // append the text of the buffer to the lines

  }

  stack->lines = lines;
  // the lines of the stack is the lines

  return stack;
  // return the stack

}

ll_text_stack *new_stack_empty_text(void) {
// create a new stack with empty text

  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  // allocate memory for the stack

  stack->lines = NULL;
  // the lines of the stack is NULL

  return stack;
  // return the stack

}

ll_text_stack *push_duplicate(ll_text_stack *stack) {
// push a duplicate of the current stack

  ll_text_stack *new_stack = malloc(sizeof(ll_text_stack));
  // allocate memory for the new stack

  new_stack->lines = duplicate_ll_text(stack->lines);
  // the lines of the new stack is a duplicate of the lines of the current stack

  new_stack->next = stack;
  // the lines of the new stack is a duplicate of the lines of the current stack

  return new_stack;
  // return the new stack

}

ll_text_stack *push_empty(ll_text_stack *stack) {
// push an empty stack

  ll_text_stack *new_stack = malloc(sizeof(ll_text_stack));
  // allocate memory for the new stack

  new_stack->lines = NULL;
  // the lines of the new stack is NULL

  new_stack->next = stack;
  // the next element of the new stack is the current stack

  return new_stack;
  // return the new stack

}

ll_text_stack *pop_stack(ll_text_stack *stack) {
// pop the stack

  if (stack == NULL) {
  // if the stack is NULL

    return NULL;
    // return NULL (theres nothing to pop)

  }
  ll_text_stack *next = stack->next;
  // the next element is the next element of the stack

  ll_text *lines = stack->lines;
  // the lines is the lines of the stack

  while (lines != NULL) {
  // iterate through the lines

    ll_text *next_line = lines->next;
    // the next line is the next line of the lines

    free(lines->text);
    // free the text of the lines

    free(lines);
    // free the lines

    lines = next_line;
    // the lines is the next line

  }

  free(stack);
  // we clear the stack

  return next;
  // return the next element

}

// Find the first newline in the input and replace it with \0
void chomp(char *s) {
// remove newline characters

  for (int i = 0; s[i]; i++) {
  // iterate through the string

    if (s[i] == '\n' || s[i] == '\r') {
    // Check for \r in case we're on Windows or a very old Mac??
    // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.

      s[i] = '\0';
      // replace it with a null character

      break;
      // break the loop, the newline character is removed
    }
  }
}
