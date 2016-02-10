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
    
    
    tree aTree, lTree, rTree;
    

    lTree = consTree("leftor", EMPTYTREE, EMPTYTREE);
    rTree = consTree("rightscim", EMPTYTREE, EMPTYTREE);
    aTree = consTree("PANZE!", lTree, rTree);
    
    /*aTree = insOrd( 100, aTree);*/
    

    printf("Weight of aTree: %d\n", findWeight(aTree));
    
    printf("His root: %s\n", root(aTree));
    printf("His left: %s\n", root(left(aTree)));
    printf("His right: %s\n", root(right(aTree)));
    
    return 0;
}
