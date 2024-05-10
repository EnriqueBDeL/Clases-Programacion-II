#include "Header.h"

int main() {
    int opcion;
    char marca[50];
    P_NODO_ARBOL arbol = crearArbol();
    COCHE coche;

    for (;;) {
        opcion = menu();

        switch (opcion) {
            case 1:  // Insertar un coche
                printf("\nIntroduce la marca: ");
                scanf("%s", marca);
                coche.marca = strdup(marca);
                printf("Introduce el modelo: ");
                scanf("%s", marca);
                coche.modelo = strdup(marca);
                printf("Introduce el ano: ");
                scanf("%d", &coche.ano);
                arbol = insertar(arbol, coche);
                printf("Coche insertado.\n");
                break;

            case 2:  // Buscar un coche
                printf("\nIntroduce la marca del coche a buscar: ");
                scanf("%s", marca);
                if (encontrar(arbol, marca) != NULL) {
                    printf("Coche encontrado.\n");
                } else {
                    printf("Coche no encontrado.\n");
                }
                break;

            case 3:  // Eliminar un coche
                printf("\nIntroduce la marca del coche a eliminar: ");
                scanf("%s", marca);
                arbol = eliminar(arbol, marca);
                printf("Coche eliminado.\n");
                break;

            case 4:  // Listar coches (InOrder)
                printf("Lista de coches (InOrder):\n");
                inOrder(arbol);
                break;

            case 5:  // Listar coches (PreOrder)
                printf("Lista de coches (PreOrder):\n");
                preOrder(arbol);
                break;

            case 6:  // Listar coches (PostOrder)
                printf("Lista de coches (PostOrder):\n");
                postOrder(arbol);
                break;

            case 7:  // Salir
                printf("Saliendo...\n");
                exit(0);

            default:
                printf("Opción no valida.\n");
                break;
        }
    }

    return 0;
}
