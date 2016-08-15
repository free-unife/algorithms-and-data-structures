/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


/*COMMENTS TODO TODO TODO*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;

    p = malloc (sizeof (int) * 10);
    p[0] = 4;
    p[1] = 6;
    p[2] = 9;

    printf ("sizeof(int) = %d, sizeof(*int) = %d, sizeof p = %d, sizeof *p = %d\n", sizeof (int), sizeof (int *), sizeof p, sizeof *p);
    printf ("%d %d %d\n", p[0], p[1], p[2]);

    return 0;
}
