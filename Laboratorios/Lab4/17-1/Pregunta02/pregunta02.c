/*
    Laboratorio 4 de Algoritmia (INF 263)
    Nombre: Gallardo Callalli Arian Gabriel
    Codigo: 20153227
    Horario: L0583

    -----------------------------------------

    Pregunta 2: Little Monk and Goblet of Fire

    Estrategia:
        Se uso una cola para simular el comportamiento de la cola de espera de
        los Magos. Como pedian implementar insercion en O(1) siguiendo los pasos
        indicados (un mago entra atras del ultimo de su escuela o al ultimo de toda
        la cola si no hay nadie de su escuela) se creo un arreglo de punteros ultimo[N]
        el cual almacenaba el puntero al ultimo Mago de la escuela i (1 <= i <= 4). Asi,
        al momento de insertar cada mago, se verifica si existe algun companhero dentro de
        la cola con el puntero indicado, realizando una operacion de apuntado al siguiente
        en O(1). Complejidad: O(Q).

    [Data Structures]

*/

#include <stdlib.h>
#include <stdio.h>
#include "Cola.h"

int main(){
	int q; scanf("%d",&q);
	getchar();
	TCola cola; Cola_init(&cola);
	for(int queries = 0; queries < q; queries++){
		char c = getchar();
		if(c == 'E'){
			int x,y; scanf("%d %d",&x,&y);
			TElemento foo;
			foo.escuela = x; foo.id = y;
			Cola_enqueue(&cola, foo);
		}
		else{
			TElemento x = Cola_dequeue(&cola);
			if(x.escuela != -1) printf("%d %d\n",x.escuela, x.id);
		}
		getchar();
	}
	Cola_finalize(&cola);
	return 0;
}