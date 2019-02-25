#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//parte a)
typedef struct Nodo{
	int valor; //un valor entero
	struct Nodo* sig; //el siguiente elemento
}TNodo;

typedef struct Lista{
	TNodo* first; //cabeza de la lista
	TNodo* last;  //final de la lista
}TLista;

void iniciar_lista(TLista* L){
	L->first=NULL;
	L->last=NULL;
}

void anadir_nodo(TLista* L, int valor){
	//anadir al ultimo
	TNodo* new=(TNodo*)malloc(sizeof(TNodo));
	new->valor=valor;
	new->sig=NULL;
	if (L->first==NULL){
		L->first=new;
		L->last=new;
		return;
	}
	L->last->sig=new;
	L->last=new;
}

//parte b)
TNodo* separa(TLista* L){
	TNodo* head=L->first; //guardar la cabeza como variable auxiliar para retornar
	L->first=head->sig; //modificar cabeza de lista
	head->sig=NULL; //Modificar puntero de cabeza
	return head; 
}
//parte c)
void une(TNodo* cabeza, TLista* L){
	assert(cabeza!=NULL); //LA CABEZA DEBE EXISTIR
	cabeza->sig=L->first; //se une la cabeza a la lista
	L->first=cabeza; //Se actualiza la cabeza de la lista
}
//parte d)

//Funcion auxiliar
int verificarIgualdad(TLista* L1, TLista* L2){
	if(L1->first==NULL){
		return 1;
	}
	if(L1->first->valor!=L2->first->valor){
		return 0;
	}
	TNodo* head1;
	TNodo* head2;
	head1=separa(L1);
	head2=separa(L2);
	int res;
	res=verificarIgualdad(L1,L2);
	une(head1,L1);
	une(head2,L2);
	return res;
}

int subconjunto(TLista* L1, TLista* L2){
	//Se asume que una lista que es subconjutno de otra lista debe estar dentro de la lista
	//con el mismo orden
	//L1 2->3
	//L2 1->2->3->4
	//L1 es un subconjunto de L2

	//L1: [X|SX]
	//L2: [Y|SY]
	//Subconjunto ([L1],NULL) FALSE 
	//subconjunto ([X|SX],[X|SY])
	if(L2->first==NULL){
		return 0;
	}
	if(L1->first->valor==L2->first->valor){
		TNodo* head1;
		TNodo* head2;
		int res;
		head1=separa(L1);
		head2=separa(L2);
		res=verificarIgualdad(L1,L2);
		une(head1,L1);
		une(head2,L2);
		return res;
	}

	TNodo* head2;
	head2=separa(L2);
	int res;
	res=subconjunto(L1,L2);
	une(head2,L2);
	return res;
}

//parte e)

//en lista separa uno  a uno L2 para comparar con el valor de head

int en_lista(TNodo* N, TLista* L){
	int res;
	TNodo* head;
	if(N->valor==L->first->valor){
		return 1;
	}
	head=separa(L);
	res=en_lista(N,L);
	une(head,L);
	return res;
}

void interseccion(TLista* L, TLista* L2, TLista* L3){
	if(L->first==NULL){
		return;
	}
	TNodo* head;
	head=separa(L);
	if(en_lista(head,L2)){
		//solo si no esta en L3
		if(!en_lista(head,L3))
			anadir_nodo(L3,head->valor);
	}
	interseccion(L,L2,L3);
	une(head,L);
}


int main(){
	TLista L;
	iniciar_lista(&L);
	anadir_nodo(&L,1);
	anadir_nodo(&L,2);
	anadir_nodo(&L,3);
	anadir_nodo(&L,4);
//	First->1->2->3->4<-Last	
	TNodo* cabeza=separa(&L);
	printf("Parte b)\nCabeza: %d \nNueva cabeza: %d\n\n", cabeza->valor,L.first->valor);
	une(cabeza,&L);
	printf("Parte c)\nCabeza lista unida: %d \nSiguiente nodo a la cabeza: %d\n\n",L.first->valor, L.first->sig->valor);
	TLista L2;
	iniciar_lista(&L2);
	anadir_nodo(&L2, 2);
	anadir_nodo(&L2, 3);
//	First->2->3<-Last
	if(subconjunto(&L2,&L)){
		printf("Parte d) \nL2 es subconjunto de L !! :D\n\n");
	}
	TLista L3;
	iniciar_lista(&L3);
	//interseccion(&L,&L2,&L3);
	//printf("Parte e) \nL3 head:%d\n",L3.first->valor);
	return 0;
}

