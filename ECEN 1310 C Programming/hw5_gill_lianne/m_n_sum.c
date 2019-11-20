#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) {
  if (argc !=3){
      printf("Wrong not 2. \n");
      return -2;
    }
  int n;
  int m;
    if (sscanf(argv[1], "%d", &m) == 0) {
      printf ("Wrong still no interger .\n");
      return -1;
    }
    if (sscanf(argv[2], "%d", &n) == 0) {
	printf ("Wrong again no interger .\n");
	return -1;
      }
      if (n <= 0) {
	printf ("not positive \n");
	return -1;
      }
      int i, sum =0;
      for (i=m; i<=n; i++)
	sum = sum + i;
      printf ("Sum: %d\n", sum);
      return 0;
      }
