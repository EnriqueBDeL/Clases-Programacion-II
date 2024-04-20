#include "Menu.h"

// LEE EL (COMENTARIO) DEL Menu.h

int Menu (){
int opciones;
printf("\n\n\n****MENU****:");
printf("\n1.Saluda.");
printf("\n2.Definicion de Programa Modular.");
printf("\n0.Salir.");
printf("\n\nIntroduce una opcion: ");   fflush(stdin);    scanf("%d",&opciones);
return opciones;
}
