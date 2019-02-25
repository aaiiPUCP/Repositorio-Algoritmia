#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "Lists.h"

void Lista_init(TLista *L){
    L->inicio = NULL;
    L->fin =  NULL;
    L->numElem = 0;
}

void Lista_finalizar(TLista *L){
    TNodo *ptrRec = L->inicio;
    while(ptrRec){
        L->inicio = L->inicio->sig;
        free(ptrRec);
        ptrRec = L->inicio;
    }
    L->inicio = NULL;
    L->fin = NULL;
    L->numElem = 0;
}

int Lista_estaVacia(TLista *L){
    return L->numElem == 0;
}

int Lista_tamanho(TLista *L){
    return L->numElem;
}

int Lista_estaEnLista(TLista *L, TElem e){
    TNodo *ptrRec = L->inicio;
    while (ptrRec){
        if (ptrRec->elem == e) return 1;
        ptrRec= ptrRec->sig;
    }
    return 0;
}

void Lista_insertar(TLista *L,TKey key, TElem nuevo){
    TNodo *ptrNuevo = malloc(sizeof(TNodo));
    if (ptrNuevo != NULL){
        ptrNuevo->elem = nuevo;
        ptrNuevo->sig = NULL;
        strcpy(ptrNuevo->key,key);         //Tener cuidado con memoria y punteros // No es una funcion tan segura
        // Insertar al final de la lista
        if (Lista_estaVacia(L))
            L->inicio = ptrNuevo;
        else
            L->fin->sig = ptrNuevo;
        L->fin = ptrNuevo;
        (L->numElem)++;
    }
}

void Lista_eliminar(TLista *L, TElem e){
    TNodo* ptrRec, *ptrAnt;
    ptrRec = L->inicio;
    ptrAnt = NULL;
    
    if (Lista_estaVacia(L)) return;
    
    while(ptrRec && ptrRec->elem != e){
        ptrAnt = ptrRec;
        ptrRec = ptrRec->sig;
    }
    
    if (ptrRec){//Encontró el elemento
        if (ptrAnt == NULL){ // Es el primer elemento
            L->inicio = L->inicio->sig;
        }
        if (ptrRec == L->fin){ // Es el último elemento
            L->fin = ptrAnt;
            if (L->numElem > 1) ptrAnt->sig = NULL;
        }else{// En el medio
            ptrAnt->sig = ptrRec->sig;
            ptrRec->sig = NULL;
        }
        free(ptrRec);
        (L->numElem)--;
    }
    
}

void Lista_imprimir(TLista *L){
    TNodo *ptrRec = L->inicio;
    while (ptrRec != NULL){
        printf("%d ", ptrRec->elem);
        ptrRec = ptrRec->sig;
    }
}

