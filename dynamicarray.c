#include <stdio.h>
#include <stdlib.h>

static int *arr_ext;

struct Array {
  int *arr;
  int capacity;
  int length;
};

struct Array init(int s);
static void error(char *s1, char *s2);
void add(struct Array s_array, int val);

struct Array init(int s) {
  struct Array s_array;
  if (s <= 0)
    error("size should be greater than 0", NULL);
  s_array.capacity = s;
  s_array.length = 0;
  if ((s_array.arr = (int *)malloc(s_array.capacity * sizeof(int))) == NULL)
    error("cannot create array of provided size", NULL);
  return s_array;
}

void add(struct Array s_array, int val) {
  if (s_array.length >= s_array.capacity) {
    s_array.capacity *= 2;
    arr_ext = (int *)malloc(s_array.capacity * sizeof(int));
    for (int i = 0; i < s_array.capacity / 2; i++)
      arr_ext[i] = s_array.arr[i];
    free(s_array.arr);
    s_array.arr = arr_ext;
  }
  s_array.arr[s_array.length++] = val;
}

int get(struct Array s_array, int idx) {
  if (idx > s_array.length)
    error("index out of bounds", NULL);
  return *(s_array.arr + idx);
}

static void error(char *s1, char *s2) {
  fprintf(stdout, s1, s2);
  fprintf(stdout, "\n");
  exit(1);
}
