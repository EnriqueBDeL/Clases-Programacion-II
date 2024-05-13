#include "Header.h"

int Menu (){

int opcion;
printf("\n\n****MENU****");
printf("\n1. Crear cola.");
printf("\n2. Esta vacia?");
printf("\n3. Primero.");
printf("\n4. Insertar avion.");
printf("\n5. Eliminar avion.");
printf("\n6. Listar aviones.");
printf("\n7. Salir.");
printf("\n\nIntroduce una opcion: "); scanf("%d",&opcion);
return opcion;
}
