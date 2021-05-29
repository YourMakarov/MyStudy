#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

void push(Node_t **head, T value) {
    Node_t *tmp = malloc(sizeof(Node_t));
    if (tmp == NULL) {
        exit(STACK_OVERFLOW);
    }
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}


T pop2(Node_t **head) {
    Node_t *out;
    T value;
    if (*head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}


T peek(const Node_t* head) {
    if (head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    return head->value;
}


void printStack(const Node_t* head) {
    printf("stack >");
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
}


int getSize(const Node_t *head) {
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}