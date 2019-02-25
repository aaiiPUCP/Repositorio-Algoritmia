#include <stdio.h>
#include <stdlib.h>

typedef int TInfo;

//Esta estructura define la información contenida en un Nodo del árbol
typedef struct Node{
    TInfo info;
    struct Node *left, *right;
}TNode;

//Esta estructura define el TAD del árbol binario
typedef struct tree{
    TNode* root;
}TBinaryTree;


//Este método sirve para inicializar el puntero a la raíz de un árbol
// Por defecto, el valor inicial de la raiz es NULL
// Este método se debe llamar antes de realizar cualquier operación sobre un árbol binario

void init_tree(TBinaryTree* T){
    T->root = NULL;
}

//Este método permite insertar elementos en un árbol
void insert(TBinaryTree* T, TInfo x){
    TNode* nuevo = (TNode*)malloc(sizeof(TNode));
    nuevo->info = x;
    nuevo->left = nuevo->right = NULL;

    //Caso 1: Arbol vacio
    if(T->root == NULL){
        T->root = nuevo;
        return;
    }

    TNode *p, *q;
    p = T->root;
    int flag = 0;

    while(p!=NULL){
        q = p;
        if(x < p->info){
            p = p->left;
            flag = 0;
        }else if(x > p->info){
            p = p->right;
            flag = 1;
        }
    }

    if(flag == 0){
        q->left = nuevo;
    }else{
        q->right = nuevo;
    }
}

void main(){
    //Programa ejemplo para probar la funcionalidad básica
    TBinaryTree T;
    init_tree(&T);

    insert(&T, 12);
    insert(&T, 7);
    insert(&T, 16);
    insert(&T, 4);

}
