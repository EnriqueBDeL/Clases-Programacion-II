#include "Menu.h"

//-------------------------------------------------------------------------------------------------
// En este segundo codigo de programacion modular vamos a aprenderás a vincular un source (.c).
//-------------------------------------------------------------------------------------------------

int main()
{

int opciones;
char nombre[100];


for(;;){

opciones = Menu();


switch (opciones){

case 1:

    Saludar(nombre);

    break;


case 2:

    Definicion();

    break;

case 0:

    printf("Saliendo...");
    return 0;

    break;


        }
    }
}



