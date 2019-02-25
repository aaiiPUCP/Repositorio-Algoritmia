#include <stdio.h>
/*Se utilizará la constante INT_MAX para denotar que no se encontró un numero pico
La estrategia a utilizar es "Divide y vencerás", se tendrá un arreglo con todos los números
Y luego se analizará si el número que se encuentra en el medio es un numero pico, sino se
procedrá a buscar en la mitad del arreglo en la que se encuentre él númerov mayor al número del medio
que se analizó y así sucesivamente, ya que sí o sí en una secuencia existe un número pico si es que no
cumplen los extremos.
Cómo del arreglo se va revisando solo mitades y mitades hasta encongtrar la respuesta, el problema tiene
un complejidad O(log(n)) puesto que no recorre todo el arreglo secuencialmente, sino divide el arreglo hasta
volverlo muy pequeño y encontrar el número pico*/

int buscaPico(int num[], int ini, int fin){
	int med=(ini+fin)/2;
	if ((num[med]>=num[med-1]) && (num[med]>=num[med+1])){
		return med;
	}
	else{
		if (num[med+1]>num[med]){
			return buscaPico(num, med, fin);
		}
		else{
			return buscaPico(num,ini,med);
		}
	}
}

int main(){
	int n; //numero de números
	scanf("%d",&n);
	int num[n]; //Arreglo con los numeros a evaluar
	for (int i=0; i<n; i++){
		scanf("%d",&num[i]);
	}
	//Primero se descartan los extremos
	if (num[0]>=num[1]){
		printf("%d\n",num[0]);
	}
	else{
		if(num[n-2]<=num[n-1]){
			printf("%d\n",num[n-1]);
		}
		//Si los extremos no son picos, se utilizará la estratégica de divide y vencerás para
		//poder hallar un número pico, muy parecido a la búsqueda binaria
		else{
			int posPico=buscaPico(num,0,n-1);
			printf("%d\n",num[posPico]);
		}
	}
	return 0;
}