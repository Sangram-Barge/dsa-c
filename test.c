#include "binarysearch.c"
#include "doubly_linked_list.c"
#include "dynamicarray.c"
#include "error.c"
#include "queue.c"
#include "stack.c"
#include <stdio.h>
#include <string.h>

int len(int arr[]);
int getIdentifier(char *s);
void dynamicArrayTest();
void stackTest();
void linkedListTest();
void queueTest();
void binarySearchTest();

int main(int argc, char *argv[]) {
  if (argc < 2)
    error("%s too few argument", argv[0], stderr);

  switch (getIdentifier(argv[1])) {
    printf("%s \n", argv[1]);
  case 0:
    break;
  case 1:
    dynamicArrayTest();
    break;
  case 2:
    linkedListTest();
    break;
  case 3:
    stackTest();
    break;
  case 4:
    queueTest();
    break;
  case 5:
    binarySearchTest();
    break;
  default:
    fprintf(stderr, "invlid argument %s\n", argv[0]);
  }
}

void dynamicArrayTest() {
  struct Array my_array = init(2);
  add(my_array, 2);
  add(my_array, 1);
  for (int i = 0; i < my_array.length; i++)
    fprintf(stdout, "idx : %d val : %d\n", i, get(my_array, i));
}

void queueTest() {
  q_offer(2);
  q_offer(3);
  q_offer(8);
  fprintf(stdout, "size %d\n", q_size());
}

void stackTest() {
  st_push(1);
  st_push(3);
  st_print();
  st_push(8);
  st_push(10);
  st_push(24);
  st_push(99);
  st_print();
  fprintf(stdout, "peek %d\n", st_peek());
  st_pop();
  st_pop();
  fprintf(stdout, "pop %d\n", st_pop());
}

void linkedListTest() {
  ll_add(1);
  ll_add_first(5);
  ll_add_last(9);
  ll_print();
  ll_remove_first();
  fprintf(stdout, "after remove first\n");
  ll_print();
  ll_remove_last();
  fprintf(stdout, "after remove last\n");
  ll_print();
  printf("len %d\n", ll_len());
  ll_remove_last();
  printf("len %d\n", ll_len());
  fprintf(stdout, "after remove last empty list\n");
  ll_print();
  fprintf(stdout, "----------testing add index----------\n");
  ll_add_first(0);
  ll_add_first(1);
  ll_add_first(2);
  ll_add_first(3);
  ll_add_first(4);
  ll_add_index(1, 100);
  ll_print();
  fprintf(stdout, "----------testing remove index 0----------\n");
  ll_remove_index(0);
  ll_print();
  fprintf(stdout, "----------testing remove index last----------\n");
  ll_remove_index(ll_len() - 1);
  ll_print();
  fprintf(stdout, "----------testing remove index 2----------\n");
  ll_remove_index(2);
  ll_print();
  fprintf(stdout, "----------testing contains----------\n");
  int d = 100;
  fprintf(stdout, "list %scontains %d\n", ll_contains(d) ? "" : "does not ", d);
}

int getIdentifier(char *s) {
  char *tests[] = {"tests", "dynamicarray", "linkedlist",
                   "stack", "queue",        "binarys"};
  int n = 0, tests_count = 5;
  if (!strcmp(s, "tests"))
    while (n <= tests_count)
      fprintf(stdout, "%s\n", tests[n++]);
  for (n = 0; n <= tests_count; n++)
    if (!strcmp(s, *(tests + n)))
      return n;
  return -1;
}

void binarySearchTest() {
  fprintf(stdout, "binary search\n");
  int arr[] = {1, 3, 6, 8, 9, 10, 14, 29, 54, 100, 374, 533};
  int length = sizeof(arr) / sizeof(int);
  fprintf(stdout, "array length %d\n", length);
  int idx = bisearch(arr, 0, length, 10);
  fprintf(stdout, "10 is at %d location\n", idx);
}
