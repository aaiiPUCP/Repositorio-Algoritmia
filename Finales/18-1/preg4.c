#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Tinfo;


//Definición de Arbol binario
typedef struct NodoAB{
	Tinfo valor;		//Valor del nodo del árbol
	struct NodoAB* izq;	//Puntero a la raiz del subarbol izquierdo
	struct NodoAB* der;	//Puntero a la raiz del subarbol derecho
}TNodoAB;

typedef struct AB{
	TNodoAB* raiz;		//Puntero al nodo raiz del AB
}TAB;

//Se usaran dos pilas que almacenes punteros a los nodos del AB
typedef struct NodoP{
	TNodoAB* nodoAB; 
	struct NodoP* next;
}TNodoP;

typedef struct Pila{
	TNodoP* head;
}TPila;

void iniciar_AB(TAB* Arbol, Tinfo valor){
	TNodoAB* new=(TNodoAB*)malloc(sizeof(TNodoAB)); //inicializacion del AB con un valor cualqueirda
	new->izq=NULL;
	new->der=NULL;
	new->valor=valor;
	Arbol->raiz=new;
}

void anadir_izq(TNodoAB* padre, Tinfo valor){
	//anadir un nuevo nodo a la izquierda de un nodo
	//REQUISITO, el hijo izquierdo deberá ser vacio
	assert(padre->izq==NULL);
	TNodoAB* new=(TNodoAB*)malloc(sizeof(TNodoAB));
	new->izq=NULL;
	new->der=NULL;
	new->valor=valor;
	padre->izq=new;
}

void anadir_der(TNodoAB* padre, Tinfo valor){
	//anadir un nuevo nodo a la izquierda de un nodo
	//REQUISITO, el hijo derecho deberá ser vacio
	assert(padre->der==NULL);
	TNodoAB* new=(TNodoAB*)malloc(sizeof(TNodoAB));
	new->izq=NULL;
	new->der=NULL;
	new->valor=valor;
	padre->der=new;
}

void iniciar_pila(TPila* Pila){
	Pila->head=NULL; //Primero la pila está vacía.
}

void push(TPila* Pila, TNodoAB* Nodo){
	TNodoP* new=(TNodoP*)malloc(sizeof(TNodoP));
	new->nodoAB=Nodo;
	new->next=Pila->head;
	Pila->head=new;
	//En este procedimiento se está insertando un nodo nuevo a la pila
}

TNodoAB* pull(TPila* Pila){
	TNodoP* aux=Pila->head;
	Pila->head=Pila->head->next; //Se devuelve el nodo que AB que tiene el nodo del head
	TNodoAB* res=aux->nodoAB;
	free(aux); //Se libera el head
	return res;
}

void fin_pila(TPila* Pila){
	while (Pila->head!=NULL){
		TNodoP* aux=Pila->head;
		Pila->head=Pila->head->next;
		free(aux);
	}
}


TPila posorder(TAB* Arbol){
	//Como lo explicado en el cuadernillo, se utilizarán 2 pilas
	TPila recorrido;
	TPila nodos;
	iniciar_pila(&recorrido);
	iniciar_pila(&nodos);
	//En la pila de nodos se inicia con la raiz
	push(&nodos,Arbol->raiz);
	while(nodos.head!=NULL){
		//Mientras aun hayan nodos en la pila:
		TNodoAB* curr;
		curr=pull(&nodos);
		if (curr->izq!=NULL){
			push(&nodos,curr->izq);
		}
		if(curr->der!=NULL){
			push(&nodos,curr->der);
		}
		push(&recorrido,curr);
	}
	fin_pila(&nodos);
	return recorrido;
}

void fin_AB(TAB* Arbol){
	TPila recorrido;
	recorrido=posorder(Arbol); //obtendrá la pila con el recorrido en posorder
	while(recorrido.head!=NULL){
		TNodoAB* curr=pull(&recorrido); //recorre el arbol  en posorder, imprime el valor 
		printf("%d ",curr->valor);
		free(curr);						//elimina el nodo al terminar
	}
	printf("\n");
	fin_pila(&recorrido);
}

int main(){
	TAB arbol;
	iniciar_AB(&arbol, 5);
	anadir_izq(arbol.raiz,3);
	anadir_der(arbol.raiz,4);
	anadir_izq(arbol.raiz->izq,1);
	anadir_der(arbol.raiz->izq,2);
	//	    5
	//	  /	 \
	//	 3    4 	Posorden:[1,2,3,4,5]
	//	/ \
	// 1   2
	printf("Recorrido posorden: \n");
	fin_AB(&arbol);
	return 0;
}
