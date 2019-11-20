#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int parsArgs (int argc, char ** argv, int * mode){
  if (argc == 1 || argc > 3) return -1;
  if (mode == NULL) return -1;
  int i = 1;
    while (argv[i]) {
	if (strcmp (argv[i], "-encrypt") == 0) {
	    *mode = 0;
	  }
	  if(strcmp (argv[i], "-decrypt") == 0){
	      *mode = 1;
	    }
	    
	  i++;
      }
  return 0;
}
void printusage(void){
  printf ("usage: ./hide < -encrypt or -w or -h-decrypt > \n Type into standard in,  then type c-d to finish \n");
  return;
}
int main (int argc, char * argv []){
  char c;
  int mode = 0;
  int err;
  int sh;
  err = parsArgs (argc, argv, &mode);
    if (err){
      printusage();
      return -1;
    }
  while (scanf ("%c", &c) != EOF){
    //decryption
    if ( mode == 1 && c >= 'A' && c <= 'z'){
      sh = -4;
      c = 'a' + (((c -'a') + sh) %26);
    }
    if ( mode == 0 && c >= 'A' && c <= 'z'){
      sh = 4;
      c = 'a' + (((c -'a') + sh) %26);
    }
    
  printf ("%c", c);
}
return 0;
}
  

