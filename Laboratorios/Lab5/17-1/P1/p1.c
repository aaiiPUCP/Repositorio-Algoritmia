/*
    Laboratorio 5 de Algoritmia (INF263)
    Nombre: Gallardo Callalli Arian Gabriel
    Codigo: 20153227
    
    Estrategia utilizada: ABB's y Recursion
    Explicacion:
        En el preorden de un ABB, se diferencian 3 campos:
        -> El primer numero es la raiz del arbol que viene a continuacion
        -> El grupo de numeros a continuacion del primero que sean menores
        	a el, pertenecen al subarbol izquierdo del ABB (definicion)
        -> El siguiente grupo de numeros pertenecen al subarbol derecho del ABB (mayores).

        Asi, por ejemplo, dado el preorden:

        	-> 50 30 24 5 28 45 98 52 60
       	
        Se distingue:
        	50 -> Raiz del arbol
        	30 ~ 45 -> Subarbol izquierdo
			98 ~ 60 -> Subarbol derecho

		Asi, como queremos mostrar el Post-Orden, analizamos primero el subarbol izquierdo,
		luego el subarbol derecho, y finalmente imprimimos la Raiz.

		La recursion iria de la siguiente manera:
				Raiz    Subarbol Izquierdo   Subarbol derecho
			
			1->  50       30 24 5 28 45          98 52 60
    		2->  30          24 5 28                45
    		3->  24             5                   28
    		4->   5            NIL                  NIL   //Se imprime 5 pues ya no quedan hijos por visitar
    		5->  28            NIL                  NIL   //Se imprime 28 pues ya no quedan hijos por visitar
														  //A este paso ya imprimimos todos los hijos de 24 (recursion 3), imprimimos 24
    		6->  45            NIL                  NIL   //Se imprime 45
    													  //A este paso ya imprimimos todos los hijos de 30 (recursion 2), imprimimos 30
 			7->  98           52 60                 NIL
 			8->  52            NIL                  60
 			9->  60            NIL                  NIL   //Se imprime 60
														  //A este paso ya imprimimos todos los hijos de 52(recursion 8), imprimimos 52
														  //Igualmente, ya imprimimos todos los hijos de 98(recursion 7), imprimimos 98
														  //Terminamos con los hijos de 50, imprimimos 50.

			El post-orden quedaria de la siguiente manera: 5 28 24 45 30 60 52 98 50
   	

   	ABB
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100002
#define debug(x) printf("Ok here: %d\n", x); fflush(stdout);
#define debug2(x,y) printf("Ok %d %d\n",x,y); fflush(stdout);

int a[N];

void go(int left, int right){
	if(left == right){
		printf("%d ", a[left]);
		return;	
	}
	
	if(a[left + 1] > a[left]){
		go(left + 1, right);
		printf("%d ", a[left]);
	}
	else{
		int tope = left + 1;
		while(tope <= right && a[tope] < a[left]) tope++; 
		tope--;
		go(left+1, tope);
		if(tope < right) go(tope + 1, right);
		printf("%d ", a[left]);
	}
}

int main(){
	int n; scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++) scanf("%d", &a[i]);
	if(n == 1){
		printf("%d\n",a[0]);
		return 0;
	}
	int tope = 1;
	if(a[1] > a[0]){
		go(1,n-1);
		printf("%d\n", a[0]);
	}
	else{
		while(tope <= n-1 && a[tope] < a[0]) tope++;
		tope--;
		go(1,tope);
		if(tope < n -1) go(tope + 1,n-1);
		printf("%d\n",a[0]);
	}
	return 0;
}
