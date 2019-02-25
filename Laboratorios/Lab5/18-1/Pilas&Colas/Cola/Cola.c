/* 
 * File:   Cola.c
 * Author: Fernando Alva Manchego
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"


void Cola_init(TCola *C){
    C->inicio = NULL;
    C->fin = NULL;
}

void Cola_enqueue(TCola *C, TElemento nuevoElem){
    TNodo *ptr_nuevoNodo;
    
    ptr_nuevoNodo = (TNodo*)malloc(sizeof(TNodo));
    
    if (ptr_nuevoNodo != NULL){
        ptr_nuevoNodo->info = nuevoElem;
        ptr_nuevoNodo->sig = NULL;
        if (C->inicio == NULL)
            C->inicio = ptr_nuevoNodo;
        else 
            C->fin->sig = ptr_nuevoNodo;

        C->fin = ptr_nuevoNodo;
    }
}

TElemento Cola_dequeue(TCola *C){
    if (!Cola_isEmpty(C)){
        TElemento head_info; TNodo *ptr_head;
        ptr_head = C->inicio;
        head_info = ptr_head->info;
        C->inicio = C->inicio->sig;
        free(ptr_head);
        return head_info;
    }
    return -1;
}

int Cola_isEmpty(TCola *C){
    return (C->inicio == NULL);
}

void Cola_finalize(TCola *C){
    while (!Cola_isEmpty(C))
        Cola_dequeue(C);
}