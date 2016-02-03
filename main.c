#include "liste.h"

#ifndef STDLIB
#define STDLIB
    #include <stdlib.h>
#endif

#ifndef STDIO
#define STDIO
    #include <stdio.h>
#endif

int main ( int argc, char ** argv ) {

    list * l;
    l = NULL;

    l = ( list * ) malloc( sizeof( list ) );
    if ( null( l ) ) {
        fprintf( stderr, "Malloc Failed, call your Mom\n" );
        exit( EXIT_FAILURE );
    }

    l->el = 28;
    l->next = NULL;

    l = cons(10, l);

    l = NULL;
    element e;
    e = car( l );

    printList( l );

    return 0;
}