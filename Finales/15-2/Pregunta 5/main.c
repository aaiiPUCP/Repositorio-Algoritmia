/* 
 * File:   main.c
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2015, 01:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
/*
 * 
 * Estamos implementado el Tad de la tabla hash con las el tipo de listas
 * que nos ayuda en la abstraccion. La mayoria de comentarios esta en el mismo 
 * codigo. En general lo que hacemos es crear las funciones de crear una nueva 
 * tabla hash que aloque la memoria suficiente y que las listas se inicializen
 * con su propia funcion. El Tad de la Tabla hash hace cosas puntuales ya que la 
 * mayoria de las inserciones y el trabajo pesado es manejado por las listas
 * 
 * Para la implementacion del Mid Square primero hemos transformado el string
 * a un integer sumando los valores de la letras (puestas en minuscula) 
 * con su valor ANSCI. Luego hemos usado mods y divisiones enteras para obtener
 * el valor del medio del cuadrado de lo que nos resultaba el valor anterior
 * 
 */
int main(int argc, char** argv) {

    t_hash hash_table;
    Hash_New(&hash_table,10);    //Tamaño pequeño de 10;
    
    Hash_addContact(&hash_table,"5125",755);  //No las he testeado pero he tratado
    //que la implementacion este bastante limpia
    Hash_searchContact(&hash_table,"5125");
    
    return (EXIT_SUCCESS);
}

