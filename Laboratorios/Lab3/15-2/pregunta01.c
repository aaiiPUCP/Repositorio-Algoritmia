/*
 Estrategia: Se basa en aplicar dos veces el algoritmo del coinRow
 * la primera es para sacar la maxima suma no adyacente por fila
 * y se va almacenando esa suma en un arreglo
 * a ese arreglo se le aplica nuevamente el coinRow para sacar
 * la maxima suma no adyacente debido a que cuando se elige un
 * numero ya no se utiliza la fila superior e inferior
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void pprint(int fil, int col, int tablero[MAX][MAX]){
    int i,j;
    
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            printf("%3d ",tablero[i][j]);
        }
        printf("\n");
    }
}

void fillBoard(int fil, int col, int tablero[MAX][MAX]){
    int i,j;
    
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            scanf("%d",&tablero[i][j]);
        }
    }
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}

//Otra vez el algoritmo del coin row
//Debido a que se eliminar la fila superior e inferior
//Entonces es como tomar la maxima suma no adyacente
int maxSuma(int sum[MAX], int size){
    int arr[MAX];
    int i;
    
    arr[0] = 0;
    arr[1] = sum[0];
    for(i=2; i<=size; i++){
        arr[i] = max(sum[i-1] + arr[i-2], arr[i-1]);
    }
    return arr[size];
}

//El problema se basa en el algoritmia del coin row
//Debido a que se necesita la maxima suma no adyacente
int maxSumaFila(int tablero[MAX][MAX], int fil, int col){
    int arr[MAX];
    int i;
    
    arr[0] = 0;
    arr[1] = tablero[fil][0];
    for(i=2; i<=col; i++){
        
        arr[i] = max(tablero[fil][i-1] + arr[i-2], arr[i-1]);
    }
    return arr[col];
}


int maxSum(int tablero[MAX][MAX], int fil, int col){
    int i, sum[MAX], cont;
    cont = 0;
    //Por cada fila se hallara la maxima suma no adyacente
    for(i=0; i<fil; i++){
        sum[cont] = maxSumaFila(tablero, i, col);
        cont++;
    }
    
    //for(i=0; i<cont; i++) printf("%d\n", sum[i]);
    
    //Luego como se tiene en un arreglo las sumas maximas por filas
    //Se vuelve a aplicar LIS para hallar la maxima suma no adyacente
    return maxSuma(sum, cont);
}

int main(int argc, char** argv) {
    int n,m;
    int tablero[MAX][MAX];
    
    while(scanf("%d %d",&m,&n) == 2){
        
        if(m == 0 && n == 0) break;
        
        fillBoard(m,n,tablero);
        
        printf("%d\n", maxSum(tablero,m,n));
        printf("\n");
        //pprint(m,n,tablero);
    }
    
    return (EXIT_SUCCESS);
}

