#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int suffix (char * str, char *suf){
  if (!str || !suf)
    return 0;
  int i;
  for (i=0; str[i]; i++)
    if (str[i] != suf [i])
      return 0;
  return 1;
}
int main() {
  char rv[] = "Sleep";
  char suf[] = "y";
  printf ( "%s %s\n", rv, suf);
  return 0;
}
