#include <stdio.h>
#include <stdlib.h>

typedef int bool;
typedef void *item;
//Single linked-list
typedef struct node_{
  item *thing;
  struct node_ *ptr;
}node;

//Double linked-list, which contains two pointers, the head and the tail.
typedef struct dlist_{
  node *head;
  node *tail;
}dlist;

void insert(dlist *this, item *thing, bool atTail);

int main(){
  dlist *dlst = (dlist *) malloc(sizeof(dlist *));
  dlist lst = {NULL,NULL};
  
  node *h1;
  node *t1;
  dlist lst2 = {h1, t1};
  *dlst = lst;
  *(dlst+1) = lst2; 
 
  item thing = (int *) 1453;
 // insert(dlst, &thing, 1);
  
  return 0;
}

void insert(dlist *this, item *thing, bool atTail){
  node* new_node = (node*) malloc(sizeof(node*));
  if(atTail == 1){
   (*this).head->ptr = new_node;
    (*(*this).head).thing = thing;
  }
  else{
    (*this).tail = new_node;
    (*(*this).tail).thing = thing;
  }
  free(new_node);
  
  
}
