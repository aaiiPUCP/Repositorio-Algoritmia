#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Grafo.h"

void Grafo_CrearVacio(TGrafo *G){
    G->adjInicio = NULL;
    G->adjFin = NULL;
    G->numVertices = 0;
}

void Grafo_InsertarVertice(TGrafo *G, TElemento v){
    if (Grafo_ExisteVertice(G,v) == NULL){
        TVertice *ptrNuevo = malloc(sizeof(TVertice));
        if (ptrNuevo){
            ptrNuevo->info = v;
            ptrNuevo->aristasInicio=NULL;
            ptrNuevo->aristasFin=NULL;
            ptrNuevo->sig=NULL;
            if (G->adjInicio==NULL)
                G->adjInicio=ptrNuevo;
            else
                G->adjFin->sig=ptrNuevo;
            G->adjFin = ptrNuevo;
            G->numVertices++;
        }
    }
}

void Grafo_InsertarArista(TGrafo *G, TElemento u, TElemento v, float peso){
    TVertice *ptrVert = Grafo_ExisteVertice(G,u);
    if (ptrVert!=NULL && Grafo_ExisteVertice(G, v) && !Grafo_ExisteArista(G,u,v)){
        TArista *ptrNuevo = malloc(sizeof(TArista));
        ptrNuevo->info=v;
        ptrNuevo->peso=peso;
        ptrNuevo->sig=NULL;
        if (ptrVert->aristasInicio==NULL)
            ptrVert->aristasInicio=ptrNuevo;
        else
            ptrVert->aristasFin->sig=ptrNuevo;
        ptrVert->aristasFin=ptrNuevo;
    }
}

TVertice* Grafo_ExisteVertice(TGrafo *G, TElemento v){
    if (G->adjInicio != NULL){
        TVertice *ptrRec = G->adjInicio;
        while (ptrRec!=NULL){
            if (ptrRec->info == v)
                return ptrRec;
            ptrRec = ptrRec->sig;
        }
    }
    return NULL;
}

int Grafo_ExisteArista(TGrafo *G, TElemento u, TElemento v){
    TVertice *ptrVert = Grafo_ExisteVertice(G, u);
    if (ptrVert!=NULL){
        TArista *ptrArt = ptrVert->aristasInicio;
        while (ptrArt!=NULL){
            if (ptrArt->info == v)
                return 1;
            ptrArt = ptrArt->sig;
        }
    }
    return 0;
}

void Grafo_Imprimir(TGrafo *G){
    TVertice *ptrVert = G->adjInicio;
    while (ptrVert !=NULL){
        printf("%d", ptrVert->info);
        TArista *ptrArist = ptrVert->aristasInicio;
        while (ptrArist!=NULL) {
            printf(" -> %d (%.2f) ", ptrArist->info, ptrArist->peso);
            ptrArist = ptrArist->sig;
        }
        printf("\n");
        ptrVert = ptrVert->sig;
    }
}


/* TODO */
void Grafo_EliminarArista(TGrafo *G, TElemento u, TElemento v);
void Grafo_EliminarVertice(TGrafo *G, TElemento v);
void Grafo_Finalizar(TGrafo *G);
