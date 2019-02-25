#include "HashID.h"
#include <stdlib.h>
#include "ListaUsuarios.h"
#include "Usuario.h"

HashID initHashID(int numEntradas) {
    HashID hash;
    hash.numEntradas = numEntradas;
    hash.entradas = malloc(numEntradas * sizeof(ListaUsuarios));
    int i;
    for (i = 0; i < numEntradas; i++)
        hash.entradas[i] = initListaUsuarios();
    return hash;
}

void HashID_Insert(HashID* hash, Usuario* usuario) {
    // usar ID de usuario para generar índice
    int indice =(usuario->id) % (hash->numEntradas);
    ListaUsuarios_Insert(&(hash->entradas[indice]), usuario);
}