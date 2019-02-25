/*
    Laboratorio 5 de Algoritmia (INF263)
    Nombre: Gallardo Callalli Arian Gabriel
    Codigo: 20153227
    
    Estrategia utilizada: Breadth First Search (Bicoloring)
    Explicacion:
        Se dice que un grafo es bipartito si se puede colorear
        los vertices del grafo con a lo mas DOS colores de tal 
        manera que dos vertices con el mismo color no presenten
        una arista entre ellos. Para esto, se uso la busqueda en
        amplitud, lo cual permitira ir coloreando los vertices uno
        a uno verificando que no exista el problema mencionado
        anteriormente.
        
        bicolorable -> flag que se desactiva cuando se hallo un error
        white[N] -> Primer grupo 
        black[N] -> Segundo grupo
        queue[2*N] -> Simulacion de una cola con two pointers
       
    Graph Theory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafo.h"

#define N 100002
#define debug(x) printf("Ok here: %d\n",x); fflush(stdout);

int bicolorable;
int color[N];
int white[N], posw;
int black[N], posb;

int queue[2*N];

void bfs(TGrafo* G, int src){
	int front = 0, rear = 0;
	color[src] = 0;
	queue[rear++] = src;
	while(front != rear){
		int u = queue[front++];
		TVertice* cur = G->adjInicio;
		while(cur && cur->info != u) cur = cur->sig;
		
		TArista* edge = cur->aristasInicio;
		while(edge){
			int v = edge->info;
			if(color[v] == -1){
				color[v] = 1 - color[u];
				queue[rear++] = v;
			}
			else if(color[v] == color[u]){
				bicolorable = 0;
				return;
			}
			edge = edge->sig;
		}

	}
}

TGrafo G;

int main(){
	int n,m; scanf("%d %d", &n,&m);
	Grafo_CrearVacio(&G);
	for(int i = 0 ; i < n ; i ++){
		int v; scanf("%d",&v);
		Grafo_InsertarVertice(&G,v);
	}
	for(int i = 0 ; i < m; i ++){
		int u,v; scanf("%d %d",&u,&v);
		Grafo_InsertarArista(&G, u, v, 1);
	}
	TVertice* cur = G.adjInicio;
	bicolorable = 1;
	memset(color,-1,sizeof(color));
	while(cur){
		int u = cur->info;
		if(color[u] == -1) bfs(&G, u);
		if(!bicolorable) break;
		if(color[u] == 0) white[posw++] = u;
		else black[posb++] = u;
		cur = cur-> sig;
	}
	if(!bicolorable) printf("No es bipartito\n");
	else{
		for(int i = 0; i < posw; i ++){
			printf("%d", white[i]);
			if(i != posw-1) printf(" ");
			else printf("\n");
		}
		for(int i = 0 ; i < posb; i++){
			printf("%d",black[i]);
			if(i != posb-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
