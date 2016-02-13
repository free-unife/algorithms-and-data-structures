/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "greedyScheduler.h"


/*sortByNearestDeadlineFirst ()
{
}
*/

boolean isSchedulingPossible( struct task *j, int numberOfTasks )
{

    int i = 0, totalTime = 0;

    /* Every task must be executed before reaching its deadline.
     * For this reason the sequence of j task is sorted by nearest deadline
     * first.
     */
/*    sortByNearestDeadlineFirst();*/

    while ( i < numberOfTasks ) {
        if ( totalTime + j[i].taskTime > j[i].deadline )
            return false;

        totalTime += j[i].taskTime;
        i++;
    }



    return true;
}
