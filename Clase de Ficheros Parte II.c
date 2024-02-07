#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//                                        ||PARTE II DE FICHEROS||

//---------------------------------------------------------------------------------------------------------------
// ESTE CODIGO CONTIENE LOS CONOCIMIENTOS BASICOS DE FICHEROS.
// PARA APRENDER FICHEROS NECESITAS EL CONOCIMIENTO DE MIS ANTEIRORES CODIGOS.
//---------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------
// RECUERDA QUE SI  QUIERES HABRIR UN FICHERO, DEBES CREAR EN UN ARCHIVO POR EJEMPLO ".txt" DENTRO DE PROYECTO,
// JUSTO DONDE ESTÁ EL main.C
//---------------------------------------------------------------------------------------------------------------

struct Fichero {

    char nombre[100];
    char texto[1000];

};



int main() {

    FILE *fichero;


    struct Fichero miFichero;


for(;;){
    printf("\n\nIntroduce el nombre del fichero: "); scanf("%s", miFichero.nombre);




    fichero = fopen(miFichero.nombre, "r");//Abrir el fichero en modo lectura

    if (fichero == NULL) {

//------------------------------------------------
        printf("\nError al abrir el fichero.\n");
//------------------------------------------------


    } else {


//------------------------------------------------
        printf("\nContenido del fichero:\n");
//------------------------------------------------

 printf("\nContenido de %sn",miFichero.nombre);
 printf("\n------------------------\n");

        while (fgets(miFichero.texto, 1000, fichero) != NULL) { //"fgets" se utiliza para leer una línea de texto de un fichero.

                                                                // Lee el fichero línea por línea hasta llegar al final del fichero.
                                                                // Cada línea leída se almacena en "miFichero.texto"

            printf("%s", miFichero.texto);


        }
printf("\n------------------------\n");


        fclose(fichero);//Cerrar el fichero


    }


//-------------------------------------------------------------------------------------------------------------------------------------
printf("\n\n\nHola, espero que te haya ayudado este codigo, si quieres la parte 3 de ficheros,\nescribe a enriquebraquehaisdelara@gmail.com o mira mi Github EnriqueBDL.");
printf("\n\nEste documento es de uso pribado, por lo que si se comparte sin permiso, sera denunciado.\n\n");
//-------------------------------------------------------------------------------------------------------------------------------------



}




return 0;
}
