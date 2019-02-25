/*
	Pregunta 2: Buscaminas recursivo
	Laboratorio 1 de Algoritmia (INF263)
	Nombre: Gallardo Callalli Arian Gabriel
	Codigo: 20153227
	Estrategia:
		El problema consiste en dejar al descubierto parte del
		mapa del buscaminas dada una posicion de clickeo. Asi,
		segun las condiciones del problema se parara de dejar 
		al descubierto cuando sea necesario.

		La estrategia es muy parecida al DFS Recursivo (Recursion)
	2017-1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 500

char mx[MAX][MAX];
int n,m;

void dfs(int x, int y){
	int dx[8]= {-1,-1,-1,0,0,1,1,1}; //Movimiento en x
	int dy[8]= {-1,0,1,-1,1,-1,0,1}; //Movimiento en y
	int cnt = 0;
	for(int i = 0; i < 8; i++){
		int r = x+dx[i], s = y+dy[i];
		if(r < 0 || s < 0 || r >=n || s >=m) continue;
		if(mx[r][s] == 'X') cnt++;
	}
	if(cnt == 0){ //No hay minas alrededor, entonces seguimos con la recursion
		mx[x][y] = '0';
		for(int i = 0; i < 8; i++){
			int r = x+dx[i], s = y+dy[i];
			if(r < 0 || s < 0 || r >=n || s >=m) continue;
			if(mx[r][s] == 'V') dfs(r,s);
		}
	}
	else{
		mx[x][y] = (char)('0' + cnt); //Ponemos el numero de minas y no seguimos la recursion
	}
}

int main(){
	int t; scanf("%d",&t);
	for(int tc = 0; tc < t; tc++){
		int x,y; scanf("%d %d",&x,&y);
		scanf("%d %d",&n,&m);
		getchar();
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				scanf("%c",&mx[i][j]);
			}
			getchar();
		}
		if(mx[x][y] == 'X') printf("Moriste\n"); //Si la posicion es una mina, MORISTE!
		else{
			dfs(x,y); //Sino, inicia la recursion
			for(int i = 0; i < n; i++){
				printf("%s\n",mx[i]);
			}
		}
		if(tc != t-1)printf("\n");
	}
	return 0;
}
