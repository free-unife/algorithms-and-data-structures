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


    printf("\n\nCalling insertElement:\n");
    
    length = vectorLength(newVector);
    
    for(i = 0; i < 10; ++i ){
        newVector = insertElement(newVector, i, i*10);
        printf( "Length: %d\n", vectorLength( newVector ) );
    }


    newVector = insertElement(newVector, 5, 9999);
    printf( "Length: %d\n", vectorLength( newVector ) );

    printf("\n\nCalling getElementValue:\n");
    for(i = 0; i < vectorLength( newVector ); ++i ){
        printf( "vector[%d] -> %d\n", i, getElementValue( newVector, i ) );
    }   
    


    printf("\n\nCalling removeElement -> head:\n");
    
    length = vectorLength(newVector);
    
    newVector = removeElement(newVector, 0);
   
    printf("\n\nCalling getElementValue:\n");
    for(i = 0; i < vectorLength( newVector ); ++i ){
        printf( "vector[%d] -> %d\n", i, getElementValue( newVector, i ) );
    }


    printf("\n\nCalling removeElement -> middle:\n");
    
    length = vectorLength(newVector);
    
    newVector = removeElement(newVector, 4);
   
    printf("\n\nCalling getElementValue:\n");
    for(i = 0; i < vectorLength( newVector ); ++i ){
        printf( "vector[%d] -> %d\n", i, getElementValue( newVector, i ) );
    }


    printf("\n\nCalling removeElement -> queue:\n");
    
    length = vectorLength(newVector);
    
    newVector = removeElement(newVector, length-1);
   
    printf("\n\nCalling getElementValue:\n");
    for(i = 0; i < vectorLength( newVector ); ++i ){
        printf( "vector[%d] -> %d\n", i, getElementValue( newVector, i ) );
    }
    
    /*
    newVector = createInitializedVector( 2, 5 );

    printf( "%d\n", vectorLength( newVector ) );
    setElementValue( newVector, 1, 100 );
    printf( "%d\n", getElementValue( newVector, 1 ) );
	*/


    return 0;
}
