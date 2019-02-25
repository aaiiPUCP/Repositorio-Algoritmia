/* 
 * File:   Lists.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2015, 01:29 PM
 */

#ifndef LISTS_H
#define	LISTS_H

typedef int TElem;
typedef char* TKey;

typedef struct nodo{
    TElem elem;
    TKey key;
    struct nodo *sig;
}TNodo;

typedef struct lista{
    TNodo *inicio;
    TNodo *fin;
    int numElem;
}TLista;


/* Crea una lista vacía */
void Lista_init(TLista *);
/* Libera la memoria ocupada por todos los elmentos de la lista */
void Lista_finalizar(TLista *);
/* Inserta un nuevo elemento en la lista */
void Lista_insertar(TLista *,TKey , TElem);
/* Verifica si la lista está vacía */
int Lista_estaVacia(TLista *);
/* Elimina un elemento de la lista */
void Lista_eliminar(TLista *, TElem);
/* Obtiene el número de elementos de la lista*/
int Lista_tamanho(TLista *);
/* Verifica si un elemento está en la lista */
int Lista_estaEnLista(TLista *, TElem);
/* Imprime los elementos de la lista */
void Lista_imprimir(TLista *);

#endif	/* LISTS_H */

