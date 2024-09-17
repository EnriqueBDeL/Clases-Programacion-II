#include <stdio.h>
#include <stdlib.h>

/*

DEFINICION:

Un puntero es una variable que almacena la dirección de memoria de otra variable como su valor.

Una variable de puntero apunta a un tipo de datos (como int) del mismo tipo y se crea con el * operador.

                                      -w3schools-

*/


int main()
{

int edad = 43;

//---------------------|
int *puntero = &edad;    // "&edad" obtiene la direccion de la edad. En mi caso es "000000000061FE14".
/*

Lo que hace esto es:

    "puntero" guarda la direccion de "edad". En mi caso es "000000000061FE14".

                        y

    "*puntero" guarda el resultado de "edad". En este caso 43.

*/

printf("%p\n", puntero); // "%p" sirve para imprimir direcciones de memoria.

printf("%p\n", &edad);


printf("%d\n", edad);

printf("%d\n", *puntero);

    return 0;
}
