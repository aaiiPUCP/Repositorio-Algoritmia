
#ifndef PILA_H
#define	PILA_H

typedef char TElemento;

typedef struct nodo {
        TElemento info;
        struct nodo *sig;
} TNodo;

typedef struct {
        TNodo *top;
} TPila;


void Pila_init(TPila*);
void Pila_push(TPila*, TElemento);
TElemento Pila_pop(TPila*);
int Pila_isEmpty(TPila *);
void Pila_finalize(TPila *);
TElemento Pila_peek(TPila*);

#endif	/* PILA_H */
