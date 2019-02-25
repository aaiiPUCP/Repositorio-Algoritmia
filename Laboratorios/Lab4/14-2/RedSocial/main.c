#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Usuario.h"
#include "HashID.h"

void leerUsuarios(HashID* hashID);

int main(int argc, char** argv) {
    
    HashID hashID = initHashID(10);
    
    // leer data original
    leerUsuarios(&hashID);
    // imprimir luego de leer data original
    
    // leer de la entrada estándar dos nombres separados por salto de línea
    // desetiquetar usuarios
    // imprimir luego de desetiquetar
    
    // ordenar por fecha de inicio de amistad
    // imprimir luego de ordenar amistades
    
    return 0;
}

void leerUsuarios(HashID* hashID) {
    FILE* fUsuarios = fopen("usuarios.txt", "r");
    int id, dia, mes, ano;
    char nombre[100];
    
    while (fscanf(fUsuarios, "%d", &id) != EOF) {
        fscanf(fUsuarios, "\n");
        fgets(nombre, 100, fUsuarios);
        nombre[strlen(nombre) - 1] = 0; // quitar salto de línea
        fscanf(fUsuarios, "%d %d %d", &dia, &mes, &ano);
        Usuario* usuario = new_Usuario(id, nombre, initFecha(dia, mes, ano));
        
        // impresión temporal para verificar lectura de datos personales
        Usuario_Print(usuario);
        printf("\n");
        
        // insertar a la tabla hash de usuarios por ID
        HashID_Insert(hashID, usuario);
    }
}