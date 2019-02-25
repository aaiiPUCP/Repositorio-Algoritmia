
#include <stdio.h>
#include <string.h>
#define N 10

/*
 Buscar todas las palabras iniciando desde todas las posiciones i,j de la matriz
 Si la longitud de las palabras es mayor o igual a 3 entonces considerar imprimirla
 si pertenece al diccionario entonces no imprimirla
 si no pertenece entonces imprimirla
 */

void leerMatriz(char matriz[N][N],int n);
void sacarPalabras(char matriz[N][N],int n, char palabra[], int m, int x, int y);
void append(char matriz[N][N], int x, int y, char palabra[], int m, char newPalabra[]);
int perteneceDiccionario(char palabra[], int m);
int isValid(char matriz[N][N], int n, char palabra[], int m, int x, int y, int i);
void initMov();
void add(char palabra[], int m);

char diccionario[100][20];
int count;
int mov[8][2];

int main(int argc, char** argv) {

    initMov();
    int i,j,n;
    char matriz[N][N], c;
    int casos;
    char palabra[20] = "";
    scanf("%d\n",&casos);
    while(casos--){
        scanf("%d\n",&n);   
        leerMatriz(matriz,n);
        count = 0;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++){
                palabra[0] = matriz[i][j];
                sacarPalabras(matriz,n,palabra,1,i,j);
            }
        printf("\n");
    }
    
    return 0;
}

void leerMatriz(char matriz[N][N],int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%c",&matriz[i][j]);
        }
        scanf("\n");
    }
}

void printArray(char array[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%c",array[i]);
    }
    printf("\n");
}

void sacarPalabras(char matriz[N][N],int n, char palabra[], int m, int x, int y){

    if(m>=3){
      
        if(perteneceDiccionario(palabra,m) == 0){
            printArray(palabra,m);
            add(palabra,m);
        }
    }
    int i,newx,newy;
    char newPalabra[20];
    for(i=0; i<8; i++){
        if(isValid(matriz,n,palabra,m,x,y,i) == 1){
            newx = x + mov[i][0];
            newy = y + mov[i][1];
            append(matriz,newx,newy,palabra,m,newPalabra);
            sacarPalabras(matriz,n,newPalabra,m+1,newx,newy);
        }
    }
    
}

int perteneceDiccionario(char palabra[], int m){
    
    char aux[m];
    strlcpy(aux, palabra, m+1);
    
    for(int i = 0; i < count; i++) {
        int res = strcmp(diccionario[i], aux);
        if(res == 0) {
            return 1;
        }
    }
    return 0;
}

void add(char palabra[], int m){
    int i;
    for(i=0; i<m; i++){
        diccionario[count][i] = palabra[i];
    }
    count++;
}

void append(char matriz[N][N], int x, int y, char palabra[], int m, char newPalabra[]){
    int i;
    for(i=0; i<m; i++)
        newPalabra[i] = palabra[i];
    newPalabra[m] = matriz[x][y];
}

int isValid(char matriz[N][N], int n, char palabra[], int m, int x, int y, int i){
    if(m == 0) return 1;
    int newx = x + mov[i][0];
    int newy = y + mov[i][1];
    if(newx>=0 && newx <n && newy>=0 && newy<n){
        if(matriz[newx][newy] > palabra[m-1])
            return 1;
    }
    return 0;
}

void initMov(){
    mov[0][0] = 0; //derecha
    mov[0][1] = 1;
    mov[1][0] = 1; // dercha abajo
    mov[1][1] = 1;
    mov[2][0] = 1; // abajo
    mov[2][1] = 0;
    mov[3][0] = 1; // abajo izquierda
    mov[3][1] = -1;
    mov[4][0] = 0; // izquierda
    mov[4][1] = -1;
    mov[5][0] = -1; // iizquierda arriba
    mov[5][1] = -1;
    mov[6][0] = -1; // arriba
    mov[6][1] = 0;
    mov[7][0] = -1; // arriba derecha
    mov[7][1] = 1;
}
 