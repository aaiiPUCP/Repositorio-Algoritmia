/* 
 * File:   Cola.h
 * Author: Fernando Alva Manchego
 *
 */

#ifndef COLA_H
#define	COLA_H

typedef int TElemento;

typedef struct nodo {
        TElemento info;
        struct nodo *sig;
} TNodo;

typedef struct {
        TNodo *inicio;
        TNodo *fin;
} TCola;


void Cola_init(TCola*);
void Cola_enqueue(TCola*, TElemento);
TElemento Cola_dequeue(TCola*);
int Cola_isEmpty(TCola *);
void Cola_finalize(TCola *);

#endif	/* COLA_H */

