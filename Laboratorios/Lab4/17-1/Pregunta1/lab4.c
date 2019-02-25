#include<stdio.h>
#include <stdlib.h>

//Estructura para un nodo
typedef struct Node{
    int data;
    struct Node* next;
}TNode;

//Tipo definido para una pila (puntero a top)
typedef struct Stack{
    TNode* top;
}TStack;

//Inicializa la pila - Obligatoriamente llamar antes de usar una pila
// Note que el argumento es un puntero a una pila
void init_stack(TStack* T){
    T->top = NULL;
}

// Evalua si la pila esta vacia o no
int is_empty(TStack T){
    if(T.top == NULL)
        return 1;

    return 0;
}

// Apila un elemento
void push(TStack* T, int x){
    TNode* nuevo = (TNode*)malloc(sizeof(TNode));
    nuevo->data = x;
    nuevo->next = NULL;

    nuevo->next = T->top;
    T->top = nuevo;
}

//Devuelve el valor del top de la pila
int top(TStack T){
    return T.top->data;
}

//Desapila un elemento de la pila
void pop(TStack* T){
    TNode* aux = T->top;
    T->top = T->top->next;

    free(aux);
}

// Elimina la pila - Llamar siempre cuando ya se terminó de usar la pila
// Note que el argumento es un puntero a una pila
void finalize(TStack* T){
    TNode* aux1 = T->top;
    TNode* aux2;

    while(aux1!=NULL){
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }
    T->top = NULL;
}


void main(){

}
