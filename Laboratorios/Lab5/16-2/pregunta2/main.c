#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
//KPS
/*El programa que implementé va a apilar el elemento que lea, sea un caracter normal o un paréntesis abierto.
    En caso encuentre un operador va a desapilar e imprimir hasta encontrar un operador de prioridad menor
    o hasta que la pila se vacie y se va a proceder a apilar el operador con el que se está analizando
    Por otro lado, si encuentra un paréntesis cerrado, va a despilar e imprimir los elementos de la pila hasta
    encontrar el paréntesis abierto. Este'paréntesis solo se desapila, no se imprime.
    Al acabar de leer todos los elementos, vamos a desapilar hasta que la pila quede vacía c:
*/
int prioridad(char c){
    //Nos dará su prioridad
    if (c=='+' || c=='-')
        return 1;
    if (c=='*' || c=='/')
        return 2;
    if (c=='^')
        return 3;
    if (c=='(')
        return 4;
    if (c==')')
        return 5;
    //Para facilitar el desapilamiento de Desapilar, en caso sea un caracter normal, le ponemos una
    //prioridad alta
    return 10;
}
void DesapilarParentesis(TPila *P){
    //Un paréntesis va a desapilar hasta que encuentra el paréntesis abierto 
    while(!Pila_isEmpty(P) && Pila_peek(P)!='('){
        printf("%c ",Pila_pop(P));
    }
    //Desapilamos el paréntesis abierto
    Pila_pop(P);
}
void Desapilar(TPila *P,char c){
    //En caso el caracter leído sea un paréntesis cerrado, se irá a otro procedimiento
    if (c==')'){
       DesapilarParentesis(P);
       return;
    }
    //Si es un operador: loop hasta encontrar un operador de menor prioridad
    while(!Pila_isEmpty(P) && (prioridad(Pila_peek(P)))>=prioridad(c) && Pila_peek(P)!='('){
        //Desapilamos e imprimimos
        printf("%c ",Pila_pop(P));
    }
    //Apilamos el caracter
    Pila_push(P,c);
}

void notacioninfija(TPila *P){  
    char c1;
    c1='1';
    //Leemos el caracter
    scanf("%c",&c1);
    //Loop hasta que se lea el salto de línea
    while (c1!='\n'){
        //en caso el caracter sea un espacio en blanco se salta
        if (c1!='\n'&& c1!=' '){
            //Si es un caracter normal o un paréntesis abierto, apilo de frente
            if((c1>='A'&&c1<='Z')||c1=='('){
                Pila_push(P,c1);
            }
            else{
                //en caso el caracter sea un operador, iré a la función apilar
                Desapilar(P,c1);
            }
        }
        //Leemos de nuevo
        scanf("%c",&c1);
    }
    //Desapilamos todo lo que hay
    while(!Pila_isEmpty(P)){
        printf("%c ",Pila_pop(P));
    }

}
void main(){
    TPila P;
    Pila_init(&P);
    //Nuestro programa imprimirá los valores que lea en notación infija
    notacioninfija(&P);

    Pila_finalize(&P);
}