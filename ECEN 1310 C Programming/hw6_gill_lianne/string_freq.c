#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printDistribution( int * frequency){
  int i;
  for (i=1; i<31; i++){
    printf ("Frequency of %d charcter long word is %d\n", i, frequency[i]);
  }
  printf ("Thr frequency of 32 or more character words is %d\n", frequency[31]);
}
int main(void) {
  int freq [32] ={0};
  int count = 0;
  char c;
  while (scanf ("%c" , &c) != EOF) {
    if (isspace(c)) {
      if (count !=0){
	if (count >31)
	  freq[32]++;
	else{
	  freq[count]++;
	  count = 0;
	}
    }
   }
    count++;
    }
  printDistribution (freq);
  return 0;
}
