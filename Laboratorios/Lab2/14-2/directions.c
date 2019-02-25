#include <stdio.h>

#define N 10

int nextNumberIsValid(int currentNumber, int nextNumber);
void printMatrix(int mat[N][N]);
void readMatrix(int mat[N][N]);
int findPath(int mat[N][N], int i, int j, int i2, int j2);

int main(int argc, char** argv) {
    int mat[N][N];
    int iF, jF, i0, j0;
    readMatrix(mat);
    scanf("%d %d %d %d", &i0, &j0, &iF, &jF);
    if (!findPath(mat, iF, jF, i0, j0)) {
        printf("no hay solución");
    }
    putchar('\n');
    return 0;
}

/* Como nuestra primera impresión de dirección la haremos
 * al llegar a la "meta", pues en ese momento sabemos que encontramos
 * respuesta, si tratamos de ir desde la posición
 * inicial a la posición final, nuestra secuencia de direcciones
 * se imprimirá al revés. Por eso comenzaremos en la posición final y
 * trataremos de llegar a la posición inicial. En realidad el proceso
 * es casi el mismo, pero lo hacemos de esta manera por conveniencia
 * para poder imprimir las direcciones en el orden solicitado de
 * manera inmediata sin tener que acumular las direcciones en un
 * arreglo de caracteres para imprimirlo después.
 * (i, j) es la posición a la cual se quiere llegar desde (i2, j2).
 * En cada paso revisaremos si es posible haber llegado a (i, j)
 * viniendo de alguna de las cuatro direcciones (un solo paso)
 * de manera que en algún momento se haya venido originalmente de
 * la posición inicial (i, j) y si es posible, imprimimos la dirección.
 * El caso base es cuando (i, j) es igual a (i2, j2), en cuyo caso
 * sabemos que sí es posible encontrar un camino desde (i, j) a (i2, j2).
 * Las celdas ya usadas las marcaremos con números negativos.
 * La función devuelve 1 si es posible encontrar un camino y 0 si no.
 */
int findPath(int mat[N][N], int i, int j, int i2, int j2) {
    int currentNumber = mat[i][j];
    
    if (i == i2 && j == j2) {
        // caso base
        // marcar celda como ya usada (negativa)
        mat[i][j] *= -1;
        return 1;
    } else {
        // marcar celda como ya usada (negativa)
        mat[i][j] *= -1;
        
        // verificar si se pudo haber venido de abajo
        if (// la posición debe existir
            i + 1 < N &&
            // el contenido de la celda debe seguir el patrón 123
            nextNumberIsValid(mat[i + 1][j], currentNumber) &&
            // debe ser una celda todavía no usada
            mat[i + 1][j] > 0 &&
            // debe ser posible llegar a (i + 1, j) desde (i2, j2)
            findPath(mat, i + 1, j, i2, j2)) {
            // como verificamos si es posible haber venido de abajo,
            // la dirección es arriba.
            printf("R");
            return 1;
        } else
        // verificar si se pudo haber venido de arriba
        if (i - 1 >= 0 &&
            nextNumberIsValid(mat[i - 1][j], currentNumber) &&
            mat[i - 1][j] > 0 &&
            findPath(mat, i - 1, j, i2, j2)) {
            printf("B");
            return 1;
        } else
        // verificar si se pudo haber venido de la izquierda
        if (j - 1 >= 0 &&
            nextNumberIsValid(mat[i][j - 1], currentNumber) &&
            mat[i][j - 1] > 0 &&
            findPath(mat, i, j - 1, i2, j2)) {
            printf("D");
            return 1;
        } else
        // verificar si se pudo haber venido de la derecha
        if (j + 1 < N &&
            nextNumberIsValid(mat[i][j + 1], currentNumber) &&
            mat[i][j + 1] > 0 &&
            findPath(mat, i, j + 1, i2, j2)) {
            printf("I");
            return 1;
        } else {
            return 0;
        }
    }
}

int nextNumberIsValid(int currentNumber, int nextNumber) {
    return nextNumber == (currentNumber) % 3 + 1;
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