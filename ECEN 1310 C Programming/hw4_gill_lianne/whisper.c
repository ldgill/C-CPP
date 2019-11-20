#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int whisper( char *  msgIn, char * msgOut){
  if (!msgIn || !msgOut)
    return -1;
  int i;
  for (i=0; msgIn [i]; i++){
    if ( 'A' <= msgIn [i] && msgIn[i]<= 'Z')
      msgOut [i] = msgIn [i] - ('A'- 'a');
    else
      msgOut [i] = msgIn [i];
  }
  return 0;
}
int main() {
   char msg [] = " WHY no SlEEp";
   char out [13];
  int err = whisper(msg, out);
  assert (!err);
  printf ("%s %s\n", msg, out);
  return 0;
}
