#include "Header.h"

int Menu(){
int opcion;
printf("\n\n****MENU****:\n");
printf("1. Agrega una consola.\n");
printf("2. Elimina una consola.\n");
printf("3. Mostrar consolas.\n");
printf("4. Salir.");
printf("\nIntroduce una opcion: "); scanf("%d",&opcion);
return opcion;
}
