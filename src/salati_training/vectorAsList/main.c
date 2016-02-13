/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef MAIN_H
#define MAIN_H
#include "main.h"
#endif

int main( void )
{
    vector newVector;
    int i;
    int length;

    printf("\nCalling createEmptyVector and tailExtendVector:\n");
    newVector = createEmptyVector();

    for(i = 0; i<10; ++i ){
    	printf( "Length: %d\n", vectorLength( newVector ) );
    	newVector = tailExtendVector(newVector, i);
    }

    printf("\n\nCalling getElementValue:\n");
    for(i = 0; i < vectorLength( newVector ); ++i ){
    	printf( "vector[%d] -> %d\n", i, getElementValue( newVector, i ) );
    }

    printf("\n\nCalling tailTrimVector:\n");
    
    length = vectorLength(newVector);
    
    for(i = 0; i < length; ++i ){
    	newVector = tailTrimVector(newVector);
    	printf( "Length: %d\n", vectorLength( newVector ) );
    }

    /*
    newVector = createInitializedVector( 2, 5 );

    printf( "%d\n", vectorLength( newVector ) );
    setElementValue( newVector, 1, 100 );
    printf( "%d\n", getElementValue( newVector, 1 ) );
	*/


    return 0;
}
