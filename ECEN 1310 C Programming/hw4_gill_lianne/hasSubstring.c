#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int hasSubstring (char * str, char * substr) {
  if (!str || !substr)
    return 0;
  int i, j;
  if (substr [0] == '\0') return 1;
  for (i=0; str[i]; i++){
    for (j=0; substr[j]; j++){
      if (str[i+j] != substr [j])
	break;
      /* when str [i+j] equals substr [j] keep going and if they do not equal break apart.*/
    }
    if (!substr[j])
      return 1;
  }
  return 0;
}
int main() {
  char str [] = "Hello universe!";
  char sub [] = "lo";
  assert (hasSubstring ("Hello universe!", "lo"));
  assert (hasSubstring ("Hello universe!", "verse"));
  assert (hasSubstring ("Hello universe!", ""));
  assert (hasSubstring ("", ""));
  assert (!hasSubstring ("Hello universe!", "verses"));
  assert (!hasSubstring ("Hello universe!", "loun"));
  assert (!hasSubstring ("Hello universe!", "erse!!"));
  printf ("%s %s\n", str, sub);
  return 0;
}
