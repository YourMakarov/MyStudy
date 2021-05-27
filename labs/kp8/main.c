#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "list.h"

int main()
{
 list * l = createList();
    add_elem(&l->size, &l->array);
    add_elem(&l->size, &l->array);
    add_elem(&l->size, &l->array);
    add_elem(&l->size, &l->array);
    printf("\n");
    add_in_index(0, &l->size, &l->array);
    print_list(&l->size, &l->array);
    printf("%d\n", l->size);
    printf("\n");
    rev(&l->size, &l->array);
    print_list(&l->size, &l->array);
    printf("\n");
    delete_in_index(0, &l->size, &l->array);
    print_list(&l->size, &l->array);
    //print_list(&count, &array);
    //for(int i = 0; i < count; i++) {
    //    free(array[i]);
    //}
    //free(array);
    return (0);
}