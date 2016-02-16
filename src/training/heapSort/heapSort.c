/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "heapSort.h"


/* r = limit of the (sub)array.
 * i = index of a new element to be placed in the correct position.
 */
void sift( int *v, int i, int r )
{

    int j = ( 2 * i ) + 1;
    int tmp;


    if ( j <= r ) {

        printf( "Sifting element v[%d] = %d\n", i, v[i] );

        assert( j > i );

        if ( ( j < r ) && ( v[j] > v[j + 1] ) )
            j++;

        assert( ( j > i ) && ( j <= r ) );

        /* Exchange v[i] and v[(2 * i) + x].
         * Since j > i, i represents an indext on the left part of the array
         * in respect to j.
         */
        if ( v[i] > v[j] ) {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;

            /* The new element has been placed in the position j.
             * That same element may be moved again depending
             */
            sift( v, j, r );
        }
    }
    return;

}

/* Heapifies the input vector.  */
void buildHeap( int *v, int n )
{

    /* Since a maximum of half of the elements of a heap are leaves,
     * sift does not need to be applied for them. Infact it's already
     * heapified for those elements.  */
    int k = ( n / 2 ) - 1;


    printf( "Building heap.\n" );
    while ( k >= 0 ) {
        sift( v, k, n - 1 );
        printArray( v, n );
        k--;
    }

    return;

}

/* Max heap: sort the array in decreasing order.  */
void heapSort( int *v, int n )
{

    int k = n - 1;
    int tmp;


    buildHeap( v, n );
    /* After the build heap, we are sure of the following.  */
    assert( v[0] <= v[n - 1] );

    printArray( v, n );

    printf( "Sorting heap.\n" );

    for ( k = n - 1; k >= 1; k-- ) {
        /* Exchange the root of the binary tree (which is the smallest
         * element in the array) with the last leaf.  */
        tmp = v[0];
        v[0] = v[k];
        v[k] = tmp;

        printArray( v, n );

        /* With each iteration, sift is executed with a smaller problem whcih 
         * decreases its size lineary (k--).  */
        sift( v, 0, k - 1 );

        /* With the first iteration now are sure that the last element of the 
         * array is the smallest one. After having done two or more iterations 
         * we can see that the current element is smaller or equal to the one 
         * immediately previous. This means that the array is ordered
         * decreasingly.
         */
        if ( k < n - 1 )
            assert( v[k + 1] <= v[k] );
    }

    return;

}
