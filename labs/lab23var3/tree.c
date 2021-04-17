#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

struct Node {
    int value;                   // значение узла
    int depth;
    struct Node* down;          // сын
    struct Node* right;         // младший брат
    struct Node* up;
    struct Node* left;
};

node *tree_create(int key)
{
    node *tree = (node *) malloc(sizeof(node));
    tree->value = key;
    tree->depth = 0;
    tree->down = NULL;
    tree->right = NULL;
    tree->up = NULL;
    tree->left = NULL;
    return tree;
}

void *tree_add_node(node *root, int key)
{
    node *res = tree_create(key);
    if (root->down == NULL) {
        root->down = res;
        res->up = root;
        res->depth = root->depth - 1;
    } else {
        node *last = root->down;
        res->depth = root->depth - 1;
        while (last->right != NULL) {
            last = last->right;
        }
        last->right = res;
        res->left = last;
    }
}

void print_node(node *n) {
    //printf(": ");
    node *last = n;
    while (last->right != NULL) {
        printf(" %d", last->value);
        last = last->right;
    }
    printf(" %d\n", last->value);
}

void show_tree(node *t) {
    if (t == NULL) {
        return;
    }
    printf("%d:\n", t->value);
    if (t->down != NULL) print_node(t->down);
    show_tree(t->right);
    show_tree(t->down);
}

void support_remover(node *t) {
    if (t != NULL) {
        support_remover(t->right);
        support_remover(t->down);
        printf("node with value %d was deleted\n", t->value);
        free(t);
        t->right = NULL;
        t->down = NULL;
    }
}

void remove_node(node *t) {
    if (t != NULL) {
        if (t->left != NULL) {
            node *a = t->left;
            a->right = NULL;
        }
        if (t->up != NULL) {
            node *a = t->up;
            a->down = NULL;
        }
        support_remover(t);
    }
}

void min_depth(node *t, int *mdepth, int *count) {
    if (t == NULL) {
        return;
    }
    min_depth(t->right, mdepth, count);
    min_depth(t->down, mdepth, count);
    if ((t->depth > *mdepth) && (t->down == NULL)) {
        *mdepth = t->depth;
        *count = t->value;
    }
}

node *choose_node(node *root) {
    node *a = root;
    char c;
    printf("You are choosing the node, if you would like finish choosing, write 'f'\n  Write 's' to choose actual node's son\n  Write 'w' to choose actual node's father\n  Write 'a' to choose actual node's elder brother\n  Write 's' to choose actual node's younger brother\n  If chosen node doesn't exist you'll get NULL\n");
    for ( ; ; )
    {
        printf("Actual node with value %d\n", a->value);
        printf("This node has\n");
        if (a->up != NULL) {
            printf("  father with value %d;\n", a->up->value);
        }
        if (a->left != NULL) {
            printf("  elder brother with value %d;\n", a->left->value);
        }
        if (a->right != NULL) {
            printf("  younger brother with value %d;\n", a->right->value);
        }
        if (a->down != NULL) {
            printf("  son with value %d;\n", a->down->value);
        }
        if ((a->up == NULL) && (a->down == NULL) && (a->left == NULL) && (a->right == NULL)){
            printf("  no relative node.\n");
        }
        printf("\n");
        c = getchar();
        if (c == 'f') {
            printf("Node with value %d chosen\n", a->value);
            return a;
        }
        if (c == 's') {
            a = a->down;
            if (a == NULL) {
                printf("Node is NULL\n");
                return NULL;
            }

        }
        if (c == 'd') {
            a = a->right;
            if (a == NULL) {
                printf("Node is NULL\n");
                return NULL;
            }

        }
        if (c == 'w') {
            a = a->up;
            if (a == NULL) {
                printf("Node is NULL\n");
                return NULL;
            }

        }
        if (c == 'a') {
            a = a->left;
            if (a == NULL) {
                printf("Node is NULL\n");
                return NULL;
            }

        }
    }
}