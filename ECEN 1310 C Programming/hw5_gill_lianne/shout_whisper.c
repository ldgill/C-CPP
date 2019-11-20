#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int parsArgs (int argc, char ** argv, int * mode){
  if (argc == 1 || argc > 3) return -1;
  if (mode == NULL) return -1;
  int i = 1;
    while (argv[i]) {
	if (strcmp (argv[i], "-w") == 0) {
	    *mode = 1;
	  }
	  if(strcmp (argv[i], "-s") == 0){
	      *mode = 0;
	    }
	    if (strcmp (argv[i], "-h") == 0){
		return -1;
	      }
	  i++;
      }
  return 0;
}
void printusage(void){
  printf ("usage: ./shout_whisper < -s or -w or -h > \n Type into standard in,  then type c-d to finish \n");
  return;
}
int main (int argc, char* argv []){
  char letter;
  int mode = 0;
  int err;
  err = parsArgs (argc, argv, &mode);
    if (err){
      printusage();
      return -1;
    }
  while (scanf ("%c", &letter) != EOF){
  if (letter >='a' && letter <='z'&& mode == 0)
    letter = letter - ('a' - 'A');
  else if (letter >='A' && letter <='Z' && mode ==1)
    letter = letter - ('A' - 'a');
  printf ("%c", letter);
}
return 0;
}
  
