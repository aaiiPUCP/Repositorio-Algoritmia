#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"


void Cola_init(TCola *C){
    C->inicio = NULL;
    C->fin = NULL;
    for(int i = 0 ; i < 5; i ++) (C->ultimo)[i] = NULL;
}

void Cola_enqueue(TCola *C, TElemento nuevoElem){
    TNodo *ptr_nuevoNodo;
    
    ptr_nuevoNodo = malloc(sizeof(TNodo*));
    
    int escuela = nuevoElem.escuela, id = nuevoElem.id;
    if (ptr_nuevoNodo != NULL){
        ptr_nuevoNodo->info = nuevoElem;
        ptr_nuevoNodo->sig = NULL;
        if(C->ultimo[escuela] == NULL){
            C->ultimo[escuela] = ptr_nuevoNodo;
            C->ultimo[escuela]->sig = NULL;
            if(C->inicio == NULL){
                C->inicio = ptr_nuevoNodo;
            }
            else{
                C->fin->sig = ptr_nuevoNodo;
            }
            C->fin = ptr_nuevoNodo;
        }
        else{
            if(C->ultimo[escuela]-> sig == NULL){
                C->fin = ptr_nuevoNodo;
            }
            else{
                ptr_nuevoNodo->sig = C->ultimo[escuela]->sig;
            }
            C->ultimo[escuela]->sig = ptr_nuevoNodo;
            C->ultimo[escuela] = ptr_nuevoNodo;
        }
    }
}

TElemento Cola_dequeue(TCola *C){
    if (!Cola_isEmpty(C)){
        TElemento head_info; TNodo *ptr_head;
        ptr_head = C->inicio;
        head_info = ptr_head->info;
        C->inicio = C->inicio->sig;
        if(C->inicio == NULL || C->inicio->info.escuela !=head_info.escuela) C->ultimo[head_info.escuela] = NULL;
        free(ptr_head);
        return head_info;
    }
    TElemento nada;
    nada.escuela = -1; nada.id = -1;
    return nada;
}

int Cola_isEmpty(TCola *C){
    return (C->inicio == NULL);
}

void Cola_finalize(TCola *C){
    while (!Cola_isEmpty(C))
        Cola_dequeue(C);

    for(int i = 0 ; i < 5; i ++) (C->ultimo)[i] = NULL;
}