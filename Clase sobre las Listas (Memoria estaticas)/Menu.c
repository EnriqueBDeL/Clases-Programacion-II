#include "Header.h"


int Menu(){
int opciones;
    printf("\n\n****MENU****:\n");
    printf("1. Insertar elemento.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Salir.\n");
    printf("Seleccione una opcion: ");  fflush(stdin);  scanf("%d", &opciones);
return opciones;
}
