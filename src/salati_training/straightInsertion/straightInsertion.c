/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "straightInsertion.h"


/* Situation at the ith loop:
 * v[0] -> v[i-1], the array is ordered in increasing order.
 * v[i], number to be inserted in the ordered part.
 * v[i] -> v[n-1], unordered part of the array.
 */
void straightInsertion( int *v, int n )
{

    int i, j, k, scan, toInsert, tmp;


    i = 1;

    while ( i <= n - 1 ) {

        for ( k = 0; k < n; k++ )
            printf( "%d ", v[k] );
        printf( "\n" );

        /* Condition control.  */
        if ( i > 1 ) {
            j = i - 1;
            assert( v[j - 1] <= v[j] );
        }


        scan = 0;
        /* Where to insert.
         * For each 0 <= j < i - 1 - 1; v[j] <= v[j+1]
         * Use of binary search ins more efficient here since the sub-array is
         * ordered. */
        while ( ( scan <= i - 1 ) && ( v[scan] <= v[i] ) )
            scan++;

        /* Get the index where the current element (v[i]) will be inserted.
         */
        toInsert = scan;
        /* The following assert should be written like this:
         * assert (v[toInsert] > v[0: 1: scan - 1])
         */
        assert( v[toInsert] > v[scan - 1] );

        tmp = v[i];
        scan = i - 1;

        /* Shift all the elements after scan one index right, so that v[i] can
         * be inserted into v[toInsert]. */
        while ( scan >= toInsert ) {
            v[scan + 1] = v[scan];
            scan--;
        }

        v[toInsert] = tmp;

        i++;

        /* This is the same assertion as the upper one.  */
        j = i - 1;
        assert( v[j - 1] <= v[j] );
    }


    return;

}
