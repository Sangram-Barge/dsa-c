#include "dynamicarray.c"
#include <stdio.h>
#include <string.h>

int getIdentifier(char *s);
void dynamicArrayTest();

int main(int argc, char *argv[]) {
  if (argc < 2)
    error("%s too few arguments", argv[0]);
  for (int i = 1; i < argc; i++)
    switch (getIdentifier(argv[i])) {
    case 0:
      dynamicArrayTest();
    }
}

void dynamicArrayTest() {
  struct Array my_array = init(2);
  add(my_array, 2);
  add(my_array, 1);
  for (int i = 0; i < my_array.length; i++)
    fprintf(stdout, "idx : %d val : %d\n", i, get(my_array, i));
}

int getIdentifier(char *s) {
  if (!strcmp(s, "dynamicarray"))
    return 0;
  return -1;
}
