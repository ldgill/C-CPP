#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int numOccur (int a[], int n, int v, int *occ){
  if (!a || !occ)
    return -1;
  if (n<0)
    return -2;
  *occ = 0;
  int i;
  for ( i=0; i<n; i++){
    if (a[i] == v){
      *occ += 1;
    }
  }
  return 0;
}
int main(){
  int rv;
  int occur;
  int a[] = { 3, 4, 5, 3, 4, 3, 2, 1,3};
  rv = numOccur(a, 9, 3, &occur);
  assert (!rv && occur == 4);
  printf("%d\n",occur);
  return 0;
}
