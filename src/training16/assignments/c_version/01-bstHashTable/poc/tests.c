#include "globalDefines.h"

#if defined M_UTILS_C
int main (void)
{
    int *a = NULL;

    if ( element_null ( a ) )
        fprintf (stderr, "[ OK ]\n" );
    else
        fprintf (stderr, "[ ERR ]\n" );

    a = malloc_safe ( sizeof (int) * 10 );
    if ( !element_null ( a ) )
        fprintf (stderr, "[ OK ]\n" );
    else
        fprintf (stderr, "[ ERR ]\n" );


    return 0;
}

#elif defined M_ADT_C
int main ( void )
{
    node first, second, third;

    first = node_new ( "01", "hallo", 'l');
    second = node_new ( "02", "hi", 'l');
    third = node_new ( "03", "halala", 'l');

    nodes_connect ( first, second );
    nodes_connect ( second, third );
    node_print ( first );

    return 0;
}

#elif defined M_BST_C
int main (void)
{
    nodePtr rootRef = malloc_safe ( sizeof ( node ) );
    node res0, res1;

    BSTInit (rootRef);

    res0 = BSTInsert ( rootRef, "00", "hallo" );
    fprintf (stderr, "%s %s\n", key_get ( res0 ), value_get ( res0 ) );

    res1 = BSTInsert ( rootRef, "01", "ha" );

/*    fprintf (stderr, "%s %s\n", key_get ( BSTRight (res0) ), value_get ( 
BSTRight ( res0 ) ) );*/

    (void) res1;

    return 0;
}

#endif
