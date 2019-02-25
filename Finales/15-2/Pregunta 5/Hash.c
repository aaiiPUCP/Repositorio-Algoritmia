#include <stdio.h>
#include <stdlib.h>

#include "Lists.h"
#include "Hash.h"
#include "ctype.h"

void Hash_New(t_hash* hash,int size)
{
    hash->size = size;
    hash->nElements = 0;
    int i;
    hash->table = malloc(sizeof(TLista)*size);
    for(i=0;i<size;i++)
    {
        Lista_init(&hash->table[i]);            // Inicializamos todas las lista
        // a las que le hemos reservado memoria
    }
}

int Hash_HashFunct(TKey key,int size)           // Implementamos aca la funcion
{                                              // Para mantener la abstracion (En el .c File)
    
    // Como es una cadena de caracteres primero utilizaremos la 
    // tecnica de comvertir a numero por sus caracteres ANSCI
    
    int k = 0;
    int i = 0;
    char c;
    while(key[i]!='\0')
    {
        c = key[i];
        c  = tolower(c);
        k += c - 'a';                
    }
       
    // Ya obtuvimos el valor numerico en k para poder hacer el Mid Square
    // Dependiendo del valor del size va a ser el numero de digitos que saca-
    // remos va a ser el numero de digitos del size menos uno Ej 1000 -> 3 digitos
    // 100 -> 2 digitos, 99 -> 1 digito (Es un caso malo pero evitamos un overflow)
    // con este tipo de hash function
    
    i = size;
    int contG  = 0;
    while(i)
    {
        contG++;
        i = i/10;           // division entera
    }
    contG--;   //tenemos el numero de digitos que debemos extraer;
    k *= k;  // Elevamos al curadrado
    
    int contK = 0;
    i = k;                  // Obtenemos el numero de digitos de el cuadrado (Deberiamos hacer un hacerto que sea)
                            // Mayor o igual al tamaño a extraer (El tamaño de ka tabla Hash no deberia ser tan grande
                            // Para que esto pase)
    while(i)
    {
        contK++;
        i = i/10;           // division entera
    }
    //ASSERT CONTK >= CONTG
    
    
    int factor = contK - contG;   //Obtenemos la cantidad que no va a ser extraida
    //la dividimos entre 2 y al K le hacemos mod primero de 10*(nAretirar+quesequedan/2)
    // y luego hacemos division entera de k / 10*(quesequedan/2);
    
    
    k = k % 10*(factor/2+contG);
    k = k / 10*(factor/2);   // Finalmente obtenemos el valor nesesario en K
    // Podriamos haberlo hecho con strings de una manera semejante con los indices
    
    return k;
}

void Hash_addContact(t_hash* hash,TKey key,TElem item)
{
    // Estoy modificando la manera en las listas que se ingresa el key ya que es un string
    // Ademas considero a los numeros Telefonicos como integers !!
    
    // Aca podemos hacer un ASSERT que el nElementos no sea el
    // 80% del tamaño porque deberiamos realizar un Rehash
    
    
    int kHash = Hash_HashFunct(key,hash->size);
    
    Lista_insertar(&hash->table[kHash],key,item);       // Mandamos la memoria 
    // Aca la lista se encarga de todas las insercciones
    // Como los casos cuando esta vacia o llena
    
    // le corresponde a la lista;
    // Incrementamos el numero de elementos de la T Hash   
    hash->nElements += 1;
    
}
TElem Hash_searchContact(t_hash* hash,TKey key)
{
    
     int kHash = Hash_HashFunct(key,hash->size);
     
     //Assert!
     if(Lista_estaVacia(&hash->table[kHash])) return -1;
     
     TNodo* currNode = hash->table[kHash].inicio;
     
     while(currNode&&strcmp(currNode->key,key)!=0)  //Comparacion de Strings   
     {
         currNode = currNode->sig;                  
     }
     
     if(currNode == NULL) return -1;    // No se encontro... ASSERT
     
     return currNode->elem;
      
    
}