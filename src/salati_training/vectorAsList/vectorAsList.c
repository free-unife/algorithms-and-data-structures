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

vector createInitializedVector( int numEl, element e )
{
    vector head;
    node headNode, newNode, hn;
    int i = 1;


    assert( numEl > 0 );

    headNode = malloc( sizeof( struct list ) );
    headNode->el = e;
    headNode->next = NULL;

    hn = headNode;

    while ( i < numEl ) {
        newNode = malloc( sizeof( struct list ) );
        newNode->el = e + i;
        hn->next = newNode;
        newNode->next = NULL;
        hn = hn->next;

        i++;
    }

    hn->next = NULL;
    head = &headNode;

    return head;
}




int vectorLength( vector v )
{
    int i = 0;
    node tmpp = ( *( v ) );
    node tmp = ( tmpp );

    printf( "%p\n", ( void * ) tmp );

    while ( tmp != NULL ) {
        printf( "el %d\n", tmp->el );
        i++;
        tmp = tmp->next;
    }

    return i;
}

/*
element getElementValue( vector v, int index )
{
    int i = 0;
    node no = *v;
    printf( "v inside getElement %p\n", ( void * ) *v );

    assert( *v != NULL );

    while ( no != NULL ) {
        if ( i == index ) {
            return no->el;
        }
        i++;
        no = no->next;
    }
    return 0;
}
*/
/*
vector setElementValue(vector v, int index, element val){

}

vector tailExtendVector(vector v, element e){}

vector tailTrimVector(vector v){}

vector insertElement(vector v, int index, element e){}

vector removeElement(vector v, int index){}
*/
