#include <stdio.h>
#include <stdlib.h>

int main()
{

//MEMORIA ESTATICA

    int entero;
    float flotante;
    double doble;
    char caracter;

    printf("El tamano de un int es: %zu bytes\n", sizeof(entero));
    printf("El tamano de un float es: %zu bytes\n", sizeof(flotante));
    printf("El tamano de un double es: %zu bytes\n", sizeof(doble));
    printf("El tamano de un char es: %zu bytes\n\n\n", sizeof(caracter));

    system("pause"); //Para de ejecutar y no continuará hasta que presione alguna tecla.

    int i[10];
    float f[10];
    double d[10];
    char c[10];

    printf("\n\nEl tamano de un arreglo de 10 int es: %zu bytes\n", sizeof(i));
    printf("El tamano de un arreglo de 10 float es: %zu bytes\n", sizeof(f));
    printf("El tamano de un arreglo de 10 double es: %zu bytes\n", sizeof(d));
    printf("El tamano de un arreglo de 10 char es: %zu bytes\n\n\n", sizeof(c));

    system("pause");


//MEMORIA DINAMICA


//ASIGNAR MEMORIA

    int *puntero_entero;
    int tamano_entero = 10;

    puntero_entero = calloc(tamano_entero, sizeof(*puntero_entero));

    printf("\n\nEl tamano del puntero al entero: %d bytes\n", tamano_entero * sizeof(*puntero_entero));


    float *puntero_flotante;
    int tamano_flotante = 10;
    puntero_flotante = calloc(tamano_flotante, sizeof(*puntero_flotante));


    printf("El tamano del puntero al flotante: %d bytes\n", tamano_flotante * sizeof(*puntero_flotante));


    double *puntero_doble;
    int tamano_doble = 10;
    puntero_doble = calloc(tamano_doble, sizeof(*puntero_doble));

    printf("El tamano del puntero al doble: %d bytes\n", tamano_doble * sizeof(*puntero_doble));


    char *puntero_caracter;
    int tamano_caracter = 10;
    puntero_caracter = calloc(tamano_caracter, sizeof(*puntero_caracter));

    printf("El tamano del puntero al caracter: %d bytes\n\n\n", tamano_caracter * sizeof(*puntero_caracter));


    system("pause");

//ACCEDER A MEMORIA

    int *puntero;

    puntero = calloc(4, sizeof(*puntero)); //Calloc escribe ceros en toda la memoria asignada.

                  // 4 es el tamaño del puntero

     *puntero = 2;

     puntero[1] = 4;

     puntero[2] = 8;

     printf("\n\n*puntero = %d", *puntero);
     printf("\npuntero[1] = %d \npuntero[2] = %d\n\n\n",puntero[1] ,puntero[2]);


    system("pause");


//REASIGNAICON DE MEMORIA


    int *puntero1, tamano;


    puntero1 = malloc(4 * sizeof(int));
    tamano = 4 * sizeof(int);//Calcular el tamaño en bytes


    printf("\n\n%zu bytes se encuentran en la direccion %p\n", tamano, puntero1);



    puntero1 = realloc(puntero1, 8 * sizeof(int));//Devuelve un NULL puntero si no puede asignar más memoria.
    tamano = 8 * sizeof(int);// Calcular el nuevo tamaño en bytes



    printf("%zu bytes se encuentran en la nueva direccion %p\n", tamano, puntero1);




    //Si no hay suficiente espacio, se asignara un nuevo bloque de memoria.

    //Copiará los datos del bloque original a este nuevo bloque, liberará el bloque original y devolverá la nueva dirección.


//Ejemplo:

    puntero1 = realloc(puntero1, 300 * sizeof(int));//Devuelve un NULL puntero si no puede asignar más memoria.
    tamano = 300 * sizeof(int);

    printf("%zu bytes se encuentran en la nueva direccion %p\n\n\n", tamano, puntero1);




    //Cuando termines de usar memoria dinamica, se recomienda liberar memoria.

    free(puntero1);//Libera memoria



    return 0;
}
