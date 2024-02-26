#include <stdio.h>
#include <stdlib.h> //Carpeta necesaria para el uso de memoria dinamica
#include <string.h>

//---------------------------------------------------------------------------------------------------------------
// ESTE CODIGO CONTIENE LOS CONOCIMIENTOS BASICOS DE MEMORIA DINAMICA I.
//---------------------------------------------------------------------------------------------------------------


struct trabajador {
    char id[5];
    char nombre[50];
    int edad;
}; // End trabajador

int Menu() {
    int opciones;
    printf("\n*****MENU****");
    printf("\n1. Anadir trabajador.");
    printf("\n2. Eliminar trabajador.");
    printf("\n3. Listar trabajadores.");
    printf("\n4. Salir.");
    return opciones;
} // End menu

int main() {

    int opciones;
    struct trabajador *t = NULL; // Inicialmente no hay trabajadores
    int numero_de_trabajadores = 0; // Contador de trabajadores
    char id_elim[5];


//CONTROLADOR MEMORIA DINAMICA
//----------------------------------------------------------------------------------------
    t = realloc(t, numero_de_trabajadores * sizeof(struct trabajador));
//----------------------------------------------------------------------------------------

//Funcionamiento:
/*


   - "sizeof(struct trabajador)" calcula el tama�o en bytes de la estructura trabajador.

   - "numero_de_trabajadores * sizeof(struct trabajador)" te da el tama�o total necesario para almacenar todos los trabajadores en la memoria.


   - La sentencia "ralloc" en C se utiliza para cambiar el tama�o de un bloque de memoria ya existente. En este caso "trabajador".
     Declarado antes de esta sentencia.

   - "t" es el puntero que se le desa cambiar de tama�o.
      Si la asignaci�n falla, "realloc" devuelve "NULL", lo que indica un error.



*/

    for (;;) {
        Menu();

printf("\nIntroduce una opcion: "); fflush(stdin); scanf("%d", &opciones);

        switch (opciones) {


            case 1:

                numero_de_trabajadores++;

                if (t == NULL) {

                    printf("Error al asignar memoria.\n");
                    return 1;
                }


printf("\nIntroduce el ID del trabajador %d: ", numero_de_trabajadores); fflush(stdin); scanf("%s", t[numero_de_trabajadores - 1].id);

printf("\nIntroduce el nombre del trabajador %d: ", numero_de_trabajadores); fflush(stdin); scanf("%s", t[numero_de_trabajadores - 1].nombre);

printf("\nIntroduce la edad del trabajador %d: ", numero_de_trabajadores); fflush(stdin); scanf("%d", &t[numero_de_trabajadores - 1].edad);

                break;

case 2:

     printf("\nIntroduce el ID del trabajador que deseas eliminar: ");
                scanf("%s", id_elim);
                for (int r = 0; r < numero_de_trabajadores; r++) {
                    if (strcmp(id_elim, t[r].id) == 0) {
                        for (int i = r; i < numero_de_trabajadores - 1; i++) {
                            strcpy(t[i].id, t[i + 1].id);
                            strcpy(t[i].nombre, t[i + 1].nombre);
                            t[i].edad = t[i + 1].edad;
                        }
                        numero_de_trabajadores--;
                        break;
                    }
                }
                break;

case 3:

    printf("\nTrabajadores: ");

    for(int c = 0; c<numero_de_trabajadores;c++){

    printf("\nTrabajador numero: %d",c);
    printf("\nID: %s",t[c].id);
    printf("\nNombre: %s",t[c].nombre);
    printf("\nEdad: %d",t[c].edad);
    printf("\n*******************");

    }


    break;



            case 4:

                printf("\nPulse enter para salir...");

               //-------------------------------------
                free(t); // Libera la memoria asignada
               //-------------------------------------

                return 0;

            break;



        } // End switch
    } // End for

//-------------------------------------------------------------------------------------------------------------------------------------
printf("\n\n\nHola, espero que te haya ayudado este codigo, si quieres la parte 3 de ficheros, mira mi Github EnriqueBDL.");
printf("\n\nEste documento es de uso pribado, por lo que si se comparte sin permiso, sera denunciado.\n\n");
//-------------------------------------------------------------------------------------------------------------------------------------

    return 0;
} //End main

