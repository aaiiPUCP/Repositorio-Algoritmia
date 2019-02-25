#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"
//KPS
void Esparsa_init(TEsparsa *E){
	E->inicio=NULL;
	E->fin=NULL;
	E->numElem=0;
}
int Esparsa_isEmpty(TEsparsa *E){
	return E->numElem==0;
}
int Esparsa_length(TEsparsa *E){
	return E->numElem;
}
void Esparsa_insert(TEsparsa *E,int pos,TElemento e){
	TNodo *nodo=malloc(sizeof(TNodo));
	nodo->pos=pos;
	nodo->elem=e;
	nodo->sig=NULL;
	
	if (Esparsa_isEmpty(E)){
		E->inicio=nodo;
		E->fin=nodo;
	}
	else{
		E->fin->sig=nodo;
		E->fin=nodo;
	}
	(E->numElem)++;
}
void Esparsa_sumar(TEsparsa *A,TEsparsa *B,TEsparsa *C){
	//Tendremos dos nodos que recorran la lista A y B respectivamente
	TNodo *crtnodoA=A->inicio;
	TNodo *crtnodoB=B->inicio;
	TElemento suma;
	int pos;
	//EL bucle acaba cuando una de las lista acaba
	while (crtnodoA!=NULL && crtnodoB!=NULL){
		// si las pos de ambos crtnodos son iguales, la sumamos;
		if (crtnodoA->pos==crtnodoB->pos){
			suma=crtnodoA->elem+crtnodoB->elem;
			Esparsa_insert(C,crtnodoA->pos,suma);
			crtnodoA=crtnodoA->sig;
			crtnodoB=crtnodoB->sig;
		}
		else{
			//Si no es así, insertamos en C el menos de estos y avanzamos ese crtnodo;
			if (crtnodoA->pos<crtnodoB->pos){
				Esparsa_insert(C,crtnodoA->pos,crtnodoA->elem);
				crtnodoA=crtnodoA->sig;
			}
			if (crtnodoA->pos>crtnodoB->pos){
				Esparsa_insert(C,crtnodoB->pos,crtnodoB->elem);
				crtnodoB=crtnodoB->sig;
			}
		}
	}
	//En caso alguna esparsa no haya acabado, se insertará en C
	//Si A no acabó
	while (crtnodoA!=NULL){
		Esparsa_insert(C,crtnodoA->pos,crtnodoA->elem);
		crtnodoA=crtnodoA->sig;
	}
	//SI B no acabó
	while (crtnodoB!=NULL){
		Esparsa_insert(C,crtnodoB->pos,crtnodoB->elem);
		crtnodoB=crtnodoB->sig;
	}
}
void Esparsa_print(TEsparsa *E){
	//imprime hasta que acabe
	if (!Esparsa_isEmpty(E)){
		TNodo *crtnodo=E->inicio;
		while(crtnodo!=NULL){
			printf("%d %d ",crtnodo->pos,crtnodo->elem);
			crtnodo=crtnodo->sig;
		}
		printf("\n");
	}
}

