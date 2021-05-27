#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "list.h"

list* createList() {
    list *out = NULL;
    out = malloc(sizeof(list));
    if (out == NULL) {
        exit(1);
    }
    out->size = 1;
    out->array = malloc(out->size * sizeof(char *));
    if (out->array == NULL) {
        free(out);
        exit(1);
    }
    return out;
}

void add_elem(int *count, char ***array) {
    *count = *count + 1;
    *array = (char **) realloc(*array, (*count-1)*sizeof(char *));
    if (!*array) {
        printf("Error: can't allocate memory!");
        exit(EXIT_FAILURE);
    }
    (*array)[*count - 2] = (char*)malloc(100);
    if ((*array)[*count - 2] == NULL)
    {
        free(*array);
        exit(EXIT_FAILURE);
    }
    printf("enter string\n");
    scanf("%s", (*array)[*count - 2]);
}

int iterator(int index, int size, char move, char ***array){
    if ((index < size - 2) && (move == 'r') && (index >= 0)) {
        if ((*array)[index+1] != NULL) {
            printf("%s\n", (*array)[index+1]);
            return index+1;
        }
    }
    if ((index < size - 2) && (index > 0) && (move == 'l')) {
        if ((*array)[index-1] != NULL) {
            printf("%s\n", (*array)[index+1]);
            return index+1;
        }
    }
    exit(EXIT_FAILURE);
}

void print_list(int *size, char ***array){
    if (!*array) {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < *size -1; i++) {
        printf("%s\n", (*array)[i]);
    }
}

void add_in_index(int index, int *size, char ***array) {
    *size = *size + 1;
    *array = (char **) realloc(*array, (*size - 1)*sizeof(char *));
    if (!*array) {
        printf("Error: can't allocate memory!");
        exit(EXIT_FAILURE);
    }
    (*array)[*size - 2] = (char*)malloc(100);
    if ((*array)[*size - 2] == NULL)
    {
        free(*array);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; *size - index - i - 2 > 0; i++) {
        memmove((*array)[*size - 2 - i], (*array)[*size - 3 - i], sizeof((*array)[*size - 3 -i]));
    }
    printf("enter string\n");
    scanf("%s", (*array)[index]);
}
void delete_in_index(int index, int *size, char ***array) {
    if (!*array) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; index + i < *size - 2; i++) {
        memmove((*array)[index + i], (*array)[index + i + 1], sizeof((*array)[index + i + 1]));

    }
    free((*array)[*size-2]);
    *size = *size - 1;
}

void rev(int *size, char ***array) {
    if (!*array) {
        printf("Error: can't allocate memory!");
        exit(EXIT_FAILURE);
    }
    char * tmp;
    for(int i = 0; i <= (*size - 1) % 2; i++) {
        tmp = (*array)[i];
        (*array)[i] = (*array)[*size - 2 - i];
        (*array)[*size - 2 - i] = tmp;
    }
}