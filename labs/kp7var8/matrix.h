#ifndef _MATRIX_H_
#define _MATRIXE_H_

#include <stdlib.h>
#include <malloc.h>

int search_value (int size, int i, int j, int str[], int stb[], int value[]);
int is_diag(int size, int m, int n, int value[], int str[], int stb[]);
void print_mass(int size, int value[], int str[], int stb[]);
void print_matrix(int size, int m, int n, int str[], int stb[], int value[]);

#endif
