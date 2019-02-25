#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//KPS
//Se utilizarán listas enlazadas
int main(){
	int ncasos,num;
	char car;
	//Tendremos 3 listas
	TLista A;
	TLista B;
	TLista C;
	//SE leen los casos
	scanf("%d%c",&ncasos,&car);

	while(ncasos--){
		//SE inicializan las listas, es importante porque si no
		//los números se alacenarían sin setearse las listas
		Lista_init(&A);
		Lista_init(&B);
		Lista_init(&C);
		//Se llenan las listas
		while(1){
			scanf("%c",&car);
			if (car=='\n')
				break;
			num=car-'0';
			Lista_insert(&A,num);	
		};
		while(1){
			scanf("%c",&car);
			if (car=='\n')
				break;
			num=car-'0';
			Lista_insert(&B,num);	
		};
		//Se resta
		Lista_restar(&A,&B,&C);
		//SE imprime el valor
		Lista_print(&C);
	}

	return 0;
}