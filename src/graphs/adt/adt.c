/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef ADT_H
#define ADT_H
#include "adt.h"
#endif


/* Init the list with a dummy node that points himself */
void initDoubleLinkedList( headPointer hp )
{
    /* insert a dummy node */
    *hp = malloc( sizeof( struct graphElement ) );

    /* setup his next and prec pointers to itself */
    ( *hp )->next = ( *hp );
    ( *hp )->prev = ( *hp );

    return;
}

/* Calculante list length, if only the dummy node is present,
 * than length( head ) == 0;
 */
int lengthDoubleLinkedList( headPointer hp )
{
    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;

    int size = 0;

    while ( succNode != refToDummy ) {
        succNode = succNode->next;
        size = size + 1;
    }

    return size;
}

/* Tells if the list is EMPTY using lenght() */
boolean isDoubleLinkedListEmpty( headPointer hp )
{
    return lengthDoubleLinkedList( hp ) == 0 ? true : false;
}

nodePointer searchVertex( char *nameToSearch, headPointer hp )
{

    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer foundNode = EMPTY;


    /* Begin scan */
    while ( succNode != refToDummy ) {
        if ( strcmp( succNode->name, nameToSearch ) == 0 ) {
            foundNode = succNode;
        }
        succNode = succNode->next;
    }

    return foundNode;
}

nodePointer searchEdge( nodePointer fromNode, nodePointer toNode,
                        headPointer hp )
{

    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer foundNode = EMPTY;

    /* Begin scan */
    while ( succNode != refToDummy ) {
        if ( ( succNode->fromNode == fromNode )
             && ( succNode->toNode == toNode ) ) {
            foundNode = succNode;
        }
        succNode = succNode->next;
    }

    return foundNode;
}

/* Free in/out connection and re-init those lists.  */
void reinitConnections( nodePointer vertex )
{
    freeDoubleLinkedList( vertex->edgeListOut );
    freeDoubleLinkedList( vertex->edgeListIn );

    vertex->edgeListOut = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( vertex->edgeListOut );

    vertex->edgeListIn = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( vertex->edgeListIn );

}

/* Create a new vertex. 
 * If vertexListPointer and edgeListPointer are:
 * null together -> all list are intialized. new vertex is created.
 * exist toghether -> a new vertex is created, vlp & elp are copied in his structure.
 * one null one not -> error!
 *
 * If a vertex is insered twice, we reset his in/out edge list.
 * So every vertex in list have an atomic value (name).
*/
nodePointer newVertex( char *name, vertexListPointer vlp,
                       edgeListPointer elp )
{
    nodePointer foundVertex;
    nodePointer dummyVertex;
    nodePointer newVertex;

    /* if are null together, init the graph */
    if ( vlp == EMPTY && elp == EMPTY ) {
        if ( ( vlp = malloc( sizeof( nodePointer * ) ) ) == NULL )
            exit( EXIT_FAILURE );

        if ( ( elp = malloc( sizeof( nodePointer * ) ) ) == NULL )
            exit( EXIT_FAILURE );

        initDoubleLinkedList( vlp );
        initDoubleLinkedList( elp );
    }

    /* no sense */
    else if ( ( vlp != EMPTY && elp == EMPTY )
              || ( vlp == EMPTY && elp != EMPTY ) ) {
        printf( "newVertex() function error. -> Nonsense operation\n" );
        exit( EXIT_FAILURE );
    }

    /* here vlp & elp are not empty together */

    /* every edge node in list must have an atomic value */
    foundVertex = searchVertex( name, vlp );
    if ( foundVertex != EMPTY ) {
        reinitConnections( foundVertex );

        return foundVertex;
    }


    /* allocate memory for the vertex */
    if ( ( newVertex = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert vetex name.  */
    newVertex->name = name;

    /* Insert vlp and elp wich are the same for all vertex in a graph */
    newVertex->pointerToVertexHead = vlp;
    newVertex->pointerToEdgeHead = elp;

    /* Init his in/out list */
    newVertex->edgeListOut = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newVertex->edgeListOut );

    newVertex->edgeListIn = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newVertex->edgeListIn );

    /* Fix list pointers.  */
    dummyVertex = *vlp;

    newVertex->prev = dummyVertex->prev;
    newVertex->next = dummyVertex;
    dummyVertex->prev->next = newVertex;
    dummyVertex->prev = newVertex;

    return newVertex;
}

/* Insert an edge before the dummy node */
nodePointer newEdge( weight w, nodePointer fromNode, nodePointer toNode,
                     headPointer hp )
{
    nodePointer foundEgde;
    nodePointer dummy;
    nodePointer newNode;



    /* every edge node in list must have an atomic value */
    foundEgde = searchEdge( fromNode, toNode, hp );
    if ( foundEgde != EMPTY ) {
        printf
            ( "The edge from \"%s\" to \"%s\" already exists! Pay Attention!\n\n",
              fromNode->name, toNode->name );

        return foundEgde;
    }


    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert edge info.  */
    newNode->w = w;
    newNode->fromNode = fromNode;
    newNode->toNode = toNode;

    newNode->pointerToEdgeHead = hp;

    /* Fix list pointers.  */
    dummy = *hp;

    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}

nodePointer connectVertex( headPointer edgehp,
                           nodePointer fromNode, nodePointer toNode,
                           weight w )
{
    nodePointer edgeP;

    edgeP = newEdge( w, fromNode, toNode, edgehp );

    /* from -> out && to -> In.  */
    insertEdgeInList( edgeP, fromNode->edgeListOut );
    insertEdgeInList( edgeP, toNode->edgeListIn );

    return edgeP;
}

void insertEdgeInList( nodePointer np, headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer newNode;


    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    newNode->edgeAddr = np;

    /* fix list pointers */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return;
}

void printNodeEdges( headPointer hp )
{
    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;

    if ( isDoubleLinkedListEmpty( hp ) ) {
        printf( "No edges\n" );
        return;
    }

    while ( succNode != refToDummy ) {
        printf( "%d ", ( succNode->edgeAddr )->w );
        succNode = succNode->next;
    }
    printf( "\n" );

    return;
}

void printVertex( headPointer hp )
{

    nodePointer dummy = *hp;
    nodePointer thisVertex = dummy->next;
    int index = 0;

    while ( thisVertex != dummy ) {
        printf( "Vertex[%d]->name = %s\n", index, thisVertex->name );
        index = index + 1;
        thisVertex = thisVertex->next;
    }
    return;
}

/* free the node after dummy  */
void freeNodeInHead( headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer toDelete = dummy->next;

    /* Fix pointers */
    dummy->next = toDelete->next;
    toDelete->next->prev = dummy;

    free( toDelete );

    return;
}

void freeDoubleLinkedList( headPointer hp )
{
    while ( lengthDoubleLinkedList( hp ) > 0 ) {
        freeNodeInHead( hp );
    }
    free( *hp );
    *hp = EMPTY;

    return;
}

/* Free all the graph given the vertex list */
void freeGraph( headPointer headVertexList, headPointer headEdgeList )
{

    nodePointer dummyVertex = *headVertexList;
    nodePointer thisVertex = dummyVertex->next;

    /* free all the Edge List */
    freeDoubleLinkedList( headEdgeList );

    /* free all in and out edge list for each node */
    while ( thisVertex != dummyVertex ) {

        freeDoubleLinkedList( thisVertex->edgeListOut );
        freeDoubleLinkedList( thisVertex->edgeListIn );

        thisVertex = thisVertex->next;
    }

    /* free all the Vertex List */
    freeDoubleLinkedList( headVertexList );

    return;
}


/* K.I.S.S queue functions. The queue has been implemented as an array of
 * pointer to nodes. */
boolean isQueueEmpty( int *head, int *tail )
{
    return ( *head == *tail );
}

nodePointer *initNodeQueue( int nodeListLen )
{
    nodePointer *queue;

    queue = malloc( sizeof( nodePointer ) * nodeListLen );

    return queue;
}

void enqueue( int *tail, int nodeListLen,
              nodePointer * queue, nodePointer toEnqueue )
{
    queue[*tail] = toEnqueue;

    *tail = ( *tail + 1 ) % nodeListLen;

    return;
}

nodePointer dequeue( int *head, int nodeListLen, nodePointer * queue )
{
    nodePointer toDequeue;

    toDequeue = queue[*head];
    *head = ( *head + 1 ) % nodeListLen;

    return toDequeue;
}


void printVertexDistancesFromRootNode( headPointer hp, nodePointer root )
{

    nodePointer dummy = *hp;
    nodePointer thisVertex = dummy->next;

    while ( thisVertex != dummy ) {
        printf( "Distance of %s from %s = %d\n", root->name,
                thisVertex->name, thisVertex->distance );
        thisVertex = thisVertex->next;
    }
    return;
}

/* This functions visits the graph and sets the distance filed of each vertex
 * to the number of steps required to reach that vertec to the designated root
 * of the graph.  */
void breadthFirstSearch( headPointer hp, nodePointer root )
{
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer *queue = NULL;
    int head = 0, tail = 0, nodeListLen;
    int *h, *t;
    nodePointer currentNode;
    /* Address of adjacent nodes.  */
    nodePointer adjRef, adjNode, adjNodeDummy;


    while ( succNode != refToDummy ) {
        /* Set distance to of all nodes to infinity.  */
        succNode->distance = INF;
        succNode->parent = EMPTY;

        succNode = succNode->next;
    }

    /* Get length of node list.  */
    nodeListLen =
        lengthDoubleLinkedList( ( succNode->next )->pointerToVertexHead );

    /* Create a new queue (implemented as a traditional array of pointers). */
    queue = initNodeQueue( nodeListLen );
    /* Assign addresses of queue's head and tail indices to its pointers.  */
    t = &tail;
    h = &head;

    root->distance = 0;
    enqueue( t, nodeListLen, queue, root );

    while ( !isQueueEmpty( h, t ) ) {

        currentNode = dequeue( h, nodeListLen, queue );

        /* Get adjacent nodes to current node.  */
        adjRef = ( *( currentNode->edgeListOut ) )->next;

        /* Dummy.  */
        adjNodeDummy = adjRef->prev;

        /* for each node n that is adjacent to current: */
        while ( adjRef != adjNodeDummy ) {

            adjNode = adjRef->edgeAddr->toNode;

            if ( ( ( adjNode )->distance ) == INF ) {
                ( adjNode )->distance = ( ( currentNode )->distance ) + 1;
                ( adjNode )->parent = currentNode;
                enqueue( t, nodeListLen, queue, adjNode );
            }

            adjRef = adjRef->next;
        }
    }

    free( queue );

    return;

}
