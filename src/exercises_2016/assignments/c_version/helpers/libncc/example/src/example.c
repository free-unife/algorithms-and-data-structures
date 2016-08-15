/*
 * example.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libncc.h"
#include "example.h"

int main (void)
{
    int n = 5;
    int i;
    ex *arr = malloc (sizeof (struct example) * n);
    list l;
    stack s;
    queue q;
    char h[6] = {'h', 'a', 'l', 'l', 'o', '\0'};

    list_init (&l);
    stack_init (&s);
    queue_init (&q);

    fprintf (stderr, "l, s, q\n");

    for (i = 0; i < n; i++)
    {
        arr[i].aChar = malloc (sizeof (char) * n);
        sprintf (arr[i].aChar, "%s:%d", h, i);

        /* You can test both append and prepend functions here. */
        list_append (arr + i, &l);
        stack_push (arr + i, &s);
        queue_enqueue (arr + i, &q);
        fprintf (stderr, "Lengths = %d, %d, %d\n", list_length (l), 
list_length (s), list_length (q));
    }

    while (!list_null (l) || !stack_null (s) || !queue_null (q))
    {
        fprintf (stderr, "%s ", (*(list_head (l))).aChar);
        list_remove (&l, l);
        fprintf (stderr, "%s ", (*(stack_pop (&s))).aChar);
        fprintf (stderr, "%s ", (*(queue_dequeue (&q))).aChar);
        fprintf (stderr, "\n");
    }

    fprintf (stderr, "\n");

    for (i = 0; i < n; i++)
        free (arr[i].aChar);
    free (arr);

    return 0;
}
