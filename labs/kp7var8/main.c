#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"

int main(){

    char *filename;

    filename = "test1.txt";

    FILE *file = fopen(filename, "r");
    if (file == NULL) return 2;


    int a = 1, b = 1;
    int c = 1, d = 1;

    fscanf(file,"%d",&a);
    fscanf(file,"%d",&b);

    int *m, *n, *value;
    m = (int*)malloc(a*b * sizeof(int));
    n = (int*)malloc(a*b * sizeof(int));
    value = (int*)malloc(a*b * sizeof(int));
    
    int *m2, *n2, *value2;
    m2 = (int*)malloc(c*d * sizeof(int));
    n2 = (int*)malloc(c*d * sizeof(int));
    value2 = (int*)malloc(c*d * sizeof(int));
    int e = a, f = d;

    int *m3, *n3, *value3;
    m3 = (int*)malloc(e*f * sizeof(int));
    n3 = (int*)malloc(e*f * sizeof(int));
    value3 = (int*)malloc(e*f * sizeof(int));

    int k = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int tmp;
            fscanf(file,"%d", &tmp);
            //printf("%d ", tmp);
            if (tmp != 0) {
                value[k] = tmp;
                //printf("%d ", tmp);
                m[k] = i + 1;
                //printf("%d ", i);
                n[k] = j + 1;
                //printf("%d ", j);
                k++;
            }
        }
    }



    fscanf(file,"%d",&c);
    fscanf(file,"%d",&d);

    

    int g = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            int tmp;
            fscanf(file,"%d", &tmp);
            //printf("%d ", tmp);
            if (tmp != 0) {
                value2[g] = tmp;
                //printf("%d ", tmp);
                m2[g] = i + 1;
                //printf("%d ", i);
                n2[g] = j + 1;
                //printf("%d ", j);
                g++;
            }
        }
    }

    int e = a, f = d; 

    int h = 0;
    if (b == c) {
        printf("Multiply could be done\n");
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= d; j++) {
                int tmp = 0;

                for(int z = 1; z <= b; z++) {
                    tmp += search_value(k, i, z, m, n, value) * search_value(g, z, j, m2, n2, value2);
                }
                if (tmp != 0) {
                    value3[h] = tmp;
                    m3[h] = i;
                    n3[h] = j;
                    h++;
                }
            }
    } else {
        printf("Multiply could not be done\n");
    }

    print_mass(k, value, m, n);
    print_matrix(k, a, b, m, n, value);
    print_mass(g, value2, m2, n2);
    print_matrix(g, c, d, m2, n2, value2);
    print_mass(h, value3, m3, n3);
    print_matrix(h, e, f, m3, n3, value3);
    if (is_diag(h, e, f, value3, m3, n3) == 1) {
        printf("Multiplied matrix is diag.\n");
    } else {
        printf("Multiplied matrix is not diag.\n");
    }

    free(n);
    free(m);
    free(value);
    free(n2);
    free(m2);
    free(value2);
    free(n3);
    free(m3);
    free(value3);
    fclose(file);

    return 0;

}