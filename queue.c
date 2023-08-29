#include "doubly_linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int q_size();
int q_isEmpty();
void q_offer(int element);
int q_poll();
int q_peek();

int q_size() { return ll_len(); }

int q_isEmpty() { return is_empty(); }

void q_offer(int element) { ll_add_last(element); }

int q_poll() {
  if (q_isEmpty())
    error("queue is empty\n", NULL, stderr);
  return ll_remove_first();
}

int q_peek() {
  if (q_isEmpty())
    error("queue is empty\n", NULL, stderr);
  return ll_find_first();
}
