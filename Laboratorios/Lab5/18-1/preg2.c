#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*Se tiene que elaborar una cola tal que permita recorrer los procesos de manera
ordenada que contenga nodos de dos elementos, id y la rafaga*/
//Definiciones para la cola
typedef struct Nodo{
  int id; //Identificador del proceso
  int rafaga; //Rafaga del proceso
  struct Nodo* next; //Siguiente nodo
}TNodo;

typedef struct Cola{
  TNodo* head; //primer elemento
  TNodo* tail; //ultimo elemento
}TCola;

//Métodos de la Cola
void iniciarCola(TCola* C){
  C->head=NULL; //al inicio la cola está vacía
  C->tail=NULL;
}

void enqueue(TCola* C, int id, int rafaga){
  TNodo* new=(TNodo*)malloc(sizeof(TNodo));
  new->next=NULL;
  new->id=id;
  new->rafaga=rafaga;
  if (C->head==NULL){ //primer elemento de la cola
    C->head=new;
    C->tail=new;
  }
  else{ //sino añadir al final
    C->tail->next=new;
    C->tail=new;
  }
}

void show_head(TCola* C, int* id, int* rafaga){
  assert(C->head!=NULL); //Cola está vacia
  *id=C->head->id;
  *rafaga=C->head->rafaga;
}

void dequeue(TCola* C){
  assert(C->head!=NULL); //Cola está vacía
  TNodo* aux=C->head;
  if(aux==C->tail){ //Si solo queda un elemento
    C->head=NULL;
    C->tail=NULL;
    free(aux);
    return;
  }
  C->head=C->head->next;
  free(aux);
}

//Programa principal
int main(){
  int N, Q;
  scanf("%d",&N); //numero de procesos
  scanf("%d",&Q); //Quantum
  TCola RR; //Round Robin
  iniciarCola(&RR); //inicializa la cola
  for(int i=0; i<N; i++){ //lectura de datos
    int id, rafaga;
    scanf("%d",&id);
    scanf("%d",&rafaga);
    enqueue(&RR,id,rafaga); //se agrega cada nodo a la lista
  }
  int tiempo=0; //Se acumulará el tiempo transcurrido
  while(RR.head!=NULL){ //mientras la cola no esté vacía
    int i, r; //i:identificador, r:rafaga
    show_head(&RR, &i, &r);
    r=r-Q; //se actualiza la rafaga
    if (r<=0){ //si se completó la rafaga, darlo por terminado
      tiempo=tiempo+Q+r;
      printf("id del proceso: %d Tiempo de terminación: %d\n",i,tiempo);
      dequeue(&RR); //se quita de la cola
    }
    else{
      tiempo=tiempo+Q; //actualizar el tiempo
      dequeue(&RR); //se quita de la cola
      enqueue(&RR,i,r); //se añade a la cola con datos actualizados
    }
  }
  return 0;
}



/*-------------------------USANDO LISTAS SIMPLEMENTE ENLAZADAS----------------------
Se tiene que elaborar una lista tal que pueda ser recorrida de manera ciruclar,
para ello se define una lista simplemente enlazada con punteros al inicio y al final
de la lista y se definen nodos de dos elementos, id y la rafaga
Definición de la Lista
typedef struct Nodo{
  int id; //Identificador
  int rafaga; //Rafaga
  struct Nodo* next; //Siguiente nodo
}TNodo;

typedef struct Lista{
  TNodo* first; //Primer elemento
  TNodo* last; //Ultimo elemento
}TLista;

Metodos de la lista
void iniciar_lista(TLista* T){
  T->first=NULL; //Al inicio la lista está vacía
  T->last=NULL;
}

void agregar_elemento(TLista* T, int ident, int raf){
  TNodo* new=(TNodo*)malloc(sizeof(TNodo)); //separacion y asignación de memoria
  new->next=NULL;
  new->id=ident;  //Se le asignan los datos
  new->rafaga=raf;
  if (T->first==NULL){ //Se ubica en la lista, si esta está vacía, se pone como
    T->first=new; //cabeza y como cola
    T->last=new;
  }
  else{
    T->last->next=new; //sino se agrega al final de la lista
    T->last=new;
  }
}

void eliminar_elemento(TLista* T, TNodo* N){
  if(N==T->first){
    T->first=T->first->next; //Si el elemento a eliminar es el primero
    free(N); //solo se acomodan los punteros y se libera la memoria
    return;
  }
  TNodo* ant=T->first; //auxiliar
  //Buscar al elemento anterior
  while(ant->next!=N){
    ant=ant->next;
    assert(ant!=T->last); //Si mi auxiliar se vuelve el ultimo elemento de la Lista
    //Se debe abortar la ejecución, ya que ha acurrido un error grave
  }
  if(N==T->last){ //si el nodo que se desea eliminar es el último
    T->last=ant; //se reacomodan los punteros
    ant->next=NULL;
    free(N);
  }
  else{
    ant->next=N->next; //Sino se elimina del medio de la lista
    free(N);
  }
}

int main(){
  int N, Q;
  scanf("%d",&N); //numero de procesos
  scanf("%d",&Q); //Quantum
  TLista RR; //Round Robin
  iniciar_lista(&RR); //inicializa la lista
  for(int i=0; i<N; i++){ //lectura de datos
    int id, rafaga;
    scanf("%d",&id);
    scanf("%d",&rafaga);
    agregar_elemento(&RR,id,rafaga); //se agrega cada nodo a la lista
  }
  TNodo* curr=RR.first; //Se empezará por el primer elemento
  int tiempo=0; //Se acumulará el tiempo transcurrido
  while(RR.first!=NULL){ //mientras la lista no esté vacía
    curr->rafaga=curr->rafaga-Q; //actualización de la ráfaga del proceso actual
    if (curr->rafaga<=0){ //si se completó la rafaga, darlo por terminado
      tiempo=tiempo+Q+curr->rafaga;
      printf("id del proceso: %d Tiempo de terminación: %d\n",curr->id,tiempo);
      TNodo* aux=curr;
      curr=(curr==RR.last)?RR.first:curr->next; //hallar siguiente nodo
      eliminar_elemento(&RR,aux); //eliminar nodo completado
    }
    else{
      tiempo=tiempo+Q; //actualizar el tiempo
      curr=(curr==RR.last)?RR.first:curr->next; //hallar el siguiente nodo
    }
  }
  return 0;
}
---------------------------------------------------------------------------*/
