#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

struct _lifo{
  unsigned capacity;
  unsigned top;
  void * data[1];
};

lifo *newLifo(int capacity){
  lifo *q;
  if (capacity <=0)
    return NULL;
  q =malloc(sizeof(lifo)+sizeof(void *)*(capacity -1));
  q-> capacity = (unsigned)capacity;
  q-> top =0;
  return q;
}
  void deleteLifo(lifo * q) {
  free(q);
}
  int isEmptyLifo (lifo const * q){
    return q->top ==0;
  }
int putLifo(lifo *q, void*e){
  if(!q) return -1;
  if (q-> capacity == q->top)
    return -1;
  q->data[q->top] =e;
  q->top++;
  return 0;
}
int getLifo (lifo *q, void **e){
  if(!q) return -1;
  if (!e) return -1;
  if (isEmptyLifo(q)){
    *e =NULL;
    return -2;
  }
  q->top--;
  *e = q->data[q->top];
  return 0;
}
int sizeLifo(lifo const *q){
  return (int) q->top;
}
int printLifo(lifo const *q, printFn f){
  unsigned i, cnt;
  if (!q) return -1;
  if (!f) return -1;
  cnt = 1;
  for(i =0; i< q->top; i++){
    printf ("%d:", cnt);
    f(q->data[i]);
    cnt++;
  }
  printf("\n");
  return 0;
}
