/* 
 * File:   HashNombre.h
 * Author: junior
 *
 * Created on November 3, 2014, 1:12 AM
 */

#ifndef HASHNOMBRE_H
#define	HASHNOMBRE_H

#include "RedSocial.h"

struct HashNombre {
    // cada entrada equivale a un índice, que puede tener más de un elemento
    int numEntradas;
    ListaUsuarios* entradas;
};

#endif	/* HASHNOMBRE_H */

