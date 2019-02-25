//la estrategia a emplear en el siguiente problema es la de recursion
//Huaman Ramos Stev 20162190
#include <stdio.h>


//Este modulo halla el numero de rondas totales
int hallarNumRondas(int n){
	int i=0;



	while(n!=1){

		n=n/2;
		i++;
	}

	return i;

}



//este modulo halla la ronda en la que se encontraran los equipos
int rondaFinal(int n,int a,int b,int numRondaTot){
	if((a<=n/2 && b>n/2)|| (b<=n/2 && a>n/2))
			return numRondaTot;
	else{
		//todos los valores que cumplen esta condicion se transforman a uno nuevo empezando desde 1
		if((a>n/2) && (b>n/2)){
			a=a-(n/2);
			b=b-(n/2);
		}

		//se halla el numero de rondas de la mitad de datos ya que estan separados
		int numRondaTotParc=hallarNumRondas(n/2);
		return rondaFinal(n/2,a,b,numRondaTotParc);
	}
}

void main(){
	int n,a,b;

	printf("Leer el numero de equipos\n" );
	scanf("%d",&n);

	printf("Leer el numero de identificadores de los equipos\n");
	scanf("%d %d",&a,&b);

	//se halla el numero de rondas totales que tiene el torneo
	int numRondaTot=hallarNumRondas(n);

	//se halla el numero de la ronda en la que se encontraran los equipos con indices a y b
	int numRonda=rondaFinal(n,a,b,numRondaTot);


	//se compara los resultados de arriba
	if(numRonda==numRondaTot){
		printf("Final!\n");
	}
	else
	{
		printf("%d\n",numRonda);
	}

}