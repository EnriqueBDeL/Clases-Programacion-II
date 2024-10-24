#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Libreria necesaria para usar las instrucciones de tiempo.

int main() {

    clock_t start, end;  // Variables para almacenar el tiempo
    double cpu_time_used;

    //--------------------------------------------|
    start = clock(); // Capturar el tiempo inicial
    //--------------------------------------------|

    for (int i = 0; i < 10000; i++) {
            printf("\nImpresion %d",i);
    }

    //--------------------------------------------|
    end = clock();    // Capturar el tiempo final
    //--------------------------------------------|


    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;    // Calcular el tiempo transcurrido


    printf("\n\nTiempo de ejecucion: %f segundos\n", cpu_time_used);

    return 0;
}
