/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


/*COMMENTS TODO TODO TODO*/
#include <stdio.h>

/* Static variable.  */
int *anExternalStaticPointer;

int
main ( void )
{

  static int *aStaticPointer;
   /**/ int anAutomaticInteger;
  int aStaticInteger;

  int *anAutomaticPointer;

  if ( aStaticPointer == NULL )
    printf ( "aStaticPointer is NULL.\n" );

  if ( aStaticInteger == 0 )
    printf ( "aStaticInteger is %d\n", aStaticInteger );

  if ( anAutomaticPointer == NULL )
    printf ( "anAutomaticPointer is NULL.\n" );

  if ( anExternalStaticPointer == NULL )
    printf ( "anExternalStaticPointer is NULL.\n" );


  return 0;

}
