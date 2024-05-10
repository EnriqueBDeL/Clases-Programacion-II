#include "Header.h"

// Menú de interacción para árboles de coches
int menu() {
    int opcion;
    printf("\n\n****MENU****:");
    printf("\n1. Insertar un coche.");
    printf("\n2. Buscar un coche.");
    printf("\n3. Eliminar un coche.");
    printf("\n4. Listar coches.");
    printf("\n5. Salir.");
    printf("\n\nIntroduce una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int main() {

    int opcion, ano;

    P_NODO_ARBOL arbol = NULL;

    COCHE coche;

for(;;){
        opcion = menu();

        switch (opcion) {
            case 1:  // Insertar un coche
                printf("\nIntroduce la marca: ");
                scanf("%s", coche.marca);
                printf("Introduce el modelo: ");
                scanf("%s", coche.modelo);
                printf("Introduce el ano: ");
                scanf("%d", &coche.ano);
                arbol = insertar(arbol, coche);
                printf("Coche insertado.\n");
                break;

            case 2:  // Buscar un coche
                printf("\nIntroduce el ano del coche a buscar: ");
                scanf("%d", &ano);
                if (encontrar(arbol, ano) != NULL) {
                    printf("Coche encontrado.\n");
                } else {
                    printf("Coche no encontrado.\n");
                }
                break;

            case 3:  // Eliminar un coche
                printf("\nIntroduce el ano del coche a eliminar: ");
                scanf("%d", &ano);
                arbol = eliminar(arbol, ano);
                printf("Coche eliminado.\n");
                break;

            case 4:  // Listar coches
                printf("Lista de coches:\n");
                inOrder(arbol);
                break;

            case 5:  // Salir
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }

    }
    return 0;
}
