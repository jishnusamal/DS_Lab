#include <stdio.h>
#include <stdlib.h>

void arrayProduct(int** a, int** b, int** p, int rw_a, int cl_a, int rw_b, int cl_b);

int main() {
    int rwa, cla, rwb, clb;

    printf("[A] Enter the no of rows: ");
    scanf("%d", &rwa);

    printf("[A] Enter the no of cols: ");
    scanf("%d", &cla);

    printf("[B] Enter the no of rows: ");
    scanf("%d", &rwb);

    printf("[B] Enter the no of cols: ");
    scanf("%d", &clb);

    // Element-wise product requires same shape
    if (cla != rwb) {
        printf("Matrix sizes must match for element-wise product.\n");
        return 1;
    }

    int** a = malloc(rwa * sizeof(int*));
    int** b = malloc(rwb * sizeof(int*));
    int** p = malloc(rwa * sizeof(int*));

    for (int i = 0; i < rwa; i++) {
        a[i] = malloc(cla * sizeof(int));
        p[i] = malloc(clb * sizeof(int));
    }
    for (int i = 0; i < rwb; i++) {
        b[i] = malloc(clb * sizeof(int));
    }

    for (int i = 0; i < rwa; i++) {
        for (int j = 0; j < cla; j++) {
            printf("[A] Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < rwb; i++) {
        for (int j = 0; j < clb; j++) {
            printf("[B] Element [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    arrayProduct(a, b, p, rwa, cla, rwb, clb);

    for (int i = 0; i < rwa; i++) {
        for (int j = 0; j < clb; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rwa; i++) {
        free(a[i]);
        free(p[i]);
    }
    for (int i = 0; i < rwb; i++) {
        free(b[i]);
    }

    free(a);
    free(b);
    free(p);

    return 0;
}

void arrayProduct(int** a, int** b, int** p, int rw_a, int cl_a, int rw_b, int cl_b) {
    for (int i = 0; i < rw_a; i++) {
        for (int j = 0; j < cl_b; j++) {
            p[i][j] = 0;
            for (int k = 0; k < cl_a; k++) {
                p[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

