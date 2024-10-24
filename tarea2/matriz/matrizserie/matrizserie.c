#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para inicializar una matriz con valores aleatorios
void inicializarMatriz(int **matriz, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 10;  // Valores aleatorios entre 0 y 9
        }
    }
}

// Función para multiplicar dos matrices A y B y almacenar el resultado en la matriz C
void multiplicarMatrices(int **A, int **B, int **C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;  // Inicializamos el valor de la posición C[i][j]
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para liberar la memoria de una matriz
void liberarMatriz(int **matriz, int N) {
    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    srand(time(NULL));  // Inicializa la semilla para números aleatorios

    int N;
    printf("Introduce el tamaño de la matriz N: ");
    scanf("%d", &N);

    // Reservamos memoria para las matrices A, B y C
    int **A = (int **)malloc(N * sizeof(int *));
    int **B = (int **)malloc(N * sizeof(int *));
    int **C = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    // Inicializamos las matrices A y B con valores aleatorios
    inicializarMatriz(A, N);
    inicializarMatriz(B, N);

    // Medimos el tiempo antes de la multiplicación
    clock_t inicio = clock();

    // Realizamos la multiplicación de matrices
    multiplicarMatrices(A, B, C, N);

    // Medimos el tiempo después de la multiplicación
    clock_t fin = clock();

    double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución para N=%d: %f segundos\n", N, tiempoTranscurrido);

    // Liberamos la memoria de las matrices
    liberarMatriz(A, N);
    liberarMatriz(B, N);
    liberarMatriz(C, N);

    return 0;
}

