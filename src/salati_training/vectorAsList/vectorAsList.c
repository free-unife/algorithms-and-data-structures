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
    node nprec, tmp;
    node ncurr;
    int i;

    nprec = malloc( sizeof( struct list ) );
    tmp = nprec;
    head = &tmp;

    nprec->el = e;
    nprec->next = NULL;

    for ( i = 0; i < numEl - 1; ++i ) {
        ncurr = malloc( sizeof( struct list ) );
        nprec->next = ncurr;
        ncurr->el = e + ( i + 1 );
        ncurr->next = NULL;
        nprec = ncurr;
    }

    return head;
}


int vectorLength( node head )
{
    int i = 0;
    node no = head;
    printf( "no inside vectorLength %p\n", ( void * ) no );
    while ( no != NULL ) {
        /*printf( "v inside vectorLength %p\n", ( void * ) *v ); */
        printf( "el %d\n", no->el );
        i++;
        no = no->next;
    }

    return i;
}

element getElementValue( vector v, int index )
{
    int i = 0;
    node no = *v;
    printf( "v inside getElement %p\n", ( void * ) *v );

    /*assert( index < vectorLength( v ) ); */
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

/*
vector setElementValue(vector v, int index, element val){

}

vector tailExtendVector(vector v, element e){}

vector tailTrimVector(vector v){}

vector insertElement(vector v, int index, element e){}

vector removeElement(vector v, int index){}
*/
