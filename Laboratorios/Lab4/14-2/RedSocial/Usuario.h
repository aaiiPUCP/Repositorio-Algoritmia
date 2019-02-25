#ifndef USUARIO_H
#define	USUARIO_H

#include "RedSocial.h"
#include "Fecha.h"
#include "ListaAmistades.h"
#include "ListaFotos.h"

struct Usuario {
    int id;
    char nombre[100];
    Fecha fechaNacimiento;
    ListaAmistades amistades;
    ListaFotos fotos;
};

Usuario* new_Usuario(int id, char* nombre, Fecha fechaNacimiento);
void Usuario_Print(Usuario* usuario);

#endif	/* USUARIO_H */

