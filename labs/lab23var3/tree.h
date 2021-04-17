#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

node *tree_create(int key);
void *tree_add_node(node *root, int key);
void print_node(node *n);
void show_tree(node *t);
void support_remover(node *t);
void remove_node(node *t);
void min_depth(node *t, int *mdepth, int *count);
node *choose_node(node *root);

#endif // _TREE_H_