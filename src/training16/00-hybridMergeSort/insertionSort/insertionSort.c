/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_INSERTIONSORT_H
#define M_INSERTIONSORT_H
#include "insertionSort.h"
#endif


void insertionSort( int *V, size_t startInd, size_t endInd )
{

    size_t j;
    int i, key;


    /* Sort.  */
    for ( j = startInd + 1; j <= endInd; j++ ) {
        key = V[j];
        i = ( int ) j - 1;

        while ( i >= ( int ) startInd && V[i] > key ) {
            V[i + 1] = V[i];
            i--;
        }

        V[i + 1] = key;
    }

    return;

}
