#include "error.c"
#include <stdio.h>

#define FALSE -1

int bisearch(int arr[], int lo, int hi, int key);

int bisearch(int arr[], int lo, int hi, int key) {
  fprintf(stdout, "lo %d, hi %d, key %d \n", lo, hi, key);
  for (int i = lo; i < hi; i++)
    fprintf(stdout, "idx %d, val %d\n", i, arr[i]);
  do {
    int mid = lo + (hi - lo) / 2;
    int val = arr[mid];
    if (val == key)
      return mid;
    else if (val > key)
      hi = mid;
    else
      lo = mid + 1;
  } while (hi > lo);
  return FALSE;
}
