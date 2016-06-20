#include "globalDefines.h"

Vertex vertex_new (unsigned int id, char colour, int d, int f, Vertex p)
{
    Vertex new_vertex = malloc_safe (sizeof (VertexObject));
}

Vertex *vertex_initList (void)
{
    Vertex *head = malloc_safe (sizeof (Vertex));

    *head = NULL;

    return head;
}

void vertex_insert (Vertex *head, Vertex toInsert)
{
    Vertex this;

    if (element_null (*head))
    {
        toInsert -> prev = NULL;
        *head = toInsert;
    }
    else
    {
        this = *head;
        while (!element_null (this))
        {
            thisp = this;
            this = this -> next;
        }
        thisp -> next = toInsert;
        toInsert -> prev = thisp;
    }
    toInsert -> next = NULL;
}

void vertex_remove (Vertex *head, Vertex toRemove)
{
    return;
}

int main (void)
{
    Vertex *head = vertex_initList();
    Vertex zero;

    zero = vertex_new (0, 'w', 0, 0, NULL);
    vertex_insert (head, zero);

    return 0;
}
