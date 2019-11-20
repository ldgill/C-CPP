#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int power(int a, int n, int *p){
  if (a == -a){
    a *= -1;
  }
  if (n == 0){
    return 1;
  }
  int i;
  *p= a;
  for ( i = 1; i<n; i++) {
    *p= *p *a;
  }
  
  return 0;
}
int main() {
  int x=-5, y=2, pow;
  power(x, y, &pow);
  assert (power!= NULL);
  printf ("%d^%d = %d\n", x, y, pow);
  return 0;
}
