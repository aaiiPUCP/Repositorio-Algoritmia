/*
    Laboratorio 4 de Algoritmia (INF 263)
    Nombre: Gallardo Callalli Arian Gabriel
    Codigo: 20153227
    Horario: L0583

    -----------------------------------------

    Pregunta 1: Stock span problem

    Estrategia:
        Con ayuda de una Pila, se calculo los valores de s[i] con las recomendaciones  
        indicadas en el texto. Al analizar el dia i, se eliminan de la pila todos los
        elementos que sean menores o iguales al precio de dicho indice. Asi, si la pila
        queda vacia, significaria que no hay un dia precedente mayor o igual a dicho precio
        con lo cual tendriamos un valor de h[i] = -1. s[i] es calculado como i-h[i].
        Se almacenan en la pila el dia actual y se repite el proceso para todos los siguientes i.

    [Data Structures]

*/

#include <stdio.h>
#include <stdlib.h>

#define N 100002

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

int a[N], h[N], s[N];

int main(){
    TStack stk;
    int t; scanf("%d",&t);
    for(int tc = 0 ; tc < t ; tc++){
        init_stack(&stk);
        int n; scanf("%d",&n);
        for(int i = 0 ; i < n ; i ++) h[i] = -1;
        for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
        h[0] = -1; push(&stk, 0);
        s[0] = 1;
        int ind = 1;
        while(ind < n){
            while(!is_empty(stk) && a[top(stk)] <= a[ind]) pop(&stk);
            if(is_empty(stk)) h[ind] = -1;
            else h[ind] = top(stk);
            s[ind] = ind - h[ind];
            push(&stk,ind);
            ind++;
        }
        for(int i = 0 ; i < n ;i ++){
            printf("%d", s[i]);
            if(i != n-1) printf(" ");
            else printf("\n");
        }
        finalize(&stk);
    }
    return 0;
}
