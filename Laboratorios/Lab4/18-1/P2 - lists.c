#include <stdio.h>
#include <stdlib.h>

typedef int TInfo; // Asignar el alias TInfo para el tipo de dato int

typedef struct Nodo{  // Definición de la estructura Nodo
	TInfo elemento;   // Elemento a almacenar en un nodo de la lista.
	struct Nodo* sig; // Puntero a una estructura Nodo.
} TNodo; // Asignar el alias TNodo para el tipo de dato Nodo*

typedef TNodo* TLista; //Asignar el alias TLista para el tipo de dato Nodo*

TNodo* crearNodo(TInfo elem) {
	TNodo* nuevo = (TNodo*)malloc(sizeof(TNodo)); // Separar memoria para el nuevo nodo.
	nuevo->elemento = elem; // Asginar el elemento
	nuevo->sig = NULL; // Apuntar el puntero siguiente a NULL
	return nuevo; // Devolver el puntero al nodo. 
}

void imprimirLista(TLista lista) {
	//Completar
	printf("\n");
}

void imprimirRecursiva(TLista lista) {
	//Completar
}

void imprimirLista2(TLista lista) {
	imprimirRecursiva(lista);
	printf("\n");
}

void agregarNodo(TLista lista,TInfo elem){
	//Completar
}

void inverirRecursiva(TLista* lista) {
	//Completar
}

int main(void){
	//Completar
	return 0;
}