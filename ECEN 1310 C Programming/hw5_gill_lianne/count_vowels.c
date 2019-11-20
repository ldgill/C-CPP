#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main (){
  int rc, cntaA= 0, cnteE= 0, cntiI= 0, cntoO=0, cntuU=0;
  char c;
  while((rc= scanf("%c", &c)) != EOF) {
    if (c == 'a' || c == 'A') {
      cntaA = cntaA + 1;
    }
    if (c == 'e' || c == 'E') {
      cnteE = cnteE + 1;
    }
    if (c == 'i' || c == 'I') {
      cntiI = cntiI + 1;
    }
    if (c == 'o' || c == 'O') {
      cntoO = cntoO + 1;
    }
    if (c == 'u' || c == 'U') {
      cntuU = cntuU + 1;
    }
  }
  printf ("Vowel count :\n a or A: %d\n e or E: %d\n i or I: %d\n o or O: %d\n u or U: %d\n", cntaA, cnteE, cntiI, cntoO, cntuU);
  return 0;
}
