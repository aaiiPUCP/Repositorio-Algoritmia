#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100 
#define INF 10000000

void reconstruir(int paso[ ], char cadenas[ ][ N ], int n){
    int cantLineas, pos, X[ N ], Y[ N ], i, j;
    cantLineas = 0;
    pos = n;
    // vamos a reconstruir las líneas, pero quedará al revés
    // Ejm:
    // palabra4 .. palabra4 ->  X[ 0 ] = 4 , Y[ 0 ] = 4
    // palabra2 .. palabra3 ->  X[ 1 ] =2 , Y[ 0 ] = 3
    // palabra1 .. palabra1 -> X[ 2 ] = 1, Y[ 2 ] = 1  
    while( pos > 0 ){
        X[ cantLineas ] = paso[ pos ], Y[ cantLineas ] = pos;
        cantLineas = cantLineas + 1;
        pos = paso[ pos ] - 1;
    }
    // Ahora sólo recorremos los arreglos al revés y tendremos
    // la solución esperada
    for( i = cantLineas-1 ; i>=0; i-- ){
        for( j = X[ i ]; j<= Y[ i ]; ++j ){
            if( j == X[ i ] ) printf("%s", cadenas[ j ] );
            else printf(" %s", cadenas[ j ] );
        }
        printf("\n");
    }
}

int minimoCosto( int dp[ ], int costo[ ][ N ], int paso[ ], int n ){
    /******************************************************************************************
        dp[ j ] = minimo costo al resolver el problema original con las palabras desde 1 hasta j
    ******************************************************************************************/
    dp[ 0 ] = 0;
    int i, j;
    // el j representa la palabra fin en la última línea del problema original con las palabras desde 1 hasta j
    for( j=1; j<= n; j++ ){
        dp[ j ] = INF;
        // el i nos dirá la palabra inicio para la línea antes mencionada
        for( i = 1; i<= j ; ++i ){
            // probamos con todos los posibles i y luego resolvemos
            // el problemas original con fin  i-1 , el cual ya lo tenemos calculado
            // previamente en el dp, y nos quedamos con el óptimo
            if( dp[ i -1 ] + costo[ i ][ j ] < dp[ j ] ){
                dp[ j ] = dp[ i -1 ] + costo[ i ][ j ];
                paso[ j ] = i; //guardamos el i óptimo para la reconstrucción
            }
        }
    }
    return dp[ n ];
}

void procesarCostos( int costo[ ][ N ], int tamano[ ], int n, int d){
    /*********************************************************************************************
        cantCaracteres[ i ][ j ] = numero de caracteres usado al colocar las palabras i, i+1, ... j
        costo[ i ][ j ] = costo de colocar en un línea las palabras i, i+1, ... j
    ***********************************************************************************************/
    int i,j;
    int cantCaracteres[ N ][ N ];
    // llenamos matriz cantCaracteres
    for( i=1; i<= n; ++i ){
        for( j=i; j<=n; ++j ){
            if( j == i ) cantCaracteres[ i ][ j ] = tamano[ i ];
            else cantCaracteres[ i ][ j ] = cantCaracteres[ i ][ j-1 ] + 1 + tamano[ j ]; //se suma 1 por el espacio en blanco
        }
    } 
    // llenamos matriz de costo
    for( i=1; i<= n; ++i ){
        for( j=i; j<=n; ++j ){
            if( cantCaracteres[ i ][ j ] > d ) costo[ i ][ j ] = INF; // no es posible colocar todas la palabras desde i hasta j
            else costo[ i ][ j ] = ( d - cantCaracteres[ i ][ j ] ) * ( d - cantCaracteres[ i ][ j ] );
        }
    } 
}

int main(int argc, char** argv) {
    int n, d, i ;
    char cadenas[ N ][ N ]; // matriz que guardará las cadenas leídas
    int dp[ N ], tamano[ N ], costo[ N ][ N ], paso[ N ];
    scanf("%d %d", &n ,&d);
    for( i = 1; i<=n; ++i ){
        scanf("%s", cadenas[ i ] );
        tamano[ i ] = strlen( cadenas[ i ] );
    }
    procesarCostos( costo, tamano, n, d );
    printf("%d\n", minimoCosto( dp, costo, paso, n ) );
    reconstruir( paso, cadenas, n );
}
