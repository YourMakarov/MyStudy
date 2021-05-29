#ifndef STACK_H
#define STACK_H


typedef int T;
typedef struct Node_tag {
    T value;
    struct Node_tag *next;
} Node_t;


void push(Node_t **head, T value);
T pop2(Node_t **head);
T peek(const Node_t* head);
void printStack(const Node_t* head);
int getSize(const Node_t *head);

#endif