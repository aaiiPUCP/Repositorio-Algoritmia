/*
Estrategia: el caso base es cuando n == 2 porque 2^1 = 1
 * hay se imprime un caracter en la columna respectiva
 * se imprime dos caracteres en la columna respectiva
 * se imprime un caracter dejando un espacion en blanco
 * luego se llama recursivamente a la funcion pero a la mitad y 
 * con el mismo indice de columna
 * luego se imprimen los n caracteres leidos al inicio del problema
 * y se llama nuevamente a la recursividad para la parte de abajo
 * pero la columna aumenta n/2 posiciones 
 
 */
#include <stdio.h>
#include <stdlib.h>

//Imprime el caracter c cant veces desde la posicion pos
void imprimirCaracterPos(int pos, int cant, int c){
    int i;
    for(i=0; i<pos; i++)
        printf(" ");
    for(i=0; i<cant; i++)
        printf("%c",c);
    printf("\n");
}

void patron(int n, int i){
    
    //Caso Base
    if(n == 2){
        imprimirCaracterPos(i,1,'*');
        imprimirCaracterPos(i,2,'*');
        imprimirCaracterPos(i+1,1,'*');
    }
    else{
        //Llamada recursiva
        patron(n/2,i);
        
        imprimirCaracterPos(i,n,'*');
        
        //Llamada Recursiva
        patron(n/2,i + n/2);
    }
    
}

int main(int argc, char** argv) {
    int n,i;
    
    scanf("%d %d",&n,&i);
    
    patron(n,i);
    
    return (EXIT_SUCCESS);
}

