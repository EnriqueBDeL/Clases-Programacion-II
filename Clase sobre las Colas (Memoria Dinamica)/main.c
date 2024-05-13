#include "Header.h"

int main(void) {

    tipo_cola cola;
    int opcion, anno, i;
    float precio;
    char id[20];
    char modelo[50];
    int cont = 0;
    int cont2 = 0;

    for (;;) {
        opcion = Menu();

        switch (opcion) {
            case 1:
                cola = crear(cola);
                cont = 0;
                cont2 = 0;
                printf("\nCola creada.");
                break;

            case 2:
                if (cola->cabeza == cola->cola) {
                    printf("\n\nLa cola esta vacia");
                } else {
                    printf("\n\nLa cola no está vacia");
                }
                break;

            case 3:
                if (cola->cabeza == cola->cola) {
                    printf("\n\nLa cola esta vacia");
                } else {
                    Avion avion = primero(cola);
                    printf("\n\nAvion en primer lugar:\nID: %s\nModelo: %s\nAno de creacion: %d\nPrecio: %.2f\n",
                           avion.id, avion.modelo, avion.anno_creacion, avion.precio);
                }
                break;

            case 4:
                printf("\nIntroduce el ID del avion: ");
                scanf("%s", id);
                printf("Introduce el modelo del avion: ");
                scanf("%s", modelo);
                printf("Introduce el ano de creacion del avion: ");
                scanf("%d", &anno);
                printf("Introduce el precio del avion: ");
                scanf("%f", &precio);

                Avion nuevo_avion;
                nuevo_avion.id = strdup(id);
                nuevo_avion.modelo = strdup(modelo);
                nuevo_avion.anno_creacion = anno;
                nuevo_avion.precio = precio;

                apilar(cola, nuevo_avion);
                cont++;
                break;

            case 5:
                suprime(cola);
                cont2++;
                break;

            case 6:
                printf("\nLista de aviones:");
                for (i = cola->cabeza; i != cola->cola; i = suma_uno(cola, i)) {
                    Avion avion = cola->valores[i];
                    printf("\nAvion %d:\nID: %s\nModelo: %s\nAno de creacion: %d\nPrecio: %.2f\n\n",i + 1, avion.id, avion.modelo, avion.anno_creacion, avion.precio);
                }
                break;

        }
    }
}
