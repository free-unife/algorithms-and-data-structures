/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

double runningTime( clock_t start, clock_t end )
{
    return ( ( ( double ) ( end - start ) / ( double ) CLOCKS_PER_SEC ) );
}

void initArray( int **arrayPtr )
{
    assert( arrayPtr != NULL );
    *arrayPtr = EMPTY;
}

bool arrayNull( int *array )
{
    return ( array == NULL );
}

bool arrayEmpty( int *array )
{
    return ( arrayNull( array ) || ( *array == ARRAY_NULL_NUM ) );
}

/* Return value. */
int el( int *array, int index )
{
    assert( !arrayNull( ( array + index ) ) );
    return ( *( array + index ) );
}

/* Return memory address correspoing to an array index. */
int *pt( int *array, int index )
{
    assert( !arrayNull( array + index ) );
    return ( array + index );
}

/* For more information: $ man test. */
bool eq( int a, int b )
{
    return ( a == b );
}

bool gt( int a, int b )
{
    return ( a > b );
}

bool lt( int a, int b )
{
    return ( a < b );
}

bool ge( int a, int b )
{
    return ( gt( a, b ) || eq( a, b ) );
}

bool le( int a, int b )
{
    return ( lt( a, b ) || eq( a, b ) );
}

/* In the following functions work with addresses of memory of single 
 * array cells. This enables us to avoid any kind of loop and to use recursion 
 * only.
 */
bool arrayOrdered( int *array )
{
    if ( arrayEmpty( pt( array, 1 ) ) )
        return true;
    else if ( gt( el( array, 0 ), el( array, 1 ) ) )
        return false;

    /*
     * Go to the next array cell. 
     * Since the array is of type int, the compiler knows that array + 1 == 
     * (void *) *( array + ( 1 * sizeof ( int ) )
     */
    return ( arrayOrdered( pt( array, 1 ) ) );
}

void printArray( int *array )
{
    if ( arrayEmpty( array ) )
        return;
    else
        fprintf( stderr, "%d\n", el( array, 0 ) );

    printArray( pt( array, 1 ) );
}

int arrayLength( int *array )
{
    return ( arrayEmpty( array ) ? 0 : 1 + arrayLength( pt( array, 1 ) ) );
}

int arraySum( int *array )
{
    return ( arrayEmpty( array ) ? 0 : el( array, 0 ) +
             arraySum( pt( array, 1 ) ) );
}

bool arrayEqual( int *a1, int *a2 )
{
    /*
     * Base case. 
     */
    if ( arrayEmpty( a1 ) && arrayEmpty( a2 ) )
        return true;
    /*
     * Different lengths means that the arrays are not equal. 
     */
    else if ( ( arrayEmpty( a1 ) && !arrayEmpty( a2 ) )
              || ( !arrayEmpty( a1 ) && arrayEmpty( a2 ) ) )
        return false;
    /*
     * Both current indices of the arrays are equal so we can go further with 
     * the recursion. 
     */
    else if ( eq( el( a1, 0 ), el( a2, 0 ) ) )
        return ( arrayEqual( pt( a1, 1 ), pt( a2, 1 ) ) );
    /*
     * Non equal elements. 
     */
    else
        return false;
}

int *allocArray( int len )
{
    int *dest;

    if ( ( dest = malloc( ( ( size_t ) len + 1) * sizeof( int ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    dest[len] = ARRAY_NULL_NUM;

    return dest;
}

int *copyArray( int *src )
{
    int *dest;

    dest = allocArray( arrayLength( src ) );
    /*
     * The array terminating char must also be copied. 
     */
    return ( memcpy
             ( dest, src, ( arrayLength( src ) + 1 ) * sizeof( int ) ) );
}

int *genRandomArray( int len )
{
    int i;
    int *array;
    struct timespec t1;

    array = allocArray( len );

    /*
     * Seed is set in nanoseconds.
     */
    clock_gettime( CLOCK_MONOTONIC, &t1 );
    srand( t1.tv_nsec );

    for ( i = 0; i < len; i++ ) {
        array[i] = ( rand(  ) % ( RAND_MAX - RAND_MIN ) ) + RAND_MIN;
        assert( ge( el( array, i ), RAND_MIN )
                && le( el( array, i ), RAND_MAX ) );
    }

    return array;
}

#ifdef M_UTILS_C
int main( void )
{
    int *array, array1[6] = { 2, 3, 5, 7, 11, ARRAY_NULL_NUM };
    clock_t start, end;

    fprintf( stderr, "\n\nInitializing array\n" );
    initArray( &array );
    if ( arrayEmpty( array ) )
        fprintf( stderr, "[ OK ] Array is empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    fprintf( stderr, "\n\nGenerating random array of %d elements\n", 100 );
    array = genRandomArray( 100 );

    fprintf( stderr, "\n\nIs array still empty?\n" );
    if ( !arrayEmpty( array ) )
        fprintf( stderr, "[ OK ] Array is not empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    fprintf( stderr, "\n\nPrinting array\n" );
    printArray( array );


    fprintf( stderr, "\n\nPrinting array 1\n" );
    printArray( array1 );

    fprintf( stderr, "\n\nChecking array length\n" );
    if ( eq( arrayLength( array ), 100 ) )
        fprintf( stderr, "[ OK ] length of array is %d\n", 100 );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );
    if ( eq( arrayLength( array1 ), 5 ) )
        fprintf( stderr, "[ OK ] length of array is %d\n", 5 );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    fprintf( stderr, "\n\nIs array 1 ordered?\n" );
    if ( arrayOrdered( array1 ) )
        fprintf( stderr, "[ OK ] Array is ordered\n" );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    fprintf( stderr, "\n\nCopy array 1\n" );
    if ( eq( arrayLength( copyArray( array1 ) ), 5 ) )
        fprintf( stderr,
                 "[ OK ] Array 1 copy has the correct length of %d \n",
                 5 );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    fprintf( stderr, "\n\nTesting array copy and array equal\n" );
    if ( arrayEqual( array1, ( copyArray( array1 ) ) ) )
        fprintf( stderr, "[ OK ] Array copy and array equal works\n" );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    free( array );


    fprintf( stderr,
             "\n\nGenerating random array of %d elements and counting the running time\n",
             100 );
    start = clock(  );
    array = genRandomArray( 100 );
    end = clock(  );
    fprintf( stderr, "Measured running time is: %f s\n",
             runningTime( start, end ) );


    fprintf( stderr, "\n\nTesting array sum on array 1\n" );
    if ( eq
         ( array1[0] + array1[1] + array1[2] + array1[3] + array1[4],
           arraySum( array1 ) ) )
        fprintf( stderr, "[ OK ] Array sum of array 1 returned %d\n",
                 arraySum( array1 ) );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    free( array );

    return 0;
}
#endif
