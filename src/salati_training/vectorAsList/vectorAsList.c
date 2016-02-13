/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "vectorAsList.h"

vector createEmptyVector( void )
{
    vector v = malloc(sizeof(node*));
    *v = NULL;
    return v;
}


vector createInitializedVector( int numEl, element e ){
    vector head;
    int i;

    /* allocate an array of pointer to struct list */
    node *nodes = malloc(numEl * sizeof(node));

    /* allocate one struct for each array element */
    for( i = 0; i<numEl; ++i){
        nodes[i] = malloc( sizeof(struct list));
    }

    /* the head must have the address of the first node */
    head = &(nodes[0]);
    
    /* fix the first node */  
    nodes[0]->next = NULL;
    nodes[0]->el = e;
    
    /* fix other nodes */
    for(i = 1; i<numEl; ++i){
        nodes[i-1]->next = nodes[i];
        nodes[i]->el = e;
        nodes[i]->next = NULL;
    }
    
    return head;
}



int vectorLength( vector v )
{
    int i = 0;
    node thisNode = *v;

    while ( thisNode != NULL ) {
        i++;
        thisNode = thisNode->next;
    }

    return i;
}


element getElementValue( vector v, int index )
{
    int i = 0;
    node thisNode = *v;
    
    assert( *v != NULL );
    assert(index < vectorLength(v));

    while ( thisNode != NULL ) {
        if ( i == index ) {
            return thisNode->el;
        }
        i++;
        thisNode = thisNode->next;
    }
    return 0;
}


vector setElementValue(vector v, int index, element val){
    int i = 0;
    node thisNode = *v;

    assert( *v != NULL );
    assert(index < vectorLength(v));

    while ( thisNode != NULL ) {
        if ( i == index ) {
            thisNode->el = val;
        }
        i++;
        thisNode = thisNode->next;
    }
    return v;
}


vector tailExtendVector(vector v, element e){
    node lastNode = NULL;
    node newNode = NULL;

    newNode = malloc(sizeof(struct list));
    newNode->el = e;
    newNode->next = NULL;

    /* if the vector has no element */
    if( *v == NULL ){
        *v = newNode;
    }
    else{
        /* scann till the last element is reached */
        lastNode = *v;
        while( lastNode->next != NULL ){
            lastNode = lastNode->next;
        }
        /* here i have in lastNode the lastest node */
        /* i have to fix his next pointer */
        lastNode->next = newNode;
    }

    return v;
}


vector tailTrimVector(vector v){
    node lastNode = NULL;
    node preLast = NULL;

    /* must have at least one element */
    assert( *v != NULL );

    /* if there's more than one element */
    if( (*v)->next != NULL ){
        
        /* begin scan */
        preLast = *v;
        lastNode = (*v)->next;
    
        while(lastNode->next != NULL){
            preLast = lastNode;
            lastNode = lastNode->next;
        }
        /* fix preLast pointers, free memory  */
        preLast->next = NULL;
        free(lastNode);
    }
    /* if there's only one element */
    else{
        free(*v);
        *v = NULL;
    }

    return v;
}

/* What we have to do with these? */
/*
vector insertElement(vector v, int index, element e){}

vector removeElement(vector v, int index){}
*/
