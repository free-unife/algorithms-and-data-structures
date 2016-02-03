#include "liste.h"

boolean null( list * head ) {
    return( head == NULL );       
}

list * cons (element e, list * head ) {
    list * t;
    t = ( list * ) malloc( sizeof( list ));
    t -> next = head;
    t -> el = e;

    return t;
}

element car ( list * head ) {
    assert( ! null( head ));

    return head -> el;
}

list * cdr( list * head ) {
    assert( ! null( head ));

    return head -> next;
} 

void printList ( list * head ) {
    
    list * this;
    int index = 0;

    this = head;
    while ( this != NULL ) {
        printf( "List[%d] -> el ==  %d\n", index, this -> el );
        this = this -> next;
        index = index + 1;
    }
}
