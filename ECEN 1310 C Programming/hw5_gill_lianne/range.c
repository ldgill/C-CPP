#include <stdio.h>
void printUsage() {
  printf ("Usage: max < [data file], where the file is" "a list of n intergers\n");
}
int main() {
  int min;
  int max;
  if (scanf ("%d", &min) !=1) {
    printUsage();
    return -1;
  }
  if (scanf ("%d", &max) !=1) {
    printUsage();
    return -1;
  }
  int rc, valmin, valmax;
  while (( rc = scanf ("%d", &valmin)) !=EOF) {
    if (rc == 0) {
      printUsage();
      return -1;
    }
    if (valmin < min)
      min = valmin;
  }
  while (( rc = scanf ("%d", &valmax)) !=EOF) {
    if (rc == 0) {
      printUsage();
      return -1;
    }
    if (valmax > max)
      max = valmax;
  }
  int range;
  range = max - min;

  printf ("Range: %d =  %d - %d\n", range, max, min);
  return 0;
}
