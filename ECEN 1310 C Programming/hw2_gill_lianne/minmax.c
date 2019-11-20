#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int minmax (int a, int b, int *min, int *max)
{
  if (min == NULL || max == NULL){
      printf ("passed NULL pointer");
      return -1;
  }
  if (a >= b){
  *max = a;
  *min = b;
  printf ("%d %d\n", *min, *max);
 }
 else {
   *min = a;
   *max = b;
   printf ("%d %d\n", *min, *max);
 }
  return 0;
}    
int main(void){
  int minM, maxM, err;
  err = minmax(2, 3, &minM, &maxM);
  assert (minM == 2);
  assert (maxM == 3);
  assert (!err);
  err = minmax(2, 2, &minM, &maxM);
  assert (minM == 2);
  assert (maxM == 2);
  assert (!err);
  err = minmax(-5, -10, &minM, &maxM);
  assert (minM == -10);
  assert (maxM == -5);
  assert (!err);
  return 0;
}
