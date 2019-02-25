/* 
 * File:   main.c
 * Author: Fernando Alva Manchego
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main(int argc, char** argv) {
    TPila P;
    
    Pila_init(&P);
    
    Pila_push(&P, 8);
    Pila_push(&P, 10);
    Pila_push(&P, 5);
    
    while (!Pila_isEmpty(&P)){
        printf("Elemento desempilado: %d\n", Pila_pop(&P));
    }
    
    Pila_finalize(&P);
        
    return (EXIT_SUCCESS);
}

