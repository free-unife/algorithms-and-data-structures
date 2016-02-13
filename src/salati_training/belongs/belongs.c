/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "belongs.h"


/* Functions that checks if an array is ordered.  */
boolean isArrayOrdered( int *v, int low, int high )
{

    int i;


    i = low;
    /* Since there can be multiple equal elements, the == statement holds.  */
    while ( i < high && v[i] <= v[i + 1] )
        i++;

    /* i >= high  */
    if ( i == high ) {
        /* Array is ordered.  */
        return true;
    }
    /* i < high */
    else {
        /* Array is not ordered.  */
        return false;
    }

}

/* A very simple binary search function on an ordered array.  */
int belongs( int el, int *v, int low, int high )
{

    /* Variable containing the index of the middle element.  */
    int mid;


    if ( high < low || low > high ) {
        /* Element not found or invalid initial input of low and high
         * variables.  */
        mid = -1;
        return mid;
    } else {

        /* Check if array is ordered within every function call.  */
        assert( isArrayOrdered( v, low, high ) );

        mid = ( low + high ) / 2;

        if ( v[mid] == el )
            return mid;
        /* v[mid : 1 : high] > el && v[low : 1 : mid - 1] <= el  */
        else if ( v[mid] > el )
            return ( belongs( el, v, low, mid - 1 ) );
        /* v[low : 1 : mid ] < el && v[mid + 1 : 1 : high] >= el  */
        else if ( v[mid] < el )
            return ( belongs( el, v, mid + 1, high ) );
    }

    /* This part of the function is never reached.  */

    return -1;

}
