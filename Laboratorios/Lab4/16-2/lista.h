#ifndef LISTA_H
#define LISTA_H

typedef int TElemento;
//Será una lista doblemente enlazada
typedef struct nodo{
	TElemento elem;
	struct nodo *sig;
	struct nodo *ant;
}TNodo;

typedef struct lista{
	TNodo *inicio;
	TNodo *fin;
	int numElem;
}TLista;

void Lista_init(TLista *);
int Lista_isEmpty(TLista *);
int Lista_length(TLista *);
void Lista_insert(TLista *,TElemento);
void Lista_addLeft(TLista *,TElemento);
//Tendremos una funcion resta que determine el mayor de acuerdo a eso
//invoque a restaAux en el orden adecuado
void Lista_restar(TLista *,TLista *,TLista *);
void Lista_restarAux(TLista *,TLista *,TLista *);
int Lista_mayor(TLista *,TLista *);
void Lista_print(TLista *);

#endif