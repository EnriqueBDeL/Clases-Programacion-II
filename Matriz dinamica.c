#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    int N, X, Y;

    printf("Introduce el tamano N de las matrices NxN: "); 
    scanf("%d", &N);

    int **A, **B, **C;

    A = (int **) malloc(N * sizeof(int *));
    // B = (int **) malloc(N * sizeof(int *));
    // C = (int **) malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++) {
        A[i] = (int *) malloc(N * sizeof(int));
        // B[i] = (int *) malloc(N * sizeof(int));
        // C[i] = (int *) malloc(N * sizeof(int));
    }

    //--------------------------------------------------------------------------
    printf("Introduce el tamano X: ");
    scanf("%d", &X);

    B = (int **) malloc(X * sizeof(int *));
    
    printf("Introduce el tamano Y: ");
    scanf("%d", &Y);

    for (int g = 0; g < X; g++) {
        B[g] = (int *) malloc(X * sizeof(int));
    }

    // Meter datos:
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0;
        }
    }

    //--------------------------------------------------------------------------
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            B[i][j] = 4;
        }
    }

    // Leer:
    for (int i = 0; i < N; i++) {
        printf("\n");
        for (int j = 0; j < N; j++) {
            printf("|%d|", A[i][j]);
        }
    }
    printf("\n");

    //--------------------------------------------------------------------------
    for (int i = 0; i < X; i++) {
        printf("\n");
        for (int j = 0; j < Y; j++) {
            printf("|%d|", B[i][j]);
        }
    }
    printf("\n");

    return 0;
}

