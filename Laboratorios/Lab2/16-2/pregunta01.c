#include <stdio.h>
#include <stdlib.h>

/*Solución del Problema 1 - Lab2 (2016-2) INF 263 Algoritmia - PUCP
    "Contar la cantidad de tripletas tal que la diferencia entre el mayor y el menor no excedan d"

  Estrategia algorítmica: Backtracking

*/

int numFormas = 0; //Variable que almacena el numero de soluciones
int valores[3];    //Arreglo auxiliar que almacena los valores escogidos (max 3)
int A[10000];      //El arreglo de entrada

/*Nuestro algoritmo recibe como entrada
    - A:        Arreglo de entrada
    - n:        Tamaño de A
    - index:    desde donde se inicia la busqueda de numeros
    - index2:   indice del numero en la tripleta que busco (solo asume valores 0, 1, 2)
    - d:        parámetro de la diferencia maxima entre tripletas

*/
void backtracking(int A[], int n, int index, int index2, int d){


    if(index2 == 2){ // Si ya escogí dos numeros?
        if((valores[1] - valores[0])>d){
            return; //Si la diferencia entre los dos numeros es mayor a d, "NO EXISTEN" tripletas con estos numeros
        }
    }else if(index2 == 3){  //Si ya escogí tres numeros?
            if((valores[2] - valores[0])>d){
                return; //Si la diferencia entre mayor y menor excede d, no pasa nada
            }else{
                numFormas++;    //Tripleta cumple con condición, entonces la contamos
                return;
            }
    }

    /*Si llegamos a este punto es por dos razones:
        - Estamos buscando el primer elemento de la tripleta ó
        - Los dos primeros elementos de una tripleta no exceden d
      Afortunadamente, ambos casos se pueden manejar por igual
    */
    int i;

    //Nuestro bucle empieza en index porque es desde ahi donde debo buscar el siguiente elemento de la tripleta
    for(i = index; i < n; i++){
        valores[index2] = A[i]; //Tomamos la decisión
        backtracking(A, n, i + 1, index2 + 1, d); //Dejamos que backtracking haga el resto del trabajo
    }
}

int main(int argc, char* argv[]){
    int numCasos;
    int n,d;

    numFormas = 0; //Inicializamos el contador de soluciones
    scanf("%d", &n); //Leemos la cantidad de numeros
    scanf("%d", &d); //Leemos el parametro de distancia

    //Leemos el arreglo
    int j;
    for(j = 0; j < n; j++)
        scanf("%d", &A[j]);

    //Invocamos a nuestra función que empieza a buscar desde el inicio y sin elementos en la tripleta al inicio
    backtracking(A, n, 0, 0, d);

    //Imprimir la solucion del caso
    printf("%d\n", numFormas);

}
