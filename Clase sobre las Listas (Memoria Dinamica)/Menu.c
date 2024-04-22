#include "Header.h"


int Menu(){
int opciones;
    printf("\n\n****MENU****:\n");
    printf("1. Insertar nombre.\n");
    printf("2. Eliminar nombre.\n");
    printf("3. Imprimir lista.\n");
    printf("4. Salir.\n");
    printf("Seleccione una opcion: ");  fflush(stdin);  scanf("%d", &opciones);
return opciones;
}
