//--------------------------------------------------------------------|
//                         PUNTEROS Y ARRAYS
//--------------------------------------------------------------------|
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   int array[4] = {10, 20, 30, 40};
   int contador;



printf("\n\nContenido del Array:\n");

   for(contador = 0; contador < 4; contador++){

     printf("%d\n", array[contador]);

   }

printf("\n\nDireccion de memoria del contenido del Array:\n");


   for(contador = 0; contador < 4; contador++){

     printf("%p\n", &array[contador]);

   }

printf("\n------------------------------------------------------------------------------------------|\nSi te fijas, a cada posicion de memoria se le ban sumando 4 bits al final de la direccion.\nEl tamano de un tipo int suele ser 4 bytes.\n------------------------------------------------------------------------------------------|\n");





   printf("\n\n\n%p\n", array); //Dirección del nombre dal Array
   printf("%p\n", &array[0]); //Dirección del primer elemento del Array


printf("\n------------------------------------------------------------------------------------------------|\nLa direccion de memoria del primer elemento del Array, es la misma que la del nombre del Array.\n------------------------------------------------------------------------------------------------|\n");



printf("\n\n%d", *array); /*El puntero direcciona al nombre array, que tiene la misma direccion que
                              la primera posicion del array.
                               Esto hace que *array tenga el valor de array[0].
                            */


printf("\n\n%d\n", *(array + 1));
printf("%d\n", *(array + 2));



//------------------------------------------------------------------------------------------------------


printf("\n\nPuntero direccionado al Array:\n");



int *puntero = array;



   for(contador = 0; contador < 4; contador++){

    printf("%d\n", *(puntero + contador));

    }


printf("\n\nCambio de valores Array:\n");

*array = 15; //Cambia el primer valor del Array.

printf("%d\n", *array);

*(array+1) = 25; //Cambia el segundo valor del Array.

printf("%d\n", *(array + 1));



printf("%d\n", *(array + 2));
printf("%d\n", *(array + 3));


    return 0;
}
