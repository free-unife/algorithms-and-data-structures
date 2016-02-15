/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "straightInsertion.h"


void straightInsertion(int *v, int n )
{

    int i, j, scan, toInsert, tmp;


    i = 1;

    while (i <= n-1)
    {
        if (i > 1)
        {
            j = i - 1;
            assert (v[j - 1] <= v[j]);
        }

        scan = 0;

        while ((scan <= i - 1) && (v[scan] <= v[i]))
            scan++;

        toInsert = scan;
        tmp = v[i];
        scan = i-1;

        while (scan >= toInsert)
        {
            v[scan + 1] = v[scan];
            scan--;
        }

        v[toInsert] = tmp;

        i++;
    }


    return;

}
