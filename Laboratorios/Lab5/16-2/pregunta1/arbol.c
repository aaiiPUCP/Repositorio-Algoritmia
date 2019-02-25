#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
int max(int a, int b){
    if (a>b)
        return a;
    return b;
}
void init_tree(TBinaryTree* T){
    T->root = NULL;
}

void preorden(TNode* node){
    if(node==NULL)
        return;

    printf("%d\n", node->elem);
    preorden(node->left);
    preorden(node->right);
}

void inorden(TNode* node){
    if(node==NULL)
        return;

    inorden(node->left);
    printf("%d\n", node->elem);
    inorden(node->right);
}

void postorden(TNode* node){
    if(node==NULL)
        return;

    postorden(node->left);
    postorden(node->right);
    printf("%d\n", node->elem);
}

void insert(TBinaryTree* T, TElemento x){
    TNode* nuevo = (TNode*)malloc(sizeof(TNode));
    nuevo->elem = x;
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
        if(x < p->elem){
            p = p->left;
            flag = 0;
        }else if(x > p->elem){
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

int count_tree(TNode* node){
    if(node==NULL)
        return 0;

    return 1 + count_tree(node->left) +
                count_tree(node->right);
}

int depth_tree(TNode* node){
    if(node==NULL)
        return 0;

    return 1 + max(depth_tree(node->left),
                   depth_tree(node->right));
}

int isABB(TNode* node){
    if(node==NULL)
        return 1;

    int flag = 0;

    if(node->left!=NULL){
        if(node->left->elem < node->elem)
            flag = 1;
        else
            flag = 0;
    }

    if(flag == 0)
        return 0;

    if(node->right!=NULL){
        if(node->right->elem > node->elem)
            flag = 1;
        else
            flag = 0;
    }

    if(flag == 0)
        return 0;

    return isABB(node->left) && isABB(node->right);
}

void remove_tree(TBinaryTree* T, TElemento x){

    if(T->root==NULL)
        return;

    TNode* p = T->root;
    TNode* q = NULL;

    while(p!=NULL){
        if(p->elem == x){
            break;
        }else if(p->elem > x){
                q = p;
                p = p->left;
        }else{
                q = p;
                p = p->right;
        }
    }

    //Caso 1: Nodo hoja
    if(p->left == NULL && p->right == NULL){
        if(q!=NULL){
            if(q->left == p){
                q->left = NULL;
            }else if(q->right == p){
                q->right = NULL;
            }
        }else{
            T->root = NULL;
        }
        free(p);
        return;
    }

    //Caso 2: Un solo hijo
    if(p->left!=NULL && p->right==NULL){
        if(q!=NULL){
            if(q->left == p){
                q->left = p->left;
            }else if(q->right == p){
                q->right = p->left;
            }
        }else{
            T->root = p->left;
        }
        free(p);
        return;
    }

    //Caso 2: Un solo hijo
    if(p->left==NULL && p->right!=NULL){
        if(q!=NULL){
            if(q->left == p){
                q->left = p->right;
            }else if(q->right == p){
                q->right = p->right;
            }
        }else{
            T->root = p->right;
        }
        free(p);
        return;
    }

    //Caso 3: p tiene dos hijos
    //Buscar maximo elemento en arbol izq
    TNode* maxp = p->left; // Contiene el elemento de reemplazo
    TNode* maxq = p; //Contiene el padre de maxp

    while(maxp->right!=NULL){
        maxq = maxp;
        maxp = maxp->right;
    }

    p->elem = maxp->elem;

    //Eliminar a maxp
    if(maxp->left==NULL){
        if(maxq ->left == maxp)
            maxq->left = NULL;
        else if(maxq->right == maxp)
            maxq->right = NULL;
        free(maxp);
        return;
    }else{
       if(maxq->left == maxp){
            maxq->left = maxp->left;
       }else if(maxq->right == maxp){
            maxq->right = maxp->left;
       }
        free(maxp);
        return;
    }



}

int search(TNode* node, TElemento x){
    TNode* aux = node;

    while(aux!=NULL){
        if(aux->elem == x){
            return 1;
        }else if(aux->elem > x){
            aux = aux->left;
        }else{
            aux = aux->right;
        }
    }
    return 0;
}