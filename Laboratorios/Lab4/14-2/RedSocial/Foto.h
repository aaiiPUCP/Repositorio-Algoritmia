/* 
 * File:   Foto.h
 * Author: junior
 *
 * Created on November 3, 2014, 1:06 AM
 */

#ifndef FOTO_H
#define	FOTO_H

#include "RedSocial.h"
#include "Fecha.h"
#include "ListaUsuarios.h"

struct Foto {
    char url[100];
    Fecha fecha;
    ListaUsuarios etiquetas;
};

#endif	/* FOTO_H */

