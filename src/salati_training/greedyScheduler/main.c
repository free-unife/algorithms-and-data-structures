/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef MAIN_H
#define MAIN_H
#include "main.h"
#endif

int main( void )
{
    struct task j[4];
    int isPossible;


    j[0].name = "start";
    j[0].taskTime = 1;
    j[0].deadline = 5;

    j[1].name = "heat up";
    j[1].taskTime = 30;
    j[1].deadline = 45;

    j[2].name = "make coffe";
    j[2].taskTime = 15;
    j[2].deadline = 60;


    isPossible = isSchedulingPossible( j, 3 );
    printf( "is possible = %d\n", isPossible );

    return 0;

}
