/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "greedyScheduler.h"


int partition( struct task *j, int from, int to )
{

    /* To exchange elements we must work with struct pointers.  */
    struct task *pivot;
    struct task *tmp;

    int fromScan = from + 1;
    int toScan = to;
    int mid;

    /* get the pivot index (which is an address in this case).  */
    pivot = &( j[from] );

    assert( to > from );

    while ( true ) {

        while ( fromScan <= toScan
                && j[fromScan].deadline <= ( *pivot ).deadline )
            fromScan++;

        while ( toScan >= fromScan
                && j[toScan].deadline >= ( *pivot ).deadline )
            toScan--;

        assert( toScan > fromScan || toScan == fromScan - 1 );

        if ( toScan > fromScan ) {
            /* Exchange fromScan and toScan elements.  */
            tmp = &( j[fromScan] );
            j[fromScan] = j[toScan];
            j[toScan] = *tmp;
            fromScan++;
            toScan--;
        } else {
            break;
        }
    }

    assert( toScan == fromScan - 1 );
    mid = fromScan - 1;
    j[from] = j[mid];
    j[mid] = *pivot;


    return mid;

}

/* The following functions are a typical example of the greedy method.  */


/* Optimizating ordering function by nearset deadline first (this is our
 * selected criteria).  */

/* This is an adapted version of quicksort (see: divide and conquer scheme).
 */
void sortByNearestDeadlineFirst( struct task *j, int from, int to )
{

    int mid;


    if ( to > from ) {
        mid = partition( j, from, to );

        assert( from <= mid && mid <= to );

        sortByNearestDeadlineFirst( j, from, mid - 1 );
        sortByNearestDeadlineFirst( j, mid + 1, to );
    }

    return;

}



/* Function that returns true if a scheduling is possible with the given input,
 * false otherwise. We assume that we are working (f.e.) in a mono-processor
 * computer, or we are doing some kind of sequential tasks (f.e.: making
 * coffee).
 */
boolean isSchedulingPossible( struct task * j, int numberOfTasks )
{

    int i = 0, totalTime = 0;


    /* Every task must be executed before reaching its deadline.
     * For this reason the sequence of j task is sorted by nearest deadline
     * first.
     */
    sortByNearestDeadlineFirst( j, 0, numberOfTasks - 1 );

    while ( i < numberOfTasks ) {

        /* If not feasable (possible).  */
        if ( totalTime + j[i].taskTime > j[i].deadline )
            return false;

        totalTime += j[i].taskTime;
        i++;
    }

    return true;

}
