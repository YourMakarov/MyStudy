#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "matrix.h"

int search_value (int size, int i, int j, int str[], int stb[], int value[]) {
    int num = 0;
    for (int a = 0; a < size; a++) {
        if ((str[a] == i) && (stb[a] == j)) {
            num = a;
            return value[num];
            }
        }
    return 0;
}

int is_diag(int size, int m, int n, int value[], int str[], int stb[]) {
    int is_d = 1;
    if (m == n) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i != j) && (search_value(size, i, j, str, stb, value) != 0)) {
                    is_d = 0;
                };
            }
        }
    } else is_d = 0;
    return is_d;
}

void print_mass(int size, int value[], int str[], int stb[]) {
    printf("values:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", value[i]);
    }
    printf("\n");
    printf("str:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", str[i]);
    }
    printf("\n");
    printf("stb:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", stb[i]);
    }
    printf("\n");
}

void print_matrix(int size, int m, int n, int str[], int stb[], int value[]) {
    int p = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            p = search_value(size, i, j, str, stb, value);
            printf("%d ", p);
        }
        printf("\n");
    }
}