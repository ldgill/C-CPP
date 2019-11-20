#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int vectorSum (int x[], int y[], int n, int sum[]){
  if (x == NULL || y== NULL || sum == NULL)
    return -1;
  if (n <= 0)
    return -2;
  int i;
  for (i = 0; i < n; i++)
    sum[i] = x[i] + y [i];
  return 0;
}
int main(){
  char x[] = {1,2,5,3};
  char y[] = {2,4,3,5};
  char sum[4];
  printf ("%s +  %s =  %s\n",  x,y,sum);
  return 0;
}
