#include <stdio.h>
#include <stdlib.h>

int ll_add(int element);
int ll_add_last(int element);
int ll_add_first(int element);
int ll_remove_first();
int ll_remove_last();
int ll_add_index(int index, int element);
int ll_remove_index(int index);
int ll_contains(int element);
int len();
int is_empty();

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
int size = 0;

int ll_add_first(int element) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = element;
  temp->prev = NULL;
  if (is_empty()) {
    temp->next = NULL;
    head = tail = temp;
  } else {
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  size++;
  return head->data;
}

int ll_add_last(int element) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = element;
  temp->next = NULL;
  if (is_empty()) {
    temp->prev = NULL;
    head = tail = temp;
  } else {
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }
  size++;
  return tail->data;
}

int ll_add(int element) { return ll_add_last(element); }

int is_empty() { return size == 0; }

void ll_print() {
  struct node *trav = head;
  while (trav != NULL) {
    fprintf(stdout, "%d \n", trav->data);
    trav = trav->next;
  }
}

int len() { return size; }
