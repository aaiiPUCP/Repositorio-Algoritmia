#include <stdio.h>
#include <stdlib.h>
/*no es necesario indicar estrategia alguna para esta pregunta*/

typedef int TInfo; // Asignar el alias TInfo para el tipo de dato int

typedef struct Nodo{  // Definición de la estructura Nodo
	TInfo elemento;   // Elemento a almacenar en un nodo de la lista.
	struct Nodo* sig; // Puntero a una estructura Nodo.
} TNodo; // Asignar el alias TNodo para el tipo de dato Nodo*




typedef struct Lista{ //NOTA: SE HA MODIFICADO LA DEFINICIÓN DE LISTA.
	TNodo* primero;
} TLista;




TNodo* crearNodo(TInfo elem) {
	TNodo* nuevo = (TNodo*)malloc(sizeof(TNodo)); // Separar memoria para el nuevo nodo.
	nuevo->elemento = elem; // Asginar el elemento
	nuevo->sig = NULL; // Apuntar el puntero siguiente a NULL
	return nuevo; // Devolver el puntero al nodo. 
}

void imprimirLista(TLista lista) {
	//imprimir la lista
	TNodo *curr=lista.primero;
	while (curr!=NULL){
		printf("%d ",curr->elemento);
		curr=curr->sig;
	}
	printf("\n");
}

void imprimirRecursiva(TNodo* nodo, TLista* L) {
	if (nodo==NULL){
		return;
	}
	imprimirRecursiva(nodo->sig, L);
	printf("%d ",nodo->elemento);
	if (nodo==L->primero){
		printf("\n");
	}
}

TNodo* newIni=NULL; //Se necesita debido a la modificación realizada de la implementación de Listas simples
void invertirRecursiva2(TNodo* N) {
	if(N->sig==NULL){
		newIni=N;
		return;
	}
	TNodo* aux=N;
	invertirRecursiva2(N->sig);
	aux->sig->sig=aux;
	aux->sig=NULL;
	return;
}

void agregarNodo(TLista* lista,TInfo elem){
	//Agrega un elemento al final de la lista
	if (lista->primero==NULL){
		lista->primero=crearNodo(elem);
	}
	else{
		//Busca el último elemento y agrega un nodo al final
		TNodo* curr=lista->primero;
		while (curr->sig!=NULL){
			curr=curr->sig;
		}
		curr->sig=crearNodo(elem);
	}
}

void invertirRecursiva(TLista* lista) {
	//invertir la lista de manera recursiva podiendo crear nuevos nodos
	if (lista->primero->sig==NULL){
		//si solo queda un elemento, ya no se hace nada
		return;
	}
	TNodo* aux=lista->primero;
	TInfo e=aux->elemento;
	lista->primero=lista->primero->sig;
	free(aux);
	invertirRecursiva(lista);
	agregarNodo(lista,e);

}
//Procedimiento necesario por la modificación de la especificación para la terminación de invertirRecursiva2
void reacomodarPuntero(TLista* L){
	TNodo* aux=L->primero;
	while (aux->sig!=NULL){
		aux=aux->sig;
	}
	L->primero=aux;
} 



int main(void){
	//inicializar la lista
	TLista L;
	L.primero=NULL;
	//Crear la lista
	agregarNodo(&L,1);
	agregarNodo(&L,2);
	agregarNodo(&L,3);
	agregarNodo(&L,4);
	agregarNodo(&L,5);
//agregarNodo(&L,6);
//agregarNodo(&L,7);
//agregarNodo(&L,8);
//agregarNodo(&L,9);
//agregarNodo(&L,10);
	//imprimir la lista
	printf("La lista creada es: ");
	imprimirLista(L);
	//Imprimir en el orden inverso sin cambiar la lista
	printf("La lista en orden inverso es (sin alterarlo): ");
	imprimirRecursiva(L.primero, &L);
	printf("La lista invertida es: ");
	invertirRecursiva(&L);
	imprimirLista(L);
	printf("La lista invertida nuevamente (sin la creación de nodos) es: ");
	invertirRecursiva2(L.primero);
	//NOTA: Debido a la nueva modificación de lista que se realizó necesariamente
	//se necesita reacomodar la direccion de lista.primero que se guarda en una
	//variable auxiliar.
	//Sin embargo, la conexión de los nodos fue invertida sin utilizar agregarNodo
	//ni recorriendo el arreglo enm una iterativa, todo mediante recursión.
	L.primero=newIni; //Redirección de la cabeza de L
	imprimirLista(L);
	return 0;
}