#ifndef LISTAUSUARIOS_H
#define	LISTAUSUARIOS_H

#include "RedSocial.h"

typedef struct NodoListaUsuarios {
    struct NodoListaUsuarios* prev;
    struct NodoListaUsuarios* sig;
    Usuario* usuario;
} NodoListaUsuarios;

struct ListaUsuarios {
    NodoListaUsuarios* primero;
    NodoListaUsuarios* ultimo;
};

ListaUsuarios initListaUsuarios();
ListaUsuarios* new_ListaUsuarios();
void ListaUsuarios_Insert(ListaUsuarios* lista, Usuario* usuario);

#endif	/* LISTAUSUARIOS_H */

