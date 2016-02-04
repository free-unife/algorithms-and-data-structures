#include <stdio.h>
#include <stdlib.h>


typedef struct elementList{

int elemento;
struct elementList *next;

}list;

int main(void){

    int i = 0; 
    
    list *l = (list *) malloc(sizeof(list));

    (*l).elemento = 28;
    (*l).next = NULL;
    
    // time to insert...
    list * head = l;
    list * prev = l;
/*
    for( i = 0; i<10 ; i++ ) {
        prev->next = (list * ) malloc ( sizeof(list));
        (*((*prev).next)).elemento = i;
        prev = prev->next;  
    }
    prev->next = NULL;
*/
    list *current;
    for( i = 0; i<10 ; i++ ) {
        current = (list * ) malloc ( sizeof(list));
        current->elemento = i;
        prev->next = current;
        prev = prev->next;  
    }
    prev->next = NULL;

    prev = head;
    while ( prev != NULL ) {
        printf("An_integer : %d\n", (*prev).elemento);
        prev = (*prev).next;
        
    }
    
    
    
    return 0;
} 
