#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int _product(int n) {
  if (n==1) return 1;
  return _product(n-1)*n;
}
int product( int n, int * s) {
  if (n <=0 || s == NULL)
    return -1;
  *s = _product(n);
  return 0;
}
int main () {
  int s, err;
  err = product(5, &s);
  assert (err == 0);
  printf("%d\n", s);
  err = product(-3, &s);
  assert (err != 0);
  return 0;
}
