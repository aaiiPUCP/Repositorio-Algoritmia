/* 
 * File:   main.c
 * Author: Fernando Alva Manchego
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

int main(int argc, char** argv) {
    
    TCola C;
    
    Cola_init(&C);
    
    Cola_enqueue(&C, 8);
    Cola_enqueue(&C, 10);
    Cola_enqueue(&C, 5);
    
    while (!Cola_isEmpty(&C)){
        printf("Elemento retirado: %d\n", Cola_dequeue(&C));
    }
    
    Cola_finalize(&C);
    
    return (EXIT_SUCCESS);
}

