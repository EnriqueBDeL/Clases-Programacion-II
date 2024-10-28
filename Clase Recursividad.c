#include <stdio.h>
#include <stdlib.h>


int ParoImpar(int n) {

    if (n % 2 == 0) {

        return 1; // Retorna 1 si es par

    } else {

        return 0; // Retorna 0 si es impar

    }

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int suma(int n2) {//(*)

    if (n2 <= 1) {

        return n2;

    } else {

        return n2 + suma(n2 - 1); // Llamada recursiva (*)

    }
}

/*

Ej: numero2 = 4 -> n2 =4 -> 4>1 -> return 4 + suma(3) -> 3>1 -> return 3 + suma(2) -> 2>1 ->

-> return 2 + suma(1)-> 2>1 -> return 2 + suma(1) -> 1 = 1 -> suma(2) = 2 + suma(1) = 2 + 1 = 3 ->

->suma(3) = 3 + suma(2) = 3 + 3 = 6 -> suma(4) = 4 + suma(3) = 4 + 6 = 10


*/

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int validarEntrada(int numero) {
    if (numero < 1 || numero > 10) {
        return -1; // Retorno -1 para indicar que la entrada es inválida
    }
    return 0; // Retorno 0 para indicar que la entrada es válida
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


int esPrimo(int n) {

    if (n < 0) {
        return 2; // Retorna 2 si el número no es válido (negativo)
    }

    if (n == 0 || n == 1) {
        return 0; // Retorna 0 para 0 y 1 (no son primos)
    }


        if (n % 2 == 0) {
            return -1; // Retorna -1 si el número es par
        }


    return 1; // Retorna 1 si el número es primo
}



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int Menu(){
int opcion;
printf("\n\n****MENU****\n");
printf("\n1. Ejemplo 1");
printf("\n2. Ejemplo 2");
printf("\n3. Ejemplo 3");
printf("\n4. Ejemplo 4");
printf("\n5. Ejemplo 5");
printf("\n\nSelecciona una opcion: "); scanf("%d",&opcion);
return opcion;
}


//%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


int main() {

int opcion, numero, numero2, numero3;


for(;;){

opcion = Menu();

switch (opcion){


case 1:

    printf("\nIntroduce un numero: "); scanf("%d", &numero);

    if (ParoImpar(numero)) {

        printf("\n> El numero %d es par.\n", numero);

    } else {

        printf("\n> El numero %d es impar.\n", numero);

    }

break;


case 2:

  printf("\n\nIntroduce un numero: "); scanf("%d", &numero2);

  printf("\n> La suma de los primeros %d numeros es %d\n", numero2, suma(numero2));


break;


case 3:


    printf("\n\nIntroduce un numero entero positivo: "); scanf("%d", &numero3);


    if (numero3 < 0) {

        printf("\n> Error: El numero no puede ser negativo.\n");

        return 1; // Retorno 1 para indicar un error
    }

     printf("\n> Has introducido el numero: %d\n", numero3);

break;


case 4:


     printf("\nIntroduce un numero entre 1 y 10: "); scanf("%d", &numero);

    if (validarEntrada(numero) == -1) {

        printf("\n> Error: Entrada invalida. El numero debe estar entre 1 y 10.\n");

    } else {

        printf("\n> Numero valido: %d\n", numero);
    }


break;



case 5:

  printf("\nIntroduce un numero: ");scanf("%d", &numero);

    int resultado = esPrimo(numero);

    if (resultado == 2) {
        printf("\nEl numero %d no es valido (negativo).\n", numero);
    } else if (resultado == 0) {
        printf("\nEl numero %d no es primo (es 0 o 1).\n", numero);
    } else if (resultado == -1) {
        printf("\nEl numero %d es par, pero no primo.\n", numero);
    } else if (resultado == 1) {
        printf("\nEl numero %d es primo.\n", numero);
    }

    return 0;

break;

        }
    }
}
