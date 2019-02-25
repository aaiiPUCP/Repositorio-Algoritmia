/* 
 * File:   Trees.h
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2015, 01:00 PM
 */

#ifndef TREES_H
#define	TREES_H

typedef char TElem;

typedef struct node
{
    TElem item;             //Estructura del arbol;
    struct node* left_t;
    struct node* right_t;
}t_tree;

void plantar(t_tree* tree,TElem item,t_tree* left,t_tree* right);

void create_Leaf(t_tree* tree,TElem item);

void print_noInt(t_tree* tree);



#endif	/* TREES_H */

