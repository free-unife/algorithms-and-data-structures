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

int main ( void ) {

  first f = malloc( sizeof( nodePointer * ) );
  last l = malloc( sizeof( nodePointer * ) );
  initQueue( f, l );

  insertQueue( 10, f, l );
  insertQueue( 20, f, l );
  insertQueue( 30, f, l );

  printQueue( f );
  printf("--------\n");
  extractQueue( f );

  printQueue( f );

  return 0;

}
