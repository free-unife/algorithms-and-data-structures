/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef ASSERT
#define ASSERT
#include <assert.h>
#endif


#define true 1
#define false 0

typedef int boolean;
typedef int time;

struct task {
    char *name;
    time taskTime;
    /* Deadline must be counted from the time the first task starts.
     * The first task is assumed to be the one with the nearest deadline.  */
    time deadline;
};

int partition( struct task *j, int from, int to );
void sortByNearestDeadlineFirst( struct task *j, int from, int to );
boolean isSchedulingPossible( struct task *j, int numberOfTasks );
