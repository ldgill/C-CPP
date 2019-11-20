#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lifo.h"

typedef struct _node {
  /* A struct named node is created this struct is a variable that contains a
 group of other variables
  */
  struct _node * next;
  /* A pointer struct named next which is different from a normal struct is
  created and it points to the struct called node
*/
  void * e;
  //A void pointer named e is created that holds nothing or garbage
} node;
// This whole struct is renamed node for easier use
static node * newNode(void * e) {
  /*memory does not move and a new function names NewNode is created that 
passed the empty voided poinetr e and this newNode function becomes a pointer 
struct that points to the original struct of node.
  */
  node * n  = malloc(sizeof(node));
  /* The memory or bits of the struct or variables in the struct of node are
 sized and the a area of memory is allocated or reserved to hold the size of all
 the memory of the variables in the node struct and this memory space is pointed
 to a varable named n. n shows the way to the memory space of the struct n.
  */
  if (!n) return NULL;
  /* if the allocated memory of the struct node is NULL or empty then the 
function  newNode will return garbage but is it has something then the 
function will ignore this line and move on.
  */
  n->next = NULL;
  /* if the last line is false then it is ignored and the struct pointer n 
which points to the allocated memory of the struct node will also point to 
the struct pointer next that then is assigned an empty value of NULL
  */
  n->e = e;
  /* Additionally the struct pointer n will point to the empty pointer named e 
and assign it the value of e which will keep it as nothing or void
  */
  return n;
  /*Now return the entire struct pointer along with everything the struct 
points to
  */ 
}

static void deleteNode(node * n) {
  /*hold the memory of the empty function named deleteNode that holds the
  struct pointer n that points to the allocated memory of the struct node
  */
  free(n);
  /* free all of the memory that the struct pointer n is pointing to and let 
it roam free
  */
}

struct _lifo {  //New Struct names lifo
  int capacity;   // Variable named Capacity
  int size;       // Number varibale named size
  node * head;   // struct pointer named head that points to the node struct 
};

lifo * newLifo(int capacity) {   /* Function named newLifo that holds the
                                    variable named capacity and this function
                                    points to the lifo struct
				  */
  lifo * q = malloc(sizeof(lifo)); /*Allocated memory of lifo struct and new 
                                     struct pointer created named q which point
                                     to the allocated mem of lifo struct
				   */ 
  if (!q) return NULL;               /* if struct pointer q is null newLifo
                                       function returns null */
  if (capacity <= 0) capacity = -1;  // capcity is assigned negatve number to indicate it is unbounded also a sign of an error code
  q->capacity = capacity;            /* q struct pointer points to the capacity
                                        variable which remains at it's value*/ 
  q->size = 0;                     // q points to size which is assigned to 0
  q->head = NULL;                 // q points to head which is assigned to NULL
  return q;                     // Return the pointer  value points to
}

void deleteLifo(lifo * q) {      /*Create a voided function named deleteLifo 
                                 which holds the value of the struct pointer q
                                 as it points to lifo*/
  if (!q) return;                // if q is NULL return NULL

  
  node * n = q->head;        /*?? struct pointer n that points to the allocated mem of node is assigned the 
                                   beginning values of the struct pointer of q which is the
                                 beginning of the pancake lifo stack
				*/
  while (n) {               // when n struct pointer is anything but NULL then the pointer n will execute a while loop
    node * next = n->next; /* the struct pointer n will go to the next value in the struct stack
			    */
    deleteNode(n);         // mem that n is pointing to gets deleted
    n = next;             //  pointer n is assigned the next mem value or whatever next is and goes back to top of while loop
  }
  free(q);               // Free memory held by q struct pointer
}
                                   //The function isEMptyLifo checks to make sure the struct pointer q which points to the lifo struct is
                                   //  empty which means it should point to null.
int isEmptyLifo(lifo const * q) { /* New number variable function called isEmptyLifo whch checks to make sure the lifo struct empty/zero
                                    that holds a constant unchanging struct
                                    pointer named q that points to the allocated
                                    memory of the lifo struct
                                   */
  if (!q) return 1;              // if q is null return el numero 1
  return(q->size == 0);        // if size ==0 the q returns 
}

int putLifo(lifo * q, void * e) {  //Int function putLifo that holds struct pointer q and e so it is passing in members of the lifo struct and node struct
  node * n;                      // Declaring a new pointer n to a struct, node  which is only avaliable to the putLIfo function and n 
  if (!q) return -1;             // if q is null the the lifo struct is empty so return -1
  if (q->size == q->capacity) return -1;   /* if the value of the pointer q as it points to size equals the value of the pointer q as it points to capacity then
                                              the lifo struct is full and so return  -1*/
  n = newNode(e);                       // n is pointing to a new node in the lifo struct
  n -> next = q->head;                  // the new node n points to the  next node which becomes the head of the q pointer struct lifo
  q->head =n;                            // the q points to the head which holds the value of n now whihc is a new node
  q->size++;                            // the size of lifo is now incremented by one
  return 0;
  } 

int getLifo(lifo * q, void ** e) {              // in function get lifo is created that holds the struct pointer q of lifo and void pointer of the pointer e
  node * n;
  if (!q || !e) return -1;                     // if q and e are null
  if (isEmptyLifo(q)) {             /* if there is  nothing to get of the function EmptyLifo is true */
    *e = NULL;                     //pointer e is null
    return -2;
  }
  assert(q->head);         /* should not be  empty else something is wrong with le code */
  n = q->head;           // if n goes to the head of the strut pointer that goes to the head of the struct
  *e = n->e;             /* write element */
  if (q->size == 1) {      // struct pointer q points to the size which equals 1  
    assert(!n->next);       /* n should have no successor */
  }
                           /* Set the head to n's successor. */
  q->head = n->next;        /* Set the pointer as it points to the head of the struct to the value of next */
  deleteNode(n);           // free the mem n holds
  q->size--;              // size decreases by one
  return 0;
}

int sizeLifo(lifo const * q) {   /*new function sizeLifo that whch checks to make sure the lifo struct empty/zero
                                    that holds a constant unchanging struct
                                    pointer named q that points to the allocated
                                    memory of the lifo struct
                                   */
  return q->size;            //return value of size
}

int printLifo(lifo const * q, printFn f) { /*new function printLifo that whch checks to make sure the lifo struct empty/zero
                                    that holds a constant unchanging struct
                                    pointer named q that points to the allocated
                                    memory of the lifo structalong with a ???????
                                   */
  node * n;
  int cnt;
  if (!q || !f) return -1;

  cnt = 0;
  for (n = q->head; n!= NULL; n = n->next) {    /* Print the index of the element. */
    cnt++;
    printf(" %d:", cnt);   /* Call user-provided f to print the element. */
    f(n->e);                 // ?????
  }
  printf("\n");             //print newline
  assert(cnt == q->size);   // guarentee that cnt equals the value of size

  return 0;
}
