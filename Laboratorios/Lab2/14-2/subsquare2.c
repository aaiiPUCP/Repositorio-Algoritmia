#include <stdio.h>

#define N 6
#define N2 3

int min(int a, int b);
void readMatrix(int mat[N][N]);
void printMatrix(int mat[N][N]);
void printMatrix2(int mat[N + 1][N + 1][N2]);
int findSubSquare1(int mat[N][N], int iF, int jF);
void findSubSquare2(int mat[N][N], int mat2[N + 1][N + 1][N2]);
void subSolve(int mat[N][N], int mat2[N + 1][N + 1][N2], int i, int j);
void setTriplet(int arr[], int a, int b, int c);
void copyTriplet(int arr[], int arr2[]);

int main(int argc, char** argv) {
    int mat[N][N];
    int mat2[N + 1][N + 1][N2];
    readMatrix(mat);
    findSubSquare2(mat, mat2);
    printMatrix2(mat2);
    return 0;
}

/*
 * Ya que nuestros casos triviales serán para matrices con cero elementos,
 * por conveniencia, nuestra matriz respuesta será de (N+1)x(N+1)
 * (utilizaremos la dimensión adicional para las matrices de cero elementos,
 * las cuales no son parte de lo que la pregunta solicita pero nos
 * serán de utilidad para calcular las demás soluciones;
 * al momento de imprimir solo mostraremos una matriz de NxN),
 * El casillero (i, j) de mat2 contiene la solución para la submatriz
 * formada por las filas desde 0 a i - 1 y columnas desde 0 a j - 1.
 * Como se puede notar, cuando i = 0 o cuando j = 0, estaremos ante
 * una submatriz de cero elementos.
 */
void findSubSquare2(int mat[N][N], int mat2[N + 1][N + 1][N2]) {
    int i, j;
    
    // Para las submatrices de cero elementos, no existe ningún cuadrado
    // Con esto resolvemos los subproblemas en la fila 0 y columna 0
    for (i = 0; i < N + 1; i++) {
        // Convención para indicar que no hay solución
        // (-1 , -1 , 0)
        setTriplet(mat2[0][i], -1, -1, 0);
        setTriplet(mat2[i][0], -1, -1, 0);
    }
    
    // Resolver los demás subproblemas
    for (i = 1; i < N + 1; i++) {
        for (j = 1; j < N + 1; j++) {
            subSolve(mat, mat2, i, j);
        }
    }
}

/*
 * Resolver el subproblema i, j
 * Para esto, usaremos las soluciones de 2 subpoblemas:
 * (i - 1, j) y (i, j - 1), que
 * corresponden a las submatrices de arriba e izquierda
 * (eliminando la última fila y la última columna respectivamente), y
 * adicionalmente usaremos la solución al restringir que el elemento
 * de la esquina inferior derecha deba estar en el cuadrado solución
 * (la solución a esto se hizo para la pregunta 2).
 * Notamos que al elegir el mayor de estas 3, tendremos la solución
 * para el subproblema i, j
 */
void subSolve(int mat[N][N], int mat2[N + 1][N + 1][N2], int i, int j) {
    // printf("subsolving %d %d\n", i, j);
    int possibleSolutions[3][N2];
    copyTriplet(possibleSolutions[0], mat2[i - 1][j]); // arriba
    copyTriplet(possibleSolutions[1], mat2[i][j - 1]); // izquierda
    setTriplet(possibleSolutions[2], i - 1, j - 1, findSubSquare1(mat, i - 1, j - 1)); // esquina
    /*
    printf("p1: %d %d %d\np2: %d %d %d\np3: %d %d %d\n",
            possibleSolutions[0][0], possibleSolutions[0][1], possibleSolutions[0][2],
            possibleSolutions[1][0], possibleSolutions[1][1], possibleSolutions[1][2],
            possibleSolutions[2][0], possibleSolutions[2][1], possibleSolutions[2][2]);
    */
    
    /* Seleccionar la solución de mayor lado.
     * Para que tenga preferencia la solución de la esquina, en caso de
     * que hayan varios cuadrados máximos de igual lado, la usamos
     * como valor inicial y luego si las demás soluciones son mejores
     * la reemplazamos
     */
    int solution[N2];
    copyTriplet(solution, possibleSolutions[2]);
    if (possibleSolutions[1][2] > solution[2]) copyTriplet(solution, possibleSolutions[1]);
    if (possibleSolutions[0][2] > solution[2]) copyTriplet(solution, possibleSolutions[0]);
    
    // printf("sol: %d %d %d\n", solution[0], solution[1], solution[2]);
    
    /* Guardamos la solución al subproblema i, j en el casillero
     * correspondiente. Si el mayor lado es 0, entonces no hay solución y
     * nos aseguramos de seguir la convención para indicar 
     * que no hay solución
     */
    if (!solution[2]) setTriplet(mat2[i][j], -1, -1, 0);
    else copyTriplet(mat2[i][j], solution);
}

int findSubSquare1(int mat[][N], int iF, int jF) {
    int l, i, j;
    int failed = 0;
    int lMax = min(iF, jF) + 1;
    
    for (l = 0; l < lMax; l++) {
        i = l;
        j = 0;
        while (!failed && j < l) {
            if (!mat[iF - i][jF - j]) {
                failed = 1;
                break;
            }
            j++;
        }
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

void readMatrix(int mat[][N]) {
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

void printMatrix2(int mat[N + 1][N + 1][N2]) {
    int i, j;
    for (i = 1; i < N + 1; i++) {
        for (j = 1; j < N + 1; j++) {
            if (mat[i][j][2] == 0)
                printf("(     ) ");
            else
                printf("(%d,%d,%d) ", mat[i][j][0], mat[i][j][1], mat[i][j][2]);
        }
        printf("\n");
    }
}

void setTriplet(int arr[], int a, int b, int c) {
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
}

void copyTriplet(int arr[], int arr2[]) {
    arr[0] = arr2[0];
    arr[1] = arr2[1];
    arr[2] = arr2[2];
}

int min(int a, int b) {
    if (a < b) return a; else return b;
}