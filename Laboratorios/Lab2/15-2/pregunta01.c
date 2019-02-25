/*
 Estrategia: Divide y Venceras
 */

#include <stdio.h>
#include <stdlib.h>
#define N 8


void fillBoard(char tablero[N][N]){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            tablero[i][j] = '.';
        }
    }
}

int baldosa(char tablero[N][N], int x, int y, int size, int leftUp, int leftDown, int rightUp, int rightDown){
    //dividir el tablero el cuatro partes
    //luego esas partes dividirlas en 4
    //hasta tener cuadrado de 2x2
    if(size == 2){
        //pintar
        
    }
    else{
        baldosa(tablero, x, y, size/2, leftUp, leftDown/2, rightUp/2, rightDown/2);
        baldosa(tablero, x, y, size/2, rightUp/2, leftDown/2, rightUp, rightDown/2);
        baldosa(tablero, x, y, size/2, leftUp/2, leftDown, rightUp/2, rightDown/2);
        baldosa(tablero, x, y, size/2, rightUp/2, leftDown/2, rightUp/2, rightDown);
    }
    
}

void printBoard(char tablero[N][N]){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%c ",tablero[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    
    int x,y;
    char tablero[N][N];
    
    fillBoard(tablero);
    scanf("%d %d",&x,&y);
    tablero[x][y] = 'X';
    baldosa(tablero, x , y, N, 0, N-1, N-1, N-1);
    printBoard(tablero);
    
    return (EXIT_SUCCESS);
}

