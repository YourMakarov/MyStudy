#ifndef LIST_H
#define LIST_H


typedef struct list_list {
    int size;
    char ** array;
} list;


list* createList();
void add_elem(int *count, char ***array);
int iterator(int index, int size, char move, char ***array);
void print_list(int *size, char ***array);
void add_in_index(int index, int *size, char ***array);
void delete_in_index(int index, int *size, char ***array);
void rev(int *size, char ***array);

#endif