#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"
//KPS
//Se utilizan esparzas, son como listas pero en el nodo guardan tambien la pos 
int main(){
	int pos,val,tam;
	char car;
	TEsparsa A;
	TEsparsa B;
	TEsparsa C;

	Esparsa_init(&A);
	Esparsa_init(&B);
	Esparsa_init(&C);

	scanf("%d",&tam);	
	//Llenamos los esparsas
	do{
		scanf("%d %d%c",&pos,&val,&car);	
		Esparsa_insert(&A,pos,val);	
	}while(car!='\n');

	do{
		scanf("%d %d%c",&pos,&val,&car);
		Esparsa_insert(&B,pos,val);
		
	}while(car!='\n');
	//Sumamos Y almacenamos en C
	Esparsa_sumar(&A,&B,&C);
	//Imprimos C
	Esparsa_print(&C);

	return 0;
}