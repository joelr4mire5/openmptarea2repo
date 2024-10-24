#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> // Incluir la biblioteca OpenMP

int main() {
    int tamano_arreglo, i;
    float suma_arreglo = 0, promedio;
    clock_t start_time, end_time;
    double total_time;

    start_time = clock();

    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &tamano_arreglo);

    int arr[tamano_arreglo];

    srand(32);
#pragma omp parallel for
    for(i = 0; i < tamano_arreglo; i++) {
        arr[i] = rand() % 100; // Números aleatorios entre 0 y 99
    }

#pragma omp parallel for reduction(+:suma_arreglo)
    for(i = 0; i < tamano_arreglo; i++) {
        printf("%d ", arr[i]);
        suma_arreglo += arr[i]; // Sumar los elementos al total
    }

    promedio = suma_arreglo / tamano_arreglo;

    printf("\nPromedio de los números aleatorios en el arreglo: %.2f\n", promedio); // Imprimir con dos decimales

    end_time = clock();

    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("El tiempo de ejecución fue de: %.6f segundos\n", total_time);

    return promedio;
}
