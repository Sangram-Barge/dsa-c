#include "doubly_linked_list.c"
#include "error.c"
#include <stdio.h>
#include <stdlib.h>

int st_is_empty();         // done
int st_size();             // done
void st_push(int element); // done
int st_pop();              // done
int st_peek();             // done
void st_print();

int st_is_empty() { return ll_len() == 0; }

int st_size() { return ll_len(); }

void st_push(int element) { ll_add_last(element); }

int st_pop() {
  if (st_is_empty())
    error("stack empty", NULL, stderr);
  return ll_remove_last();
}

int st_peek() { return ll_find_last(); }

void st_print() { ll_print(); }
