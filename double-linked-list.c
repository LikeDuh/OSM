/* 
 * File:   main.c
 * Author: superman
 *
 * Created on 8. februar 2014, 21:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "doublelink.h"




//Main function

int main(int argc, char** argv) {


    return (0);
}

//XOR two pointers(The TA's suggestion)

node* XOR(void* p1, void* p2) {
    
    (void*) (((uintptr_t) p1) ^ ((uintptr_t) p2));

}

/* The insert operation
 * 
 */
void insert(dlist *this, item* thing, bool atTail) {

    node* new_node = (node*) malloc(sizeof (node*));

    new_node->thing = thing;
    new_node->ptr = (*this->head, NULL);

    XOR(this->head, NULL);  //previous node
    XOR(NULL, this->tail);  //next node
    
    //insert node in the end
    if (this != NULL && atTail == 1) {

        this->head = XOR(NULL, new_node);
        

    }
    
    //insert node in the front
    if (this != NULL && atTail == 0) {

        this->tail = XOR(new_node, NULL);
        
     }
    

    free(new_node);
}
