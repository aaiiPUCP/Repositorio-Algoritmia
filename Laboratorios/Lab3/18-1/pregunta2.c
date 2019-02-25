#include <stdio.h>
/*Para el siguiente problema se utilizará la estrategia de programación dínamica, se creará
una arreglo que almacene el tamaño de la subsecuencia más larga que se puede formar con la
característica mencionada*/

int absDiferencia(int n,int m){
	return (m<n)?(n-m):(m-n);
//Función auxiliar para hallar el valor absoluto de la diferencia
}

int main(){
	int n; //cantidad de numeros del arreglo
	scanf("%d",&n);
	int num[n]; //Arreglo que almacena los números
	for (int i=0; i <n; i++){
		scanf("%d",&num[i]);
	}
	int dpSec[n]; //Arreglo que almacena la longitud máxima de la subsecuencia que acaba
	//en el ultimo numero de la posicion que almacena y cumple con dicha característica
	dpSec[0]=1; //Si solo se toma la secuancia hasta la pos 0, el tamaño máximo será 1
	//Calcular el arreglo:
	for (int i=1; i<n; i++){
		int maxi=0;
		for (int j=0; j<i; j++){
			if ((absDiferencia(num[j],num[i])==1) && (dpSec[j]>maxi)){
				maxi=dpSec[j];
			}
		}
		dpSec[i]=maxi+1;
	}
	//Ahora, se debe hallar la subsecuencia máxima que se encontró!
	int max=0;
	for (int i = 0; i <n; i++){
		max=(dpSec[i]>max)?dpSec[i]:max;
	}
	printf("%d\n",max);
	return 0;
}