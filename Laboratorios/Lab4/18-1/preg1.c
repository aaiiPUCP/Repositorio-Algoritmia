#include <stdio.h>
#include <stdlib.h>
/*Para este programa se definirá un arreglo de enteros de tamaño 5 que almacenrá los
numeros que se vayan ingresando, cuando el arregle se llene se le aumentatrá 5 espacios
más al arreglo creando otro, copiandolo y liberando la memoria*/

int main(){
	//Se define el tamaño inicial del arreglo
	int* arreglo=(int*)malloc(sizeof(int)*5);
	int nElem=0;
	int tamanho=5;
	int curr;
	scanf("%d",&curr);
	while (curr>-1){
		nElem++;
		if (nElem>tamanho){
			tamanho+=5;
			//si se supera se deberá aumentar el espacio, para ello
			//se creará un nuevo arreglo de más memoria y se guardarán los números ya obtenidos
			//luego de ello se liberará la memoŕia del arreglo anterior
			int *arregloAux=(int*)malloc(sizeof(int)*tamanho);
			for (int i=0; i<nElem-1; i++){
				arregloAux[i]=arreglo[i];
			}
			free(arreglo); //se libera la memoria que ya no sirve
			arreglo=arregloAux; //se modifica el puntero arreglo por el puntero de arregloAux
		}
		arreglo[nElem-1]=curr;
		scanf("%d", &curr);
	}
	printf("Tamaño: %d, Num. elementos: %d\n",tamanho, nElem);
	for (int i=0; i<nElem; i++){
		printf("%d ",arreglo[i]);
	}
	printf("\n");
	return 0;
}