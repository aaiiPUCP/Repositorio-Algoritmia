#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//KPS
void Lista_init(TLista *L){
	L->inicio=NULL;
	L->fin=NULL;
	L->numElem=0;
}
int Lista_isEmpty(TLista *L){
	return L->numElem==0;
}
int Lista_length(TLista *L){
	return L->numElem;
}
//insert inserta por la derecha
void Lista_insert(TLista *L,TElemento e){
	TNodo *nodo=malloc(sizeof(TNodo));
	nodo->elem=e;
	nodo->sig=NULL;
	nodo->ant=NULL;
	
	if (Lista_isEmpty(L)){
		L->inicio=nodo;
		L->fin=nodo;
	}
	else{
		L->fin->sig=nodo;
		nodo->ant=L->fin;
		L->fin=nodo;
	}
	(L->numElem)++;
}
//addLeft se utlizará en resta, ya que los números de van hallando de derecha a izq
void Lista_addLeft(TLista *L,TElemento e){
	TNodo *nodo=malloc(sizeof(TNodo));
	nodo->elem=e;
	nodo->sig=NULL;
	nodo->ant=NULL;
	
	if (Lista_isEmpty(L)){
		L->inicio=nodo;
		L->fin=nodo;
	}
	else{
		L->inicio->ant=nodo;
		nodo->sig=L->inicio;
		L->inicio=nodo;
	}
	(L->numElem)++;
}
//determina el mayor de dos listas
int Lista_mayor(TLista *A,TLista *B){
	TNodo *crtnodoA=A->inicio;
	TNodo *crtnodoB=B->inicio;
	if (Lista_length(A)>Lista_length(B)){
		return 1;
	}
	if (Lista_length(A)<Lista_length(B)){
		return 2;
	}

	while (crtnodoA!=NULL && crtnodoB!=NULL){
		if (crtnodoA->elem > crtnodoB->elem)
			return 1;
		if (crtnodoA->elem < crtnodoB->elem)
			return 2;
		if (crtnodoA->elem == crtnodoB->elem){
			crtnodoA=crtnodoA->sig;
			crtnodoB=crtnodoB->sig;
		}
	}
	//iguales;
	return 0;
}
//Determina y mayor e invoca
void Lista_restar(TLista *A,TLista *B,TLista *C){
	int mayor=Lista_mayor(A,B);
	if (mayor==1)
		Lista_restarAux(A,B,C);
	if (mayor==2)
		Lista_restarAux(B,A,C);
	if (mayor==0)
		Lista_insert(C,0);
}
//ESta función ya tiene como primer parámetro a la lista mayor
void Lista_restarAux(TLista *A,TLista *B,TLista *C){
	TNodo *crtnodoA=A->fin;
	TNodo *crtnodoB=B->fin;
	TElemento borrow,resta;
	borrow=0;
	//el bucle hasta que los dos o uno acaben
	while (crtnodoA!=NULL && crtnodoB!=NULL){
		//hallamos la resta
		resta=(crtnodoA->elem)-((crtnodoB->elem)+borrow);
		//si es negativo
		if (resta<0){
			//guardamos el borrow
			borrow=1;
			//el resultado del digito de la resta cambia
			resta = 10 + resta;	
		}
		else{
			borrow=0;
		}
		//se añade este número por la izq
		Lista_addLeft(C,resta);
		//se analizan los nodos anteriores (mayor significacia)
		crtnodoA=crtnodoA->ant;
		crtnodoB=crtnodoB->ant;
	}
	//si la lista B acabó, copiamos lo demás de la lista A, sin olvida el borro que pudo haber quedado
	while (crtnodoA!=NULL){
		resta=crtnodoA->elem-borrow;
		//si es negativo
		if (resta<0){
			//guardamos el borrow
			borrow=1;
			//el resultado del digito de la resta cambia
			resta = 10 + resta;	
		}
		else{
			borrow=0;
		}
		if(crtnodoA!=A->inicio || (crtnodoA==A->inicio && resta!=0))
			Lista_addLeft(C,resta);
		crtnodoA=crtnodoA->ant;
	}
}
void Lista_print(TLista *L){

	if (!Lista_isEmpty(L)){
		TNodo *crtnodo=L->inicio;
		//no imprime los ceros de adelante
		while(crtnodo!=NULL && crtnodo->elem==0){
			crtnodo=crtnodo->sig;
		}
		while(crtnodo!=NULL){
				printf("%d",crtnodo->elem);
			crtnodo=crtnodo->sig;
		}

		printf("\n");
	}
}