#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int _product( int  n, int  *s){
  int i =1;
  if (n <= 0 || s == NULL)
    return -1;
  *s = 1;
  for (i = 1; i <= n; i++){
  *s *= i;
}
return 0;
}
int main() {
  int s, err;
  err = _product(5, &s);
  assert (err == 0);
  printf ("%d\n", s);
  return 0;
}
