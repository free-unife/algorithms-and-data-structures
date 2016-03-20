/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_MEASURERUNNINGTIME_H
#define M_MEASURERUNNINGTIME_H
#include "measureRunningTime.h"
#endif


second measureRunningTime( clock_t start, clock_t end )
{

    return ( ( second ) ( ( double ) ( end - start ) /
                          ( double ) CLOCKS_PER_SEC ) );

}
