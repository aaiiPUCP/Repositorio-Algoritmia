typedef int TElemento;

typedef struct arista{
    TElemento info;
    float peso;
    struct arista *sig;
}TArista;

typedef struct vertice{
    TElemento info;
    TArista *aristasInicio;
    TArista *aristasFin;
    struct vertice *sig;
}TVertice;

typedef struct grafo{
    int numVertices;
    TVertice *adjInicio;
    TVertice *adjFin;
}TGrafo;


void Grafo_CrearVacio(TGrafo *);
void Grafo_InsertarVertice(TGrafo *, TElemento);
void Grafo_InsertarArista(TGrafo *, TElemento, TElemento, float);
TVertice* Grafo_ExisteVertice(TGrafo *, TElemento);
int Grafo_ExisteArista(TGrafo *, TElemento, TElemento);
void Grafo_EliminarVertice(TGrafo *, TElemento);
void Grafo_EliminarArista(TGrafo *, TElemento, TElemento);
void Grafo_Imprimir(TGrafo *);
void Grafo_Finalizar(TGrafo *);
