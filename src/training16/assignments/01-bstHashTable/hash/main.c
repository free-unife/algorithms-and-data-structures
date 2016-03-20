/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_MAINHASH_H
#define M_MAINHASH_H
#include "main.h"
#endif


int main (void)
{

    char *string;
    size_t key;
    bstPointer *hashTable;


    hashTable = initHashTable();
    while (true)
    {
        if ( ( string = calloc( 500, sizeof( char ) ) ) == NULL )
            exit( EXIT_FAILURE );

        printf ("%p\n", (void *)string );
        fprintf (stdout, "Value to be hashed (^C to quit): ");
        scanf ("%s", string);

        key = hash (string);

        hashTable[key] = string;
        printf ("key = %u\n", (unsigned int) key);

        printf ("Hash table status: ");
        printHashTable (hashTable);

/*        free (string);*/
    }

    return 0;

}

