#ifndef ARBOL_H
#define ARBOL_H
typedef int TElemento;

typedef struct nodo{
	TElemento elem;
	struct nodo *left;
	struct nodo *right;
}TNode;

typedef struct arbol{
	TNode *root;
}TBinaryTree;

void init_tree(TBinaryTree* T);
void preorden(TNode* node);
void inorden(TNode* node);
void postorden(TNode* node);
void insert(TBinaryTree* T, TElemento x);
int count_tree(TNode* node);
int depth_tree(TNode* node);
int isABB(TNode* node);
void remove_tree(TBinaryTree* T, TElemento x);
int search(TNode* node, TElemento x);
int max(int a, int b);

#endif