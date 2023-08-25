#include <stdio.h>
#include <stdlib.h>

#define NULLL
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

int size = 0;
struct Node head;
struct Node tail;

int ladd(int element);
int add_last(int element);
int add_first(int element);
int is_empty();
int contains(int element);
int peek_first();
int peek_last();
int remove_first();
int remove_last();
int remove_index(int index);
int remove_data(int element);
int index_of(int element);
struct Node *create_node(int data);

int ladd(int data) { return add_last(data); }

int add_last(int data) {
  struct Node *n = create_node(data);
  if (is_empty())
    head = tail = *n;
  else {
    tail.next = n;
    tail = *n;
  }
  return data;
}

struct Node *create_node(int element) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->data = element;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

void free_node(struct Node *node) { free(node); }

void print_ll() {
  struct Node trav = head;
  fprintf(stdout, "\n[");
  while (trav != NULL)
    trav = *trav.next;
  fprintf(stdout, "%d ", trav.data);
  fprintf(stdout, "]\n");
}
