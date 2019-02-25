/*
 Estreategia: Los mismo que la pregunta 2
 * solo que se hace todo en una iteracion y cuando termine de leet todas
 * las palabras recien imprime el pabrero
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

void fillMoves(int moves[8][2]){
    moves[0][0] =  1; moves[0][1] = -1;
    moves[1][0] =  1; moves[1][1] =  0;
    moves[2][0] =  1; moves[2][1] =  1;
    moves[3][0] =  0; moves[3][1] =  1;
    moves[4][0] = -1; moves[4][1] =  1;
    moves[5][0] = -1; moves[5][1] =  0;
    moves[6][0] = -1; moves[6][1] = -1;
    moves[7][0] =  0; moves[7][1] = -1;
}

void convertirMayuscula(char palabra[MAX], int len){
    int i;
    char c;
    for(i=0; i<len; i++){
        c = toupper(palabra[i]);
        palabra[i] = c;
    }
}

void fillBoard(char tablero[MAX][MAX], int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            tablero[i][j] = getchar();
            getchar();
        }
    }
}

void printBoard(char tablero[MAX][MAX], int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%c ",tablero[i][j]);
        }
        printf("\n");
    }
}

int is_valid(char tablero[MAX][MAX], int size, int x, int y){
    return x >= 0 && x < size && y >= 0 && y < size;
}

int pupiletras(char tablero[MAX][MAX], int size, char palabra[MAX], int longitud, int cont, int x, int y, int moves[8][2], int k){
    //printf("cont:%d\n",cont);
    //Caso Base: si cont es igual a la longitud de la palabra, termino porque la encontro
    if(cont == longitud){
        //printBoard(tablero, size);
        return 1;
    }
    
    char c;
    
    if(is_valid(tablero, size, x, y) && tablero[x][y] == palabra[cont]){
        
        //printf("(%d,%d)\n",x,y);
        
        c = palabra[cont];
        tablero[x][y] = tolower(c);
        
        if (pupiletras(tablero, size, palabra, longitud, cont+1, x + moves[k][0], y + moves[k][1], moves, k)){
            return 1;
        }
        else{
            c = tablero[x][y];
            tablero[x][y] = toupper(c);
            return 0;
        }
        
    }
    //La direccion de la que vino no es valida
    else
        return 0;
    
}

void buscarPalabra(char tablero[MAX][MAX], int size, char palabra[MAX], int longitud, int moves[8][2]){
    
    int i,j,m;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            //Conciden la primera letras
            if(tablero[i][j] == palabra[0]){
                //printf("->(%d,%d)\n",i,j);
                //Prueba todas las direcciones posibles
                for(m = 0; m < 8; m++){
                    
                    if(pupiletras(tablero, size, palabra, longitud, 0, i, j, moves, m)){
                        //printBoard(tablero, size);
                        return;
                    }
                    
                }      
                
            }
            
        }
    }
        
}

int main(int argc, char** argv) {
    
    int n, len, numPalabras, k;
    char tablero[MAX][MAX];
    char palabra[MAX];
    int moves[8][2];
    
    fillMoves(moves);
    
    while(1){
        scanf("%d",&n);
        if(n == -1) break;
        getchar();
        fillBoard(tablero, n);
    
        scanf("%d",&numPalabras);
        getchar();
        for(k=0; k<numPalabras; k++){
            scanf("%s",&palabra);
            len = strlen(palabra);
            convertirMayuscula(palabra, len);
            buscarPalabra(tablero, n, palabra, len, moves);
        }
        
        printBoard(tablero, n);
        
    }
    
    return (EXIT_SUCCESS);
}

