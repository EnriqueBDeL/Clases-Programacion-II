#include "Header.h"

int menu() {
    int opcion;
    printf("\n\n****MENU****:");
    printf("\n1. Insertar un coche.");
    printf("\n2. Buscar un coche.");
    printf("\n3. Eliminar un coche.");
    printf("\n4. Listar coches (InOrder).");
    printf("\n5. Listar coches (PreOrder).");
    printf("\n6. Listar coches (PostOrder).");
    printf("\n7. Salir.");
    printf("\n\nIntroduce una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
