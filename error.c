#include <stdio.h>
#include <stdlib.h>

void error(char *s1, char *s2, FILE *e);
#ifndef ERR
#define ERR
void error(char *s1, char *s2, FILE *e) {
  fprintf(e, s1, s2);
  exit(1);
}
#endif /* ifndef :ERR */
