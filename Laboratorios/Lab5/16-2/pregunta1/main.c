#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
//KPS
//EL programa imprimiRango va a tener que recorrer el árbol de forma inorder, y va a imprimir
//solo los elementos que se encuentran en el rango sugerido.
void imprimirRango(TNode *node,int ini,int fin){
	//Recoremos el arreglo como un inorden
	if (node==NULL)
		return;	
	imprimirRango(node->left,ini,fin);
	//Solo que imprimiremos los valores solo si cumplen la condición
	if (node->elem>=ini && node->elem<=fin)
			printf("%d ",node->elem);
	imprimirRango(node->right,ini,fin);
}
void main(){
    //Programa ejemplo para probar la funcionalidad básica
    TBinaryTree T;
    init_tree(&T);
    int s,t;
    insert(&T, 12);
    insert(&T, 7);
    insert(&T, 16);
    insert(&T, 4);
    insert(&T, 5);
    insert(&T, 8);
    insert(&T, 20);
    insert(&T, 14);
    insert(&T, 0);
    insert(&T, 30);
    insert(&T, 40);
    //No piden datos de entrada, aquí puede cambiar los valores de s y t
    s=8;
    t=30;
	imprimirRango(T.root,s,t);
	printf("\n");
}