//-------------------------------------------------------------------------------------------------------
#include "Menu.h" //Para conectar un fichero .h con el main, debes poner #include "nombre_del_fichero.h"
//-------------------------------------------------------------------------------------------------------

//Esto sirve para tener mucho más legible el codigo, ya que esto hace que haga lo mismo que si estubiese en un unico fichero pero separado por partes.


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

case 0:

    printf("Saliendo...");
    return 0;

    break;


        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------
// En este primer codigo de programacion modular solo vamos a aprender a vincular un header (.h). En el siguiente aprenderás a vincular un source (.c).
//----------------------------------------------------------------------------------------------------------------------------------
