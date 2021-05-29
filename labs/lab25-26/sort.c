#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "stack.h"

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

Node_t * procedure(Node_t **head) {
    if (head == NULL) {
        exit(OUT_OF_MEMORY);
    }
    Node_t *actual = NULL;
    Node_t *ref = NULL;
    int count;
    int tmp;
    push(&actual, pop2(head));
    while (getSize(*head)) {
        count = pop2(head);
        if (peek(actual) >= count) {
            push(&actual, count);
        } else {
            tmp = pop2(&actual);
            push(&actual, count);
            push(&actual, tmp);
        }

    }
    while (actual) {
        push(&ref,pop2(&actual));
    }
    return ref;
}