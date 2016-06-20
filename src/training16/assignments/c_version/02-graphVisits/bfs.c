/*
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"


unsigned int BFS(Graph g, nodePointer source)
{
    int i;
    unsigned int maxQueueDim = 0;
    nodePointer *vertexArray;
    nodePointer u;
    nodePointer *v;
    unsigned int u_d;
    first f;
    last l;

    f = malloc_safe( sizeof( first ) );
    l = malloc_safe( sizeof( last) );
    initQueue( f, l );

    vertexArray = vertices_iterate (g);
    for (i = 0; i < lengthDoubleLinkedList (g -> head); i ++)
    {
        strcpy (vertexArray[i]->color, "WHITE");
        vertexArray[i]->d = INT_MAX;
        vertexArray[i]->pi = NULL;
    }

    strcpy (source->color, "GREY");

    insertQueue( source, f, l );

    while (lenQueue (f) != 0)
    {
        u = extractQueue(f);
        v= vertexlistnode_getneighbors (g, u);
        i = 0;
        while (!element_null(v[i]))
        {
            if (strcmp (v[i] -> color, "WHITE") == 0)
            {
                strcpy (v[i]->color, "GREY");
                u_d = u->d;
                v[i]->d = u_d + 1;
                v[i]->pi = u;

                insertQueue (v[i], f, l);

                if (lenQueue (f) > maxQueueDim)
                    maxQueueDim = lenQueue(f);
            }
            i++;
        }
        strcpy (u -> color, "BLACK");
    }

    return maxQueueDim;
}
