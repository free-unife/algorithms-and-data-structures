/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_ISARRAYSORTED_H
#define M_ISARRAYSORTED_H
#include "isArraySorted.h"
#endif


boolean isArraySorted( int *V, size_t low, size_t high )
{

    size_t i;


    i = low;
    /* Since there can be multiple equal elements, the == statement holds.  */
    while ( i < high && V[i] <= V[i + 1] )
        i++;

    /* i >= high.  */
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
