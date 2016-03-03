/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "atoi.h"


int aToI( const char *s )
{

    int i = 0, num = 0;
    /* Base of output number is 10 */
    const int x = 10;
    /* Offset used to transform single ASCII element to integer representation. */
    const char offset = '0';


    while ( s[i] != '\0' ) {
        /* Check if input character corresponds to a number between 0 and 9. */
        assert( s[i] >= '0' && s[i] <= '9' );
        num = ( num * x ) + s[i] - offset;
        i++;
    }

    return num;
}
