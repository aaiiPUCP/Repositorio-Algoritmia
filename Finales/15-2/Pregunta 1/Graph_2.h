/* 
 * File:   Graph_2.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2015, 11:37 AM
 */

#ifndef GRAPH_2_H
#define	GRAPH_2_H

#define MATSIZE 30

typedef int TElem;


typedef struct nodo {
        TElem info;
        struct nodo *sig;
} TNodo;

typedef struct {
        TNodo *inicio;
        TNodo *fin;
} TCola;


void Cola_init(TCola*);
void Cola_enqueue(TCola*, TElem);
TElem Cola_dequeue(TCola*);
int Cola_isEmpty(TCola *);
void Cola_finalize(TCola *);

typedef struct node
{
    int cost;                   //Implementamos como estructura para que sea extendible 
}g_node;

typedef enum
{
    NOTHING,XNODE,YNODE
}t_type;

typedef enum
{
    UNDIRECTED,DIRECTED
}t_mode;

typedef struct grafo
{
    g_node g_mat[MATSIZE][MATSIZE];
    int nVert;
}t_graph;

void newGraph(t_graph* grafo,int nVert);

void insert_Edge(t_graph* grafo,int cost,TElem g_ini,TElem g_fin,t_mode mode);

int BFS(t_graph* grafo,TElem g_ini,TElem g_fin);


    

#endif	/* GRAPH_2_H */

