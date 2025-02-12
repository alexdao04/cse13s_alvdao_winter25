#include "editor_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions about ll_text...
// append a line: add to the end of the linked list

ll_text *append_text(ll_text *list, char *text) { 
  // list is the head of the linked list 
  // aka what we're adding to, and want to return in the end
  // text is the string to be added

  list = NULL;  
  // list is empty for now, but we will add to it
  
  text = strdup(text); 
  // strdup function duplicates the string

  ll_text *element = malloc(sizeof(ll_text)); 
  // malloc allocates heap memory

  element -> next = list; 
  // assigns the next element to the list

  element -> text = text;
  // assign the text to the new element

  list = element; 
  // here, we're adding the assigned element to the list

  return list;
  // return the list

}

void save_to_file(ll_text *list, const char *filename) {
  FILE *outfile = fopen(filename, "w");
  for (ll_text *here = list; here; here = here->next) {
    fprintf(outfile, "%s\n", here->text);
  }
  fclose(outfile);
}

int ll_text_length(ll_text *list) { 
  // returns the number of lines in the linked list

  int text_length = 0; 
  // starts incrementing from 0 to get our length

  for (ll_text *here = list; here; here = here->next) { 
    // we go through our linked list and increment text_length for each line

    text_length++; 
    // increment text_length

  }

  return text_length;
  // return the final length

}

// insert a specific line: add to specific place in the linked list; this is the
// new entry at the specified line

ll_text *insert_text(ll_text *list, char *text, int position) { 
  // position is the line number
  // text is the string to be added
  // list is the head of the linked list (what we're adding to)
  // set list to NULL to start
  // set text to a duplicate of the string
  // here, what we want to return is the resulting linked list

  list = NULL;
  // list is empty for now, but we will add to it

  text = strdup(text); 
  // duplicate the string like in append_text

  int line_number = position;
  // line_number is the position of the line we want to add

  return list;
}

// delete a specific line: delete the entry in the linked list and return
// the new front of the linked list.

ll_text *delete_text(ll_text *list, int position) { 
  // position is the line number
  // list is the head of the linked list (what we're adding to)
  // set list to NULL to start
  // here, what we want to return is the resulting linked list

  UNUSED(list);
  UNUSED(position);
  return NULL;
}

// replace a line: go to the specific entry, free the text that's there, replace
// it with a copy of the specified text.

ll_text *replace_text(ll_text *list, char *text, int position) { 
  // position is the line number
  // text is the string to be added
  // list is the head of the linked list (what we're adding to)
  // again, set list to NULL
  // set text to a duplicate of the string
  // return resulting linked list (list)

  UNUSED(list);
  UNUSED(text);
  UNUSED(position);
  return NULL;
}

// duplicate a list. Returns a copy of the list, including newly copied versions
// of all of the strings.
ll_text *duplicate_ll_text(ll_text *list) {
  // list is the head of the linked list (what we're adding to)
  // again, set list to NULL at the beginning
  // return the resulting linked list (list)

  list = NULL;
  strdup(list);
  return list;
}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
  ll_text *lines = NULL;
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  char buf[1024];
  FILE *infile = fopen(filename, "r");
  while (fgets(buf, 1024, infile)) {
    chomp(buf);
    lines = append_text(lines, buf);
  }
  stack->lines = lines;
  return stack;
}

ll_text_stack *new_stack_empty_text(void) {
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = NULL;
  return stack;
}

// Push a new state onto the stack that's an exact copy of the state currently
// at the top.
ll_text_stack *push_duplicate(ll_text_stack *stack) {
  // stack is the stack we're adding to
  // we want to return the resulting stack

  UNUSED(stack);
  return stack;
}

// Push a new entry onto the stack that has an empty ll_text at the top.

ll_text_stack *push_empty(ll_text_stack *stack) {
  // again, we're adding to and returning our resultant stack

  UNUSED(stack);
  return stack;
}

// undo, removing the most recent state
// this has to free all the memory associated with that state
ll_text_stack *pop_stack(ll_text_stack *stack) {
  // stack is the stack we're adding to
  // might i repeat myself? 
  // just look at what i did above to find out what we're returning

  UNUSED(stack);
  return stack;
}

// Find the first newline in the input and replace it with \0
void chomp(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] == '\n' || s[i] == '\r') {
      // Check for \r in case we're on Windows or a very old Mac??
      // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.
      s[i] = '\0';
      break;
    }
  }
}
