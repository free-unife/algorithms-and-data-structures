/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

/* http://www.cse.yorku.ca/~oz/hash.html djb2 */
/* Output is unsigned because we have buckets from 0 to M - 1.  */
unsigned int hash( char *input )
{
    unsigned int key = 5381, i;

    i = 0;
    while ( input[i] != '\0' ) {
        key = ( key << 5 ) + key + ( ( unsigned int ) input[i] );       /* hash * 33 + c */
        i++;
    }

    /*
     * Return the slot id.  
     */
    return ( key % M );
}
