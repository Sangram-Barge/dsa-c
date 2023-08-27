#include "error.c"
#include <stdio.h>
#include <stdlib.h>

#ifndef LL
#define LL
int ll_add(int element);                  // done
int ll_add_last(int element);             // done
int ll_add_first(int element);            // done
int ll_remove_first();                    // done
int ll_remove_last();                     // done
int ll_add_index(int index, int element); // done
int ll_remove_index(int index);           // done
int ll_contains(int element);             // done
int ll_len();                             // done
int is_empty();                           // done
int ll_find_first();
int ll_find_last();
struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;

struct node *tail = NULL;

int size = 0;

int ll_contains(int element) {
  if (head->data == element)
    return 1;
  struct node *trav = head;
  while ((trav = trav->next) != NULL)
    if (trav->data == element)
      return 1;
  return 0;
}

int ll_find_first() {
  if (is_empty())
    error("empty list\n", NULL, stderr);
  return head->data;
}

int ll_find_last() {
  if (is_empty())
    error("empty list\n", NULL, stderr);
  return tail->data;
}

int ll_add_index(int index, int element) {
  if (index < 0 || index > ll_len() - 1)
    error("index out of bounds\n", NULL, stderr);
  if (index == 0)
    return ll_add_first(element);
  else if (index == size - 1)
    return ll_add_last(element);
  struct node *temp = (struct node *)malloc(sizeof(struct node)), *trav = head;
  temp->data = element;
  int i = 0;
  while (i++ < index)
    trav = trav->next;
  temp->next = trav;
  temp->prev = trav->prev;
  temp->prev->next = temp;
  temp->next->prev = temp;
  size++;
  return element;
}

int ll_remove_index(int index) {
  if (index < 0 || index > ll_len() - 1)
    error("index out of bounds\n", NULL, stderr);
  if (index == 0)
    return ll_remove_first();
  else if (index == ll_len() - 1)
    return ll_remove_last();
  struct node *trav = head;
  int i = 0;
  while (i++ < index)
    trav = trav->next;
  int data = trav->data;
  trav->prev->next = trav->next;
  trav->next->prev = trav->prev;
  free(trav);
  size--;
  return data;
}

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

int ll_remove_first() {
  if (is_empty())
    error("operation: %s, list empty\n", "remove first", stderr);
  int data = head->data;
  struct node *remove = head;
  size--;
  if (is_empty())
    head = tail = NULL;
  else {
    head = head->next;
    head->prev = NULL;
  }
  free(remove);
  return data;
}

int ll_remove_last() {
  if (is_empty())
    error("operation: %s, list empty\n", "remove last", stderr);
  int data = tail->data;
  struct node *remove = tail;
  size--;
  if (is_empty())
    head = tail = NULL;
  else {
    tail = tail->prev;
    tail->next = NULL;
  }
  free(remove);
  return data;
}

int ll_add(int element) { return ll_add_last(element); }

int is_empty() { return size == 0; }

void ll_print() {
  if (head == NULL)
    fprintf(stderr, "empty list\n");
  struct node *trav = head;
  while (trav != NULL) {
    fprintf(stdout, "%d \n", trav->data);
    trav = trav->next;
  }
}

int ll_len() { return size; }
#endif /* ifndef LL */
