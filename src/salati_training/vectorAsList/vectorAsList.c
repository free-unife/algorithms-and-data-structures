/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "vectorAsList.h"

vector createEmptyVector( void )
{
    vector v = NULL;
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

/*
vector setElementValue(vector v, int index, element val){

}

vector tailExtendVector(vector v, element e){}

vector tailTrimVector(vector v){}

vector insertElement(vector v, int index, element e){}

vector removeElement(vector v, int index){}
*/
