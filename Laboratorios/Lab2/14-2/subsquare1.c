#include <stdio.h>

#define N 6

int min(int a, int b);
void readMatrix(int mat[N][N]);
void printMatrix(int mat[N][N]);
int findSubSquare1(int mat[N][N], int iF, int jF);

int main(int argc, char** argv) {
    int mat[N][N];
    int iF, jF;
    readMatrix(mat);
    scanf("%d %d", &iF, &jF);
    printf("%d", findSubSquare1(mat, iF, jF));
    return 0;
}

int findSubSquare1(int mat[][N], int iF, int jF) {
    int l, i, j;
    int failed = 0;
    // el máximo lado posible que encontraremos
    // será el mínimo entre iF y jF más 1
    int lMax = min(iF, jF) + 1;
    
    for (l = 0; l < lMax; l++) {
        /* En cada iteración básicamente estamos
         * verificando si existe un cuadrado de lado L que cumpla
         * las restricciones indicadas. En la siguiente iteración
         * verificamos si existe un cuadrado de lado L + 1, procesando
         * solo los nuevos elementos de la matriz que todavía no
         * se han procesado. Nos basamos en que ya sabemos si existe
         * o no un cuadrado de lado L para verificar si existe uno
         * de lado L + 1. La siguiente matriz muestra de manera intuitiva
         * el orden en el que verificaremos los 1s de acuerdo a lo
         * mencionado anteriormente.
         * 3 3 3 3
         * 3 2 2 2
         * 3 2 1 1
         * 3 2 1 0
        */
        i = l;
        j = 0;
        // recorremos la nueva fila, es decir, con i fijo y j variando
        while (!failed && j < l) {
            if (!mat[iF - i][jF - j]) {
                failed = 1;
                break;
            }
            j++;
        }
        // recorremos la nueva fila, es decir, con i variando y j fijo
        while (!failed && i >= 0) {
            if (!mat[iF - i][jF - j]) {
                failed = 1;
                break;
            }
            i--;
        }
        
        if (failed) break;
    }
    
    return l;
}

void readMatrix(int mat[N][N]) {
    int n;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%1d", &n);
            mat[i][j] = n;
        }
    }
}

void printMatrix(int mat[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b) {
    if (a < b) return a; else return b;
}