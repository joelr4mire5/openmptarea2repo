#include <stdio.h>
#include <time.h> // Biblioteca para medir el tiempo

double f(double x) {
    return x * x;
}

double trapezoidal_rule(double a, double b, int N) {
    double h = (b - a) / N; // Tamaño de cada división
    double sum = 0.0;

    // Calculamos los valores de los extremos
    sum += f(a) + f(b);

    // Calculamos las sumas intermedias
    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    // Aplicamos la fórmula del trapecio
    return (h / 2) * sum;
}

int main() {
    double limite_inferior, limite_superior;
    int divisiones;

    // Leemos los valores de a, b y N
    printf("Ingrese el valor de a (límite inferior): ");
    scanf("%lf", &limite_inferior);
    printf("Ingrese el valor de b (límite superior): ");
    scanf("%lf", &limite_superior);
    printf("Ingrese el número de divisiones N: ");
    scanf("%d", &divisiones);

    // Medir el tiempo de ejecución
    clock_t start_time, end_time;
    double cpu_time_used;

    // Registramos el tiempo de inicio
    start_time = clock();

    // Calculamos la integral
    double result = trapezoidal_rule(limite_inferior, limite_superior, divisiones);

    // Registramos el tiempo de finalización
    end_time = clock();

    // Calculamos el tiempo usado
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Mostramos el resultado
    printf("El valor aproximado de la integral es: %lf\n", result);
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);

    return 0;
}
