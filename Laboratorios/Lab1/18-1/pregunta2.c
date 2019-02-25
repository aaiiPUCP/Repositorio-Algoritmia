#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define	N 360
//Huaman Ramos Stev 20162190
//se utilizara el metodo de fuerza bruta

int hallarDifMin(int ArrAng[N],int n){
		int i,j,k;
		//iteradores

		int min=360;
		//la diferencia minima es 360

		for(j=0;j<n;j++){

			int sumaPar1=ArrAng[j];//suma de la parte inicial
			int	sumaPar2=360-sumaPar1;

			if(abs(sumaPar2-sumaPar1)<min)
					min=abs(sumaPar2-sumaPar1);	//hallar la minima diferencia entre angulos

			for(i=j+1;i<n;i++){//se ira sumando pedazo a pedazo
				sumaPar1=sumaPar1+ArrAng[i];
				sumaPar2=360-sumaPar1;
				if(abs(sumaPar2-sumaPar1)<min)
					min=abs(sumaPar2-sumaPar1);

				if(j>1 && i==n-1){ //cuando llegue al extremo tambien se puede coger el primer elemento, pues es una pizza redonda

					for(k=0;k<=j-2;k++){
						sumaPar1=sumaPar1+ArrAng[k];
						sumaPar2=360-sumaPar1;

					if(abs(sumaPar2-sumaPar1)<min)
						min=abs(sumaPar2-sumaPar1);
					}
				}
			}

		}
		return min;
}

void main(){
	int n;
	int i;
	printf("Leer el numero de pedazos de la pizza\n");
	scanf("%d",&n);

	int ArrAng[N];

	//inicializar los angulos en 0
	for (i = 0; i < n; i++)
	{
		ArrAng[i]=0;
	}

	printf("Leer los angulos de los %d pedazos de la pizza\n",n );

	for (i = 0; i < n; i++)
	{
		scanf("%d",&ArrAng[i]);
	}

	int diferMin=hallarDifMin(ArrAng,n);
	printf("La diferencia minima entre los angulos de la pizza es %d\n",diferMin);

}
