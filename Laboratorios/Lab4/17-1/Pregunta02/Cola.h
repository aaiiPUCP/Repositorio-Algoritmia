typedef struct Elemento{
	int escuela;
	int id;
}TElemento;

typedef struct nodo {
        TElemento info;
        struct nodo *sig;
} TNodo;

typedef struct {
        TNodo *inicio;
        TNodo *fin;
        TNodo* ultimo[5];
} TCola;


void Cola_init(TCola*);
void Cola_enqueue(TCola*, TElemento);
TElemento Cola_dequeue(TCola*);
int Cola_isEmpty(TCola *);
void Cola_finalize(TCola *);
