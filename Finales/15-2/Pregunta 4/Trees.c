#include <stdio.h>
#include <stdlib.h>

#include "Trees.h"

void plantar(t_tree* tree,TElem item,t_tree* left,t_tree* right)
{
    tree->item = item;
    tree->left_t = left;
    tree->right_t = right;
}

void create_Leaf(t_tree* tree,TElem item)
{
    tree->item = item;
    tree->left_t = NULL;
    tree->right_t = NULL;
}
int is_Leaf(t_tree* tree)
{
    return (tree->left_t == NULL && tree->right_t == NULL);
}

void print_post(t_tree* tree)
{
    if(tree==NULL) return;
    print_post(tree->left_t);
    print_post(tree->right_t);
    if(tree->item == 'G')
    {
        int x = 1;
    }
    if(is_Leaf(tree))
    {
        printf("%c ",tree->item);
    }
}

void print_noInt(t_tree* tree)
{
    if(tree == NULL) return;
    
    print_post(tree->left_t);
    print_post(tree->right_t);
    
    printf("%c ",tree->item);
    
}
