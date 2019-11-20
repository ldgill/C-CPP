#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int copyStringN(char * in, char *out, int n){
  if (!in || !out)
    return -1;
  int i;
  for (i=0; i<n; i++) {
    out[i] = in[i];
    if (i ==  n)
      return -2;
  }
  out [i+1] = '\0';
  return 0;
}
int main() {
  char rv[] = "I'm so sleepy ";
  char out [128];
  printf ("%s\n", rv);
  copyStringN (rv, out, 24);
  printf ("%s\n", out);
  return 0;
}
