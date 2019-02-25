/*
 * L(i)=longitud de la secuencia mas larga con n/2 elementos
 * L(i)=1+max j= 0,1,..i-1{L(j)/Xj<Xi}, i>0
 * L(0)=1
 * 
 * se uas una variante de lis la diferencia es que debo comparar los elementos
 * del arreglo A con el del arreglo B, es decir se compara el segundo elemento
 * de la tupla con el primer elemento de la tupla siguiente
 */

/* 
 * File:   pregunta4.c
 * Author: alulab14
 *
 * Created on 12 de mayo de 2018, 12:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int Lis(int A[],int B[],int N){
    int L[N];
    int i;
    for (i = 0; i < N; i++) L[i]=0;

    L[0]=1;
    
    int j,max;
    
    for (i = 1; i < N; i++) {
        max=0;
        for (j = 0; j < i; j++){
            if(B[j]<A[i]){
                if(L[j]>max)
                    max=L[j];
            }
        }
        L[i]=1+max;
    }
    
    max=L[0];
    
    for (i = 0; i < N; i++) {
        if(L[i]>max)
            max=L[i];
    }
    return max;

}

int main(int argc, char** argv) {
    int n=5;
    //donde el arreglo A contiene todos los elementos
    //pares del arreglo y el arreglo B contiene todos los elementos impares
    //del arreglo
    int A[]={5,39,15,27,50};
    int B[]={24,60,28,40,90};
    printf("%d",Lis(A,B,n));
    
    return (EXIT_SUCCESS);
}

