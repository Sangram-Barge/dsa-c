#include "doubly_linked_list.c"
#include "dynamicarray.c"
#include <stdio.h>
#include <string.h>

int getIdentifier(char *s);
void dynamicArrayTest();
void stackTest();
void linkedListTest();

int main(int argc, char *argv[]) {
  if (argc < 2)
    error("%s too few argument", argv[0]);

  switch (getIdentifier(argv[1])) {
    printf("%s \n", argv[1]);
  case 0:
    fprintf(stdout, "test\n");
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

void stackTest() {}

void linkedListTest() {
  ll_add(1);
  ll_add_first(2);
  ll_add_first(2);
  ll_add_first(2);
  ll_add_first(2);
  ll_add_first(2);
  ll_add_last(9);
  ll_print();
}

int getIdentifier(char *s) {
  char *tests[] = {"tests", "dynamicarray", "linkedlist", "stack"};
  int n = 0, tests_count = 3;
  if (!strcmp(s, "tests"))
    while (n <= tests_count)
      fprintf(stdout, "%s\n", tests[n++]);
  for (n = 0; n <= tests_count; n++)
    if (!strcmp(s, *(tests + n)))
      return n;
  return -1;
}
