#ifndef ESPARSA_H
#define ESPARSA_H

typedef int TElemento;

typedef struct nodo{
	int pos;
	TElemento elem;
	struct nodo *sig;
}TNodo;

typedef struct esparsa{
	TNodo *inicio;
	TNodo *fin;
	int numElem;
}TEsparsa;

void Esparsa_init(TEsparsa *);
int Esparsa_isEmpty(TEsparsa *);
int Esparsa_length(TEsparsa *);
void Esparsa_insert(TEsparsa *,int,TElemento);
void Esparsa_sumar(TEsparsa *,TEsparsa *,TEsparsa *);
void Esparsa_print(TEsparsa *);

#endif