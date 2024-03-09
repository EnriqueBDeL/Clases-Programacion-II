#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//---------------------------------------------------------------------------------------------------------------
// ESTE CODIGO CONTIENE LOS CONOCIMIENTOS BASICOS DE MEMORIA DINAMICA II.
//---------------------------------------------------------------------------------------------------------------


struct Mercedes {
int ID;
char Tipo[50];
char Modelo[50];
float Precio;
};




int Menu(){
int opciones;
printf("\n\n****MENU****\n");
printf("\n1. Anadir coche.");
printf("\n2. Eliminar coche.");
printf("\n3. Mostrar coches.");
printf("\n4. Salir del programa.");
return opciones;
}




int main()
{


int opciones = 0;
int numero_de_modelos = 0;
int id_eliminar = 0;
int encontrado;

//-----------------------------------------------------------------------------
 struct Mercedes *coches = (struct Mercedes*)malloc(sizeof(struct Mercedes));
//------------------------------------------------------------------------------


/*

Funcionamiento:

+ El puntero "*coches" es declarado como un puntero a una estructura "Mercedes".

+ Se usa "malloc" para asignar memoria para un solo objeto "Mercedes".


Detallado:

 struct Mercedes *coches                =              (struct Mercedes*)                       malloc(sizeof(struct Mercedes));

Declara un puntero llamado "*coches" ||       Se utiliz para indicar que el                ||  Se utiliza la función "malloc" para asignar dinámicamente
que apunta a un objeto de tipo       ||     puntero devuelto por "malloc" se trata         ||  un bloque de memoria del tamaño de una estructura "Mercedes".
"struct Mercedes".                   ||   como un puntero a una estructura "Mercedes".     ||  La función "sizeof" devuelve el tamaño en bytes de la estructura "Mercedes".
                                                                                           ||  Lo que garantiza que se reserve suficiente memoria para almacenar un objeto completo de ese tipo.
*/


for(;;){

opciones = Menu();

printf("\n\nIntroduce una opcion: "); scanf("%d",&opciones);

switch(opciones){




//------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                    AÑADIR UN COCHE
//------------------------------------------------------------------------------------------------------------------------------------------------------
case 1:

  numero_de_modelos++;


//Asigna mas memoria para almacenar la información del nuevo coche.
//-----------------------------------------------------------------------------------------
  coches = (struct Mercedes*)realloc(coches, numero_de_modelos * sizeof(struct Mercedes));
//-----------------------------------------------------------------------------------------

//printf("\n Numero de espacio: %d",numero_de_modelos);          //Descomentalo para revisar en que posición se encuntra guardado.


printf("\nIntroduce el ID del coche: "); fflush(stdin); scanf("%d",&coches[numero_de_modelos - 1].ID);

printf("\nIntroduce el tipo del coche: "); fflush(stdin);  scanf("%s", coches[numero_de_modelos - 1].Tipo);

printf("\nIntroduce el modelo del coche: "); fflush(stdin);  scanf("%s", coches[numero_de_modelos - 1].Modelo);

printf("\nIntroduce el precio del coche: "); fflush(stdin); scanf("%f",&coches[numero_de_modelos - 1].Precio);


    break;




//------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                    ELIMINAR UN COCHE
//------------------------------------------------------------------------------------------------------------------------------------------------------

case 2:


       if (numero_de_modelos > 0) {

            printf("Introduce el ID del coche que deses eliminar: "); fflush(stdin); scanf("%d",&id_eliminar);

          for (int j = 0; j < numero_de_modelos; j++) {
            if (coches[j].ID == id_eliminar) {


                encontrado = 1; // Se encontró el ID



                // Mover todos los coches una posición hacia atrás
                for (int k = j; k < numero_de_modelos - 1; k++) {
                    coches[k] = coches[k + 1];
                }


                // Redimensionar el arreglo para eliminar el último coche.
                //(Reduce el tamaño del bloque de memoria para eliminar la información del coche eliminado.)

                //-----------------------------------------------------------------------------------------
                coches = (struct Mercedes*)realloc(coches, (numero_de_modelos - 1) * sizeof(struct Mercedes));
                //-----------------------------------------------------------------------------------------


                numero_de_modelos--;


                printf("\nCoche eliminado correctamente.");
                break;
            }
        }

        if (!encontrado) {

            printf("\nNo se encontró ningún coche con el ID proporcionado.");

        }
    } else {

        printf("\nNo hay coches para eliminar.");

    }


    break;



//------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                    MOSTRAR COCHES GUARDADOS
//------------------------------------------------------------------------------------------------------------------------------------------------------

case 3:


   printf("\nCoches almacenados:");

     for (int i = 0; i < numero_de_modelos; i++) {

                    //printf("\n Numero de espacio: %d",i);        //Descomentalo para revisar en que posición se encuntra guardado.
                    printf("\nID: %d", coches[i].ID);

                    printf("\nTipo de coche: %s", coches[i].Tipo);

                    printf("\nModelo: %s", coches[i].Modelo);

                    printf("\nPrecio: %f", coches[i].Precio);

                    printf("\n*****************************");

      }


    break;





case 4:

    //-------------------------------------------------------------------------------------------------------------------------------------
    printf("\n\n\nHola, espero que te haya ayudado este codigo, si quieres la parte 3 de memoria dinamica, mira mi Github EnriqueBDL.\n\n");
    //-------------------------------------------------------------------------------------------------------------------------------------

    free(coches);

    return 0;


    break;




}//end switch
}//end for
    return 0;
}//end main
