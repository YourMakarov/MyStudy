#include <stdio.h>
#include "tree.h"

int main() {
    node *root;
    printf("if you would like to finish this program write 'f'\nIf you want to create a tree write '1'\nIf you want to check tree structure write '2'\nIf you want to choose actual node write '3'\nIf you want to add a new node to chosen node write '4'\nIf you want to delete chosen node write '5'\nIf you want to to find the list with min depth write 6\n");
    for ( ; ; ) {
        int key = 0;
        node* a;
        int min_depth_count = -999999;
        int depth_result;
        char c = getchar();
        if (c == 'f') {
            break;
        }
        if (c == '1') {
            printf("Write root's value\n");
            scanf("%d", &key);
            root = tree_create(key);
            printf("The tree was created\n");
        }
        if (c == '2') {
            if (root != NULL) {
                show_tree(root);
            }
        }
        if (c == '3') {
            if (root != NULL) {
                a = choose_node(root);
                printf("The node was chosen\n");
            }
        }
        if (c == '4') {
            if (a != NULL) {
                printf("Write node's value\n");
                scanf("%d", &key);
                tree_add_node(a, key);
                printf("The node with value %d was added\n", key);
            }
        }
        if (c == '5') {
            if (a != NULL) {
                remove_node(a);
            }
        }
        if (c == '6') {
            if (root != NULL) {
                min_depth(root, &min_depth_count, &depth_result);
                printf("A value of list is %d\n", depth_result);
                printf("its depth is %d\n", -min_depth_count);
                min_depth_count = -999999;
            }

        }
    }
    return 0;
}