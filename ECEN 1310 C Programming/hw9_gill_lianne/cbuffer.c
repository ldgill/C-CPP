#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

struct _fifo {
  unsigned capacity;
  unsigned head;
  unsigned tail;
  void * data[1];
};

fifo * newFifo(int capacity) {
  fifo * q;
  if (capacity < 1) return NULL;

  /* The capacity of a circular buffer is one less than
   * one would think: if the user wants a given
   * capacity, the required array is one cell larger.
   */
  capacity++;

  /* allocate one chunk of memory */
  q = malloc(sizeof(fifo) +
             (capacity-1) * sizeof(void *));
  if (!q) return NULL;
  q->capacity = (unsigned) capacity;
  q->head = q->tail = 0;
  return q;
}

void deleteFifo(fifo * q) {
  free(q);
}

int isEmptyFifo(fifo const * q) {
  if (!q) return 1;
  return q->head == q->tail;
}

int putFifo(fifo * q, void * e) {
  if (!q) return -1;
  if ((q->head+1) % q->capacity == q->tail) /* full? */
    return -1;
  q->data[q->head] = e;
  q->head = (q->head+1) % q->capacity;
  return 0;
}

int getFifo(fifo * q, void ** e) {
  if (!q) return -1;
  if (!e) return -1;
  if (isEmptyFifo(q)) {
    *e = NULL;
    return -2;
  }
  *e = q->data[q->tail];
  q->tail = (q->tail+1) % q->capacity;
  return 0;
}

int sizeFifo(fifo const * q) {
  if (q->head >= q->tail)
    return (int) (q->head - q->tail);
  else
    return (int) (q->capacity - q->tail + q->head); 
}

int printFifo(fifo const * q, printFn f) {
  unsigned i, cnt;
  if (!q) return -1;
  if (!f) return -1;
  cnt = 1;
  for (i = q->tail; i != q->head; i = (i+1) % q->capacity) {
    printf(" %d:", cnt);
    f(q->data[i]);
    cnt++;
  }
  printf("\n");
  return 0;
}
