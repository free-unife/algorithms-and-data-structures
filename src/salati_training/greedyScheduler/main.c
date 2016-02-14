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


    j[0].name = "grind coffe";
    j[0].taskTime = 15;
    j[0].deadline = 65;

    /* T0 = 0 = start time.  */
    j[1].name = "start";
    j[1].taskTime = 1;
    j[1].deadline = 4;

    j[2].name = "heat up";
    j[2].taskTime = 30;
    j[2].deadline = 40;

    j[3].name = "deliver coffe";
    j[3].taskTime = 10;
    j[3].deadline = 80;

    isPossible = isSchedulingPossible( j, 4 );
    printf( "Is scheduling possible = %d\n", isPossible );

    return 0;

}
