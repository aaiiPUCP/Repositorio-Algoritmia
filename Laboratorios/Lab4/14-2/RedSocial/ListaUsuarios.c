#include "ListaUsuarios.h"
#include "Usuario.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ListaUsuarios initListaUsuarios() {
    ListaUsuarios lista;
    lista.primero = NULL;
    lista.ultimo = NULL;
    return lista;
}

ListaUsuarios* new_ListaUsuarios() {
    ListaUsuarios* lista = malloc(sizeof(ListaUsuarios));
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}

void ListaUsuarios_Insert(ListaUsuarios* lista, Usuario* usuario) {
    NodoListaUsuarios* nodo = malloc(sizeof(NodoListaUsuarios));
    nodo->usuario = usuario;
    nodo->sig = NULL;
    nodo->prev = lista->ultimo;
    if (lista->ultimo != NULL) lista->ultimo->sig = nodo;
    else lista->primero = nodo;
    lista->ultimo = nodo;
}