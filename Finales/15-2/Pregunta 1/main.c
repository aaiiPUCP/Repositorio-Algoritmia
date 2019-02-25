/* 
 * File:   main.c
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2015, 11:28 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Graph_2.h"
/*
 * Lo que hemos es recorrer el grafo en Breadth First Search ( Esta decision
 * es importante ya que va a permitir que nunca estemos en un vertice que no este
 * marcado, ya que inicialmente marcamos al del otro)
 * 
 * (Al recorrer en BFS tambien se cubre el hecho que sea dirigido o no dirigido
 * (esto se hace al insertar los vertices)
 * 
 * Finalmente hacemos el BFS  y vamos marcando intercalando el tipo y siempre 
 * chekeamos si hay incongruencias y si las hay salimos del algoritmo con false
 * pero si completamos el BFS entonces se pundo completar todo el grafo marcando
 * a todas.
 * 
 */
int main(int argc, char** argv) {
   
    FILE* xDatos;
    xDatos  = fopen("datos.txt","r"); //El formato de entrada es una linea
    //inicial que nos da el numero de vertices (N) del grafo y luego 
    //un numero de lineas que termina con -1 con los valores de los
    //vertices 0<=v<N que representan los edges
    
   int g_ini,g_fin;
   g_ini = 1;
   t_graph grafo;
   int size;
   fscanf(xDatos,"%d",&size);
   newGraph(&grafo,size);
  
   while(g_ini!=-1)
   {
       fscanf(xDatos,"%d",&g_ini);
       fscanf(xDatos,"%d",&g_fin);
       if(g_ini!=-1)
       {
           insert_Edge(&grafo,1,g_ini,g_fin,UNDIRECTED);
       }
   }
   
   int type = BFS(&grafo,0,1);
   if(type)
   {
       printf("\nSi es bipartido");
   }else
   {
       printf("\nNo es bipartido");
   }
   
    return (EXIT_SUCCESS);
}

