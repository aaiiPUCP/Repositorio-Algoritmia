#include <stdio.h>
#include <stdlib.h>
/*Estrategia a utilizar: Se elaborará un procedimiento iterativo que funcione de
la misma manera que un procedimiento recursivo por medio de la utilización de
pilas expliícitas. Para ello se definirá una pila especial para QuickSort, puesto
que sus nodos podran almacenar el valor de inicio y el de fin. El puntero del
arreglo no se almacenará en la pila puesto que siempre es el mismo y se puede
utilizar el mismo puntero que se el entrega al procedimiento iterativo*/
/*Definición de la Pila Explícita para QuickSort*/
typedef struct Nodo{
  int ini; //Valor inicio de QuickSort
  int fin; //Valor de fin de QuickSort
  struct Nodo* next; //Siguiente Nodo en la pila
}TNodo;

typedef struct Pila{
  TNodo* cabeza; //Puntero al primer Nodo
}TPila;

void iniciarPila(TPila* P){
  P->cabeza=NULL; //Al inicio la pila no tiene ningún elemento
}

void apilar(TPila* P, int ini, int fin){
  TNodo* new=(TNodo*)malloc(sizeof(TNodo)); //Separación y asignación del espacio de memoria
  new->ini=ini; //Asignación de los valores
  new->fin=fin;
  if(P->cabeza==NULL){
    P->cabeza=new; //De no tener elementos, el nuevo nodo será la cabeza.
    P->cabeza->next=NULL; //NULL marca el fin de la pila
  }
  else{
    new->next=P->cabeza; //Se añade la pila por arriba y se
    P->cabeza=new;      //crea el enlace al elemento siguiente
  }
}

void desapilar(TPila* P, int* ini, int* fin){
  *ini=P->cabeza->ini; //Se sacan los valores de la pila
  *fin=P->cabeza->fin; //Por medio de punteros
  TNodo* aux=P->cabeza; //Se elimina el primer elemento de la pila
  P->cabeza=P->cabeza->next; //Y se enlaza con el que le seguía a la cabeza
  free(aux); //Se libera el espacio de memoria
}

/* Función para particionar: Se toma el último elemento como pivote, se coloca en su posición correcta en el arreglo ordenado.
	Para esto se coloca a la izquierda todos los elementos menores al pivote y a la derecha todos los mayores al pivote.
	Devuelve el índice correspondiente a la posición correcta del pivote*/
int particionar(int arr[], int inicio, int fin)
{
    int pivote = arr[fin];    // Valor del pivote
    int i = (inicio - 1);  // Variable para hacer seguimiento al índice del pivote.
 	int aux = 0; // Variable auxiliar para el intercambio
    for (int j = inicio; j <= fin - 1; j++)
    {
        // Si el elemento es menor o igual al pivote
        if (arr[j] <= pivote)
        {
            i++;    // Incrementar el índice y pasar el elemento al lado izquierdo
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    //Colocar el pivote en la posición correspondiente y retornar esta posición
    aux = arr[i + 1];
    arr[i + 1] = arr[fin];
    arr[fin] = aux;
    return (i + 1);
}

/* Función QuickSort Recursiva */
void quickSort(int arr[], int inicio, int fin)
{
    if (inicio < fin)
    {
        /* i_pivote es el índicie del pivote */
        int i_pivote = particionar(arr, inicio, fin);

        // Ordenar el lado derecho y el lado izquierdo
        quickSort(arr, inicio, i_pivote - 1);
        quickSort(arr, i_pivote + 1, fin);
    }
}

/* Función QuickSort Iterativa */
void quickSortIterativa(int arr[], int inicio, int fin)
{
	TPila Stack;
  iniciarPila(&Stack); //Se crea e inicializa la Pila
  apilar(&Stack,inicio,fin); //Se apila los valores iniciales de QuickSort
  int i, f; //Serán las variables que rescatarán los valores de la pila
  while(Stack.cabeza!=NULL){ //Mientras hallan nodos en la Pila
    desapilar(&Stack,&i,&f); //Rescato los valores del nodo y lo elimino
    if (i<f){ //Si se cumple la condición se realiza el bucle
     int i_pivote=particionar(arr,i,f);
     apilar(&Stack,i,i_pivote-1); //Como el buble tiene llamadas recursivas, se
     apilar(&Stack,i_pivote+1,f); //apilan los datos que realizará QuickSort
   }
  }
}

/* Impresión del arreglo */
void imprimirArreglo(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	int n = 6;
    int arr[6] = {10, 7, 8, 9, 1, 5};
    quickSortIterativa(arr, 0, n-1); //Reemplazo por el procedimiento iterativo
    printf("Arreglo ordenado:\n");
    imprimirArreglo(arr, n);
    return 0;
}
