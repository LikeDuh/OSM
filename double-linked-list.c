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

    struct node *head = NULL;


    return (0);
}


//XOR two pointers(The TA's suggestion)

node* XOR(void* p1, void* p2) {

    return (void*) (((uintptr_t) p1) ^ ((uintptr_t) p2));

}

/* The insert operation
 * 
 */
void insert(dlist *this, item* thing, bool atTail) {

    node* new_node = (node*) malloc(sizeof (node*));

    new_node->thing = thing;

    //in case the list is empty
    if (this == NULL) {

        new_node = XOR(NULL, NULL);

    }

    //insert node in the front
    if (this != NULL && atTail == 0) {

        node* nextNode = XOR(NULL, this->head);
        this->head = XOR(new_node, nextNode);

        //update the head
        this->head = new_node;
    }


    //insert node in the end
    if (this != NULL && atTail == 1) {

        node* previousNode = XOR(this->tail, NULL);
        this->tail = XOR(previousNode, new_node);

        //update the tail
        this->tail = new_node;

    }

    free(new_node);
}

item* extract(dlist *this, bool atTail) {

    //if the list is empty then return nothing
    if (this == NULL) {

        return NULL;
    }

    if (this != NULL && atTail == 0) {


        node* nextNode = XOR(NULL, this->head);

        //updating the nextNode to be the new head
        nextNode = this->head;


        return this->head->thing;


    }

    if (this != NULL && atTail == 1) {

        node* previousNode = XOR(this->tail, NULL);

        //update previousNode to be the new tail
        previousNode = this->tail;

        return this->tail->thing;

    }

}

void reverse(dlist *this) {

    //temporary place holder to assignment head to tail and reverse
    node* temp = this->head;
    this->head = this->tail;
    this->tail = temp;

}

item* search(dlist *this, bool(*matches)(item*)) {

    node* currNode = this->head;
    node* prevNode = NULL;

    while (currNode != NULL) {
        if (matches(currNode->thing)) {

            return currNode->thing;
        }
        node* temp = currNode;
        currNode = XOR(currNode->ptr, prevNode->ptr);
    }
    return NULL;

}

