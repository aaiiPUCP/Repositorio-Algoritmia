#include <stdio.h>
#include <stdlib.h>

#include "Graph_2.h"

void Cola_init(TCola *C){
    C->inicio = NULL;
    C->fin = NULL;
}

void Cola_enqueue(TCola *C, TElem nuevoElem){
    TNodo *ptr_nuevoNodo;
    
    ptr_nuevoNodo = (TNodo*)malloc(sizeof(TNodo));
    
    if (ptr_nuevoNodo != NULL){
        ptr_nuevoNodo->info = nuevoElem;
        ptr_nuevoNodo->sig = NULL;
        if (C->inicio == NULL)
            C->inicio = ptr_nuevoNodo;
        else 
            C->fin->sig = ptr_nuevoNodo;

        C->fin = ptr_nuevoNodo;
    }
}

TElem Cola_dequeue(TCola *C){
    if (!Cola_isEmpty(C)){
        TElem head_info; TNodo *ptr_head;
        ptr_head = C->inicio;
        head_info = ptr_head->info;
        C->inicio = C->inicio->sig;
        free(ptr_head);
        return head_info;
    }
    return -1;
}

int Cola_isEmpty(TCola *C){
    return (C->inicio == NULL);
}

void Cola_finalize(TCola *C){
    while (!Cola_isEmpty(C))
        Cola_dequeue(C);
}

void newGraph(t_graph* grafo,int nVert)
{
    grafo->nVert = nVert;
    int i,j;
    for(i=0;i<nVert;i++)
    {
        for(j=0;j<nVert;j++)
        {
           grafo->g_mat[i][j].cost = 0;
        }
    }
}

void insert_Edge(t_graph* grafo,int cost,TElem g_ini,TElem g_fin,t_mode mode)
{
    if(mode==UNDIRECTED)
    {
        grafo->g_mat[g_fin][g_ini].cost = cost;    //Como no es dirigido inserto de los dos lados
    }
    
    grafo->g_mat[g_ini][g_fin].cost = cost;
}

int BFS(t_graph* grafo,TElem g_ini,TElem g_fin)     //En realidad no hay nodo fin pero lo pongo para que sea extendible
{
    TCola cola;
    Cola_init(&cola);
    
    int size = grafo->nVert;
    
    Cola_enqueue(&cola,g_ini);
    int* visitados  = malloc(sizeof(int)*size);
    t_type* tipo = malloc(sizeof(t_type)*size);
    
    int i;
    for(i=0;i<size;i++)      
    {
        visitados[i] = 0;
        tipo[i] = NOTHING;             //Inicializamos los arreglos que nos van a
        //ayudar a ver los visitados y que tipo le corresponde a cada
        //vertex, de esta manera vamos pintando
        //poco a poco al recorrer el grafo y si existe un conflicto de tipos no
        //es bipartito  
    }
    
    TElem P = g_ini;
    tipo[P] = XNODE;            //Iniciamos con el X node
    
    while(!Cola_isEmpty(&cola))
    {
        P = Cola_dequeue(&cola);
        if(!visitados[P])
        {
            visitados[P] = 1;
            printf("%d ",P);                //Imprimimos para ver el recorrido
            for(i=0;i<size;i++)             //Vamos poniendo a los hijos que estan conectandolos y pintandolos si es nesesario
            {
                if(!visitados[i]&&grafo->g_mat[P][i].cost)       // El costo es diferente de 0
                {
                    Cola_enqueue(&cola,i);            //Hay que notar que simpre estaremos en un nodo pintado por las propiedades del BFS(Siempre recorremos los hijos primero)
                    if(tipo[i]==NOTHING)            //Aun no esta pintado -> Lo pintamos del contrario
                    {
                        if(tipo[P]==XNODE)
                        {
                            tipo[i] = YNODE;
                        }else
                        {
                            tipo[i] = XNODE;
                        }
                        
                    }else
                    {
                        if(tipo[P]==XNODE)
                        {
                            if(tipo[i]==XNODE)  //Podriamos manejarlo aunmentado valores      
                            {
                                return 0;                               
                            }
                        }else
                        {
                            if(tipo[i]==YNODE)  //Revisamos si no hay incongruencias con como estan dispuestos
                            {
                                return 0;
                            }
                        }                                                
                    }                  
                }
            }
        }       
    }
    return 1;
    
    //Si terminamos todo el proceso sin incongruencias entonces es un grafo Bipartito    
}
