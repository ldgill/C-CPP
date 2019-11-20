#include <stdio.h>
#include <assert.h>

int multipleof3(int n){
  if (n%3 == 0){
  printf ("%d\n", n);
  return 1;
  }
  return 0;
}

int main(void){
  int rv;
  rv = multipleof3(9);
  assert (rv);
  rv = multipleof3(32);
  assert (!rv);
  rv = multipleof3(300);
  assert (rv);
  rv = multipleof3(112);
  assert (!rv);
  return 1;
}
