/*
    Sistema operativo usado: Linux Mint
	Pregunta 2
	Laboratorio 2 de Algoritmia - INF263
	Nombre: Gallardo Callalli Arian Gabriel
	Codigo: 20153227
	Horario: Lab 583

	Estrategia utilizada: BACKTRACKING
		- En este problema se iran posicionando las torres de manera
		  recursiva y se probara la disponibilidad de los espacios 
		  siguientes a partir de las ya posicionadas. La funcion ok
		  revisa si es posible plantar una torre en dicho lugar
		  (es decir, que no haya ninguna pared ahi o una torre este
		  atacando dicho lugar), mientras que la funcion solve posicionara
		  las torres de manera recursiva.

		  Un valor de 1 significa que existe una pared en dicho lugar, mientras
		  que un valor de 2 significa que existe una torre en dicho lugar. De lo contrario
		  la casilla esta vacia.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int mat[N][N];
int n;

int ok(int x, int y){
	//Si es que hay una torre o una pared plantada en el lugar, no puede ir una torre ahi
	if(mat[x][y] == 1 || mat[x][y] == 2) return 0;
	//Verificar ataque de torres:
	//Arriba
	for(int u = x; u >=0 && mat[u][y] != 1; u--){
		if(mat[u][y] == 2) return 0;
	}
	//Abajo
	for(int u = x; u < n && mat[u][y] != 1; u++){
		if(mat[u][y] == 2) return 0;
	}
	//Izquierda
	for(int v = y; v >= 0 && mat[x][v] != 1; v--){
		if(mat[x][v] == 2) return 0;
	}
	//Derecha
	for(int v = y; v < n && mat[x][v] != 1; v++){
		if(mat[x][v] == 2) return 0;
	}
	//De lo contrario, se puede plantar la torre
	return 1;
}

int solve(){
	int ma = 0; //Maxima cantidad de torres que puedo plantar con la configuracion a poner
	for(int i = 0 ; i < n; i ++){
		for(int j = 0; j < n ; j ++){
			if(ok(i,j)){ //Si es que se puede plantar la torre, proseguir
				mat[i][j] = 2; //2 significa que plante una torre en dicho lugar
				int res = 1 + solve(); //Recursion backtracking
				if(res > ma) ma = res;
				mat[i][j] = 0; //Deshaciendo el efecto
			}
		}
	}
	return ma;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n ; j ++){
			scanf("%d",&mat[i][j]); //Lectura
		}
	}
	int res = solve(); //Llamada a la funcion backtracking
	printf("%d\n",res);
	return 0;
}
