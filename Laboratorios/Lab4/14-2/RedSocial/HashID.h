/* 
 * File:   HashUsuariosPorID.h
 * Author: junior
 *
 * Created on November 3, 2014, 1:11 AM
 */

#ifndef HASHID_H
#define	HASHID_H

#include "RedSocial.h"
#include "HashID.h"

struct HashID {
    // cada entrada equivale a un índice, que puede tener más de un elemento
    int numEntradas;
    ListaUsuarios* entradas;
};

HashID initHashID(int numEntradas);
void HashID_Insert(HashID* hash, Usuario* usuario);

#endif	/* HASHID_H */

