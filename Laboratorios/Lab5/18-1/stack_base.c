#include <stdio.h>
#include <stdlib.h> 

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
	/*
	*
	*   Implemente esta función.
	*
	*/
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
    quickSort(arr, 0, n-1);
    printf("Arreglo ordenado:\n");
    imprimirArreglo(arr, n);
    return 0;
}