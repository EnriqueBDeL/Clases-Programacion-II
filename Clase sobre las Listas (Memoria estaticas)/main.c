#include "Header.h"

int main()
{

struct Lista lista;

int opciones;
int valor;

inicializarLista(&lista);


for(;;){

opciones = Menu();


switch (opciones){

case 1:
    if (lista.longitud < MAX_ELEMENTOS) {

    printf("Ingrese el valor a insertar (Ej:1234): "); scanf("%d", &valor);

    insertar(&lista, valor);

    } else {

    printf("Error: La lista está llena, no se puede insertar más elementos.\n");

    }
break;


case 2:

    imprimirLista(&lista);

break;

case 3:
        printf("Saliendo del programa.\n");
        return 0;

break;

default:

printf("Opcion invalida. Intente de nuevo.\n");

        }
    }
}
