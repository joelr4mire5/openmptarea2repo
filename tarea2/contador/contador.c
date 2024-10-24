#include <stdio.h>
#include <omp.h>

int main() {
    int contador = 0;
    int N = 100000;
    int i;  // Declarar la variable i fuera del bucle for

    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        #pragma omp atomic
        contador++;
    }

    printf("Valor final del contador: %d\n", contador);
    return 0;
}
