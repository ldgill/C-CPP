#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void) {
  int word=0, letter=0, flag=1;
  char c;
  while (scanf ("%c" , &c) != EOF) {
    if (isspace(c)&& flag == 1) {
      word++;
      flag = 0;
    }
    else if (isspace(c)==0) {
      letter++;
      flag = 1;
    }
  }
  if (word == 0) return -1;
  int mean = letter/word;
  printf ("%d\n", mean);
  return 0;
}
