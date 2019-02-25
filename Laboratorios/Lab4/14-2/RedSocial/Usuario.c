#include "Usuario.h"
#include "ListaAmistades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Usuario* new_Usuario(int id, char* nombre, Fecha fechaNacimiento) {
    Usuario* usuario = malloc(sizeof(Usuario));
    strcpy(usuario->nombre, nombre);
    usuario->id = id;
    usuario->fechaNacimiento = fechaNacimiento;
    // usuario->amistades = ?
    // usuario->fotos = ?
    
    return usuario;
}

void Usuario_Print(Usuario* usuario) {
    printf("ID: %d\nNombre: %s\nFecha Nacimiento: ", usuario->id, usuario->nombre);
    Fecha_Print(usuario->fechaNacimiento);
    printf("\n");
}