#include <stdio.h>
#include <stdlib.h>

#include "llist.h"


typedef struct _node node;

struct _node {
  node * next;
  void * e;
};

static node * newNode(void * e) {
  node * n  = malloc(sizeof(node));
  if (!n) return NULL;
  n->next = NULL;
  n->e = e;
  return n;
}

static void deleteNode(node * n) {
  free(n);
}

struct _llist {
  node * head;
};

llist * newLList(void) {
  llist * ll = malloc(sizeof(llist));
  if (!ll) return NULL;
  ll->head = NULL;
  return ll;
}

void deleteLList(llist * ll) {
  if (!ll) return;
  node * n = ll->head;
  while (n) {
    node * next = n->next;
    deleteNode(n);
    n = next;
  }
  free(ll);
}

int isEmptyLList(llist const * ll) {
  if (!ll) return 0;
  return(ll->head == NULL);
}

int putLList(llist * ll, void * e) {
  node * n;
  if (!ll) return -1;
  n = newNode(e);
  if (!n) return -1;
  n->next = ll->head;
  ll->head = n;
  return 0;
}

int getLList(llist * ll, void ** e) {
  node * n;
  if (!ll || !e) return -1;
  if (ll->head == NULL) {
    *e = NULL;
    return -2;
  }
  n = ll->head;
  *e = n->e;
  ll->head = n->next;
  deleteNode(n);
  return 0;
}

int peekLList(llist const * ll, void ** e) {
  if (!ll || !e) return -1;
  if (ll->head == NULL) {
    *e = NULL;
    return -2;
  }
  *e = ll->head->e; /* write element */
  return 0;
}

int printLList(llist const * ll, printFn f) {
  node * n;
  int cnt;
  if (!ll || !f) return -1;

  cnt = 0;
  for (n = ll->head; n != NULL; n = n->next) {
    cnt++;
    printf(" %d:", cnt);
    f(n->e);
  }
  printf("\n");
  return 0;
}

int zip(llist * ll1, llist * ll2, llist * ll3) {
  node * curNode = NULL;
    if (!ll1 || !ll2 || !ll3) return -1;      //check for NULL pointers
    if (ll3->head!=NULL || ll3 ==ll2 || ll3 == ll1) return -1;
    
    while (ll1 -> head && ll2 -> head){
      if (!curNode){
      ll3->head = ll1-> head= curNode;
      ll1-> head = ll1->head ->next; }
      else{
	curNode -> next = ll1 ->head;
	curNode = curNode -> next;
	ll1 ->head= ll1->head->next;
      }
	curNode-> next = ll2 -> head;
	curNode = curNode -> next;
	ll2 -> head = ll2 -> head -> next;
      }
      if (ll1->head) {
	if (!curNode)
	  ll3 -> head =ll1 -> head;
	else {
	  curNode -> next = ll1 -> head;
	}
	ll1 -> head = NULL;
      }
      else if (ll2->head) {
	if (!curNode)
	  ll3 -> head =ll2 -> head;
	else {
	  curNode -> next = ll2 -> head;
	 	}
	ll2 -> head = NULL;
      }
      return 0;
}
