#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//-------------------------- Todo lo que no esté entre las barras ( //-----------  ), son cosas que se generan automaticamente al hacer un fichero.h ------------------------------------------

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
/*

 En este .h hemos declarado todas las librerias (los includes) que va a necesitar nuestro codigo.

 Además hemos creado el menu como si lo hubieramos creado en el main.c.

*/
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Menu (){
int opciones;
printf("\n\n\n****MENU****:");
printf("\n1.Saluda");
printf("\n0.Salir");
printf("\n\nIntroduce una opcion: ");   fflush(stdin);    scanf("%d",&opciones);
return opciones;
}


void Saludar (char nombre[100]){

printf("\nIntroduce tu nombre: "); fflush(stdin); scanf("%s",nombre);

printf("\n\nMuchas gracias '%s' por usar este codigo para aprender o recorda el concepto de la programacion modular.\nSi deseas aprender mas cosas de C entra en mi Github *EnriqueBDeL*.",nombre);

}



//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // MENU_H_INCLUDED
