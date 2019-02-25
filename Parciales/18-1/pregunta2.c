/*
 * Para este problema se tiene una arreglo se pide que la suma de dos subarreglos
 * formados por este arreglo sea minima y esto es aproximadamente la suma/2 de 
 * los elementos entonces se irán escogiendo los elementos para los subarreglos
 * hasta cumplir que su suma sea aproximadamente la mitad de la suma del arreglo
 * para esto se usará backtracking para probar y corroborar que elementos
 * correctos escoger
 */

/* 
 * File:   pregunta2.c
 * Author: alulab14
 *
 * Created on 12 de mayo de 2018, 11:46 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void imprimir(int A[],int f){
    int i;
    for (i = 0; i <= f; i++) {
        printf("%d ",A[i]);
    }

}
void imprimirOtroArr(int A[],int X[],int f,int n){
    int i,j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= f; i++)
            if (A[i]!=X[i]) {
                printf("%d ",A[i]);
            }

        
    }
}

int validarSuma(int e,int *sumaParcial,int suma){
    if (sumaParcial+e <=suma) {
        *sumaParcial=sumaParcial+e;
        return 1;
    }
    return 0;

}

int hallarConjuntos(int A[],int n,int *sumaParcial ,int suma){
    int X[],f=n/2;
    X[f];
    
    int sumParcial;
    if(sumaParcial==suma/2){
        imprimir(X,f);        
        if(n % 2 == 0)            
            imprimirOtroArr(A,X,f);
        else
            imprimirOtroArr(A,X,f+1,n);
    }
    int i;
    for (i = 0; i < n; i++) {
        if(validarSuma(A[i],&sumaParcial,suma)){
            X[i]=A[i];
            if(hallarConjuntos(A,n,&sumaParcial ,suma)){
                return 1;
            }
            X[i]=0;
        }    
    }
    return 0;
}
int main(int argc, char** argv) {
    int n=10;
    int A[]={3,4,5,-3,100,1,89,54,23,20};
    int i,suma=0;
    for(i=0;i<n;i++){
        suma=suma+A[i];
    }
    hallarConjuntos(A,n,suma);
    return (EXIT_SUCCESS);
}

