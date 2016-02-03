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
    l = makeList( 0 );

    

    int i;

    for (i = 1; i< 100; i++){
        l = cons( i, l);
    }
    int len = length( l );
    printList( l );

    printf("Lunghezza: %d\n", len);

    return 0;
}