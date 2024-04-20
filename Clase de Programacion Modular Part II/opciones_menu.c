#include "Menu.h"

// LEE EL (COMENTARIO) DEL Menu.h

void Saludar (char nombre[100]){

printf("\nIntroduce tu nombre: "); fflush(stdin); scanf("%s",nombre);

printf("\n\nMuchas gracias '%s' por usar este codigo para aprender o recorda el concepto de la programacion modular.\nSi deseas aprender mas cosas de C entra en mi Github *EnriqueBDeL*.",nombre);

}


void Definicion (){

printf("\n\nLa programacion modular es un enfoque de desarrollo de software que consiste en dividir un programa en partes mas pequenas y autonomas llamadas modulos.\nCada modulo tiene una funcion especifica y se comunica con otros modulos a traves de interfaces bien definidas.\nEste enfoque ayuda a organizar el codigo, facilita la reutilizacion y el mantenimiento, y permite que multiples desarro lladores trabajen de manera mas eficiente en un proyecto.");

}
