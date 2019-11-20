#include <stdio.h>
#include <assert.h>


int smallerabsval(int x, int y){
  if (x < 0){
    x = x * -1;
  }
  if (y < 0){
    y = y * -1;
  }
  if (x > y){
    printf("%d\n", y);
    return y;
  }
  if (x < y){
    printf("%d\n", x);
    return x;
  }
  if (x == -y){
    printf("%d\n", x);
    return x;
  }
  if (-x == y){
    printf("%d\n", y);
    return y;
  }
  if (x == y){
    printf("%d\n", x);
    return x;
  }
  return 0;
}
  
int main(void) {
  int rv;
  rv = smallerabsval(8,-5);
  assert (rv);
  rv = smallerabsval(9,22);
  assert (rv);
  rv = smallerabsval(-3,-72);
  assert (rv);
  rv = smallerabsval(7,7);
  assert (rv);
  return 0;
}
