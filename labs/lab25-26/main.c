#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102


int main() {
    Node_t *head = NULL;
    int value = 1;
    while (value != 0) {
        scanf("%d", &value);
        push(&head, value);
    }
    int size = getSize(head);
    for (int i = 0; i < size; i++) {
        head = procedure(&head);
    }
    head = procedure(&head);
    printStack(head);
    return 0;
}