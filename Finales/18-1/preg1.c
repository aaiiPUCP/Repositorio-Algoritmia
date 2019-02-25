#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Tinfo;

typedef struct Nodo{
	Tinfo valor;		//Valor del nodo del árbol
	struct Nodo* izq;	//Puntero a la raiz del subarbol izquierdo
	struct Nodo* der;	//Puntero a la raiz del subarbol derecho
}TNodo;

typedef struct ABB{
	TNodo* raiz;		//Puntero al nodo raiz del ABB
}TABB;

void iniciar_ABB(TABB* Arbol){
	Arbol->raiz=NULL; //Cuando se inmicia un arbol, no tiene raiz
}

void anadir_ABB(TABB* Arbol, Tinfo valor){
	TNodo* aux=Arbol->raiz; //Nodo auxiliar para hallar la posición a insertar
	TNodo* new=(TNodo*)malloc(sizeof(TNodo));
	
	new->valor=valor; //Se inicializa el nuevo nodo
	new->izq=NULL;
	new->der=NULL;

	if (aux==NULL){
		Arbol->raiz=new;
		return;
	}

	while(1){
		if (aux->valor>valor){

			if(aux->izq!=NULL){
			aux=aux->izq; //debe ir a la izquierda del nodo aux
			}
			else{
				aux->izq=new; //si su izquierda es vacio, ahi deberá ser insertado
				return;
			}

		}
		else{
			if(aux->der!=NULL){
				aux=aux->der;	//analogamente en el otro caso, se permite repeticiones
			}
			else{
				aux->der=new;
				return;
			}
		}
	}

}

TNodo* buscar_nodo(TNodo* Nodo, Tinfo objetivo){
	//Nodo es un puntero que será modificado y devuelto por el procedimeinto
	if(Nodo==NULL){
		return NULL;
	}
	if(Nodo->valor==objetivo){
		return Nodo;
	}
	//Para buscar el nodo de manera recursiva se necesitará primero el nodo de la raiz y este se irá
	//modificando mientras se busca el objetivo.
	//Como se ha asumido que el ABB puede tener números repetidos:
	TNodo* res;
	if(Nodo->valor>objetivo){
		//buscar a la izquierda
		res=buscar_nodo(Nodo->izq, objetivo);
		return res;
	}
	else{
		//si el objetivo es mayor al valor actual, se deberá buscar a la derecha
		res=buscar_nodo(Nodo->der,objetivo);
		return res;
	}
}

TNodo* buscar_padre(TABB* Arbol, TNodo* Nodo){
	//funcion auxiliar para allar al padre del nodo
	assert(Nodo!=NULL); //El Nodo no exite en el arbol
	if(Nodo==Arbol->raiz){
		return NULL;
	}
	TNodo* aux;
	aux=Arbol->raiz;
	while (aux->izq!=Nodo && aux->der!=Nodo){
		if (aux->valor>Nodo->valor){
			aux=aux->izq;
		}
		else{
			aux=aux->der;
		}
	}
	return aux;
}

void eliminar_nodo(TABB* Arbol, Tinfo objetivo){
	//En primer lugar se utilizan las funciones auxiliares
	TNodo* nodo_obj=buscar_nodo(Arbol->raiz,objetivo);
	assert(nodo_obj!=NULL); //El nodo a eliminar no se encuentra en el arbol
	TNodo* nodo_padre=buscar_padre(Arbol, nodo_obj);
	if(nodo_obj->izq==NULL && nodo_obj->der==NULL){ //Sus ambos hijos son vacios, la conexion
		if (nodo_obj==Arbol->raiz){
			Arbol->raiz=NULL;
		}
		if(nodo_padre->valor>objetivo){				//con el padre desaparece.
			nodo_padre->izq=NULL;
		}
		else{
			nodo_padre->der=NULL;
		}
		free(nodo_obj);	//se libera la memoria del nodo
		return;
	}
	//si solo tiene un hijo entonces, se crea una conexion entre el nodo_padre y el hijo no nulo del objetivo
	if(nodo_obj->izq==NULL){ 
		if (nodo_obj==Arbol->raiz){
			Arbol->raiz=nodo_obj->der;
		}
		if(nodo_padre->valor>objetivo){
			nodo_padre->izq=nodo_obj->der;
		}
		else{
			nodo_padre->der=nodo_obj->der;
		}
		free(nodo_obj); //se libera el objetivo
		return;
	}
	if(nodo_obj->der==NULL){
		if (nodo_obj==Arbol->raiz){
			Arbol->raiz=nodo_obj->izq;
		}
		if(nodo_padre->valor>objetivo){
			nodo_padre->izq=nodo_obj->izq;
		}
		else{
			nodo_padre->der=nodo_obj->izq;
		}
		free(nodo_obj); //se libera el objetivo
		return;
	}
	//si se tiene dos hijos, el valor del nodo objetivo deberá ser reemplazado
	//(en este caso) con el mayor de los valores del subarbol izquierdo y dicho nodo deberá
	//desaparecer. En este caso, no es encesario considerar cuando el nodo es la raiz del arbol
	TNodo* auxiliar=nodo_obj->izq;
	while (auxiliar->der!=NULL){
		auxiliar=auxiliar->der;
	}
	Tinfo reemplazo=auxiliar->valor;
	eliminar_nodo(Arbol, auxiliar->valor);
	nodo_obj->valor=reemplazo;
}

int main(){
	TABB Arbol;
	iniciar_ABB(&Arbol);
	anadir_ABB(&Arbol,5);
	anadir_ABB(&Arbol,3);
	anadir_ABB(&Arbol,9);
	anadir_ABB(&Arbol,2);
	anadir_ABB(&Arbol,4);
	anadir_ABB(&Arbol,6);
	eliminar_nodo(&Arbol,9);
	eliminar_nodo(&Arbol,5);
	//printf("Raiz nueva: %d\n",Arbol.raiz->valor);
	printf("Exito!\n");
	
	return 0;
}