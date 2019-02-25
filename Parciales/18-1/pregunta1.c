/*
 * ya que existe un patron para los 50 primeros numeros se inicializa un arreglo
 * del 1 al 50 esto es solo para encontrar el n*5 elemento, siendo n la entrada,
 * ya que este será el inicio del patron donde se cumple que hay n ceros y este
 * patron se da hasta n*5+4, siempre se repite esta logica, es decir si n es 1 
 * n*5=5 y 5!=120 y aqui empieza a repetirse un cero hasta n*5+4 9!=362880 
 * siempre se cumple esto.  
 */

/* 
 * File:   pregunta1.c
 * Author: alulab14
 *
 * Created on 12 de mayo de 2018, 12:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define N 50
/*
 * 
 */

void imprimir(int A[],int ini){
    int i;
    for (i = ini; i <= ini+4; i++) {
        printf("%d ",A[i]);
    }

}

int encontrarFactnCeros(int A[],int x,int ini,int fin){
    if(ini>fin)
        return 0;
    int med=(ini+fin)/2;
    if(A[med]==x*5)
        imprimir(A,x*5);
    else if(A[med]<x*5)
        return encontrarFactnCeros(A,x,med+1,fin);
    else 
        return encontrarFactnCeros(A,x,ini,med-1);
}

int main(int argc, char** argv) {
    int A[N];
    int i;
    for (i = 0; i < N; i++) A[i]=i;
    int x=0;
    //scanf("%d",&x);
    encontrarFactnCeros(A,x,0,N);
    return (EXIT_SUCCESS);
}

