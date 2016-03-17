/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_MERGESORT_H
#define M_MERGESORT_H
#include "mergeSort.h"
#endif


void mergeSort( int *V, int p, int r)
{

    int q;


    if (p < r)
    {
        q = ( p + r ) / 2;
        mergeSort(V, p, q);
        mergeSort(V, q + 1, r);
        merge(V, p, q, r);
    }


    return;

}

void merge (int *V, int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j, k;
    int *L, *R;


    if ( ( L = malloc( (n1 + 1) * sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );
    if ( ( R = malloc( (n2 + 1) * sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );

    for (i = 0; i < n1; i++)
        L[i] = V[p + i];

    for (j = 0; j < n2; j++)
        R[j] = V[q + 1 + j];

    L[n1] = INF;
    R[n2] = INF;

    i = 0;
    j = 0;
    for (k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            V[k] = L[i];
            i++;
        }
        else
        {
            V[k] = R[j];
            j++;
        }
    }

    free (L);
    free (R);

    return;

}

