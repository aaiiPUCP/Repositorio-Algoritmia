/*
    Sistema Operativo Usado: Linux Mint
	Pregunta 1: M Coloring Problem - Backtracking
	Laboratorio 2 de Algoritmia - INF263
	Nombre: Gallardo Callalli Arian Gabriel
	Codigo: 20153227
	Horario: Lab 583

	Estrategia utilizada: BACKTRACKING
		- En este problema se encontrara una configuracion adecuada
		  para los colores de los nodos en un grafo, de tal manera 
		  que dos nodos adyacentes no tengan el mismo color. Asi,
		  se encontraran todas las permutaciones de los colores para los
		  nodos para finalmente proceder a verificar la condicion
		  mencionada arriba. La funcion ok() cumple esa tarea, mientras
		  que la funcion solve encuentra recursivamente todas las permutaciones
		  posibles para los colores de los nodos del grafo.

		  Como la estrategia solo pide Backtracking, se implemento una funcion
		  facil de codificar en tiempo O(m^n * n^2), sin embargo, no es la
		  solucion mas optima

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 11
#define M 11

int colors[M];
int per[N];
int adj[N][N];
int n,m;
int done;

int ok(){
	for(int i = 0; i < n; i++){
		int col = per[i];
		for(int j = 0; j < n; j++){
			if(i == j) continue; //No tiene sentido revisar el mismo nodo
			if(adj[i][j] == 1 && col == per[j]) return 0; //Si hay conexion entre estos dos nodos, y tienen el mismo color, fallo
		}
	}
	return 1;
}

void solve(int cnt){
	if(cnt == n){ //Una vez que se completaron todos los colores para todos los nodos
        if(ok()){ //Si es que se encuentra solucion, imprimir
			done++;
			for(int i = 0; i < n; i ++){
				printf("%d",per[i]);
				if(i != n-1) printf(" ");
			}
			printf("\n");
		}
		return;
	}
	for(int i = 0; i < m; i ++){
		per[cnt] = colors[i]; //Llenar la permutacion
		solve(cnt+1);
		if(done) return; //Si ya hay solucion, no tiene sentido buscar otra, regresar
		per[cnt] = 0;
	}
}

int main(){
	for(int i = 0; i < M; i ++) colors[i] = i+1; //Mis colores para los nodos
	int tc; scanf("%d",&tc);
	for(int t = 0; t < tc; t++){
		for(int i = 0; i < N; i ++) per[i] = 0; //Inicializo la permutacion
		done = 0; //Inicializo el estado que indica si se encontro solucion
		scanf("%d %d",&n, &m);
		for(int i = 0 ; i < n; i ++){
			for(int j = 0 ; j < n; j ++){
				scanf("%d",&adj[i][j]); //Lectura de la matriz
			}
		}
		solve(0); //Funcion backtracking
		if(!done){
			printf("El grafo no puede ser coloreado con %d ",m);
			if(m == 1) printf("color\n");
			else printf("colores\n");
		}
	}
	return 0;
}
