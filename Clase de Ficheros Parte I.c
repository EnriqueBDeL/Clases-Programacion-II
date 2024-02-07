#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//---------------------------------------------------------------------------------------------------------------
// ESTE CODIGO CONTIENE LOS CONOCIMIENTOS BASICOS DE FICHEROS.
// PARA APRENDER FICHEROS NECESITAS EL CONOCIMIENTO DE MIS ANTEIRORES CODIGOS.
//---------------------------------------------------------------------------------------------------------------





//---------------------------------------------------------------------------------------------------------------
//                                      MENU
//---------------------------------------------------------------------------------------------------------------


int Menu (){

int opciones;

printf("\n****MENU****\n");
printf("1. Crear fichero.\n");
printf("2. Eliminar fichero.\n");
printf("3. Anadir texto.\n");
printf("4. Leer fichero.\n");
printf("0. Salir.\n");


return opciones;
}










//---------------------------------------------------------------------------------------------------------------
//                                            MAIN
//---------------------------------------------------------------------------------------------------------------


int main()
{


FILE *fichero;



//VARIABLES:
//---------------------------------------------------------------------------------------------------------------
int opciones;

char nombre_fichero [80];

int elimina; // "0" Es que se ha elimindado y "1" si no se ha eliminado

char modificaciones [200]; //Guarda el texto que quieres agregarle a un fichero.

char mostrar;
//---------------------------------------------------------------------------------------------------------------





//OPCIONES MENU:
for(;;){

    Menu();

printf("\nIntroduce una opcion: "); scanf("%d",&opciones);

switch(opciones){







//---------------------------------------------------------------------------------------------------------------
//                                    CREAR FICHERO
//---------------------------------------------------------------------------------------------------------------


 case 1:


printf("Introduce el nombre del archivo (Ejemplo: fichero.txt): "); fflush(stdin); gets(nombre_fichero);



//Abre el fichero en modo escribir
  fichero = fopen(nombre_fichero, "w");



//Comprobación
if (fichero == NULL) {
        printf("Error al crear el archivo!");
        return 1;
    }else{

    printf("\nFichero creado correctamente.\n");

    }



//Cierra el fichero
     fclose(fichero);


 break;





//---------------------------------------------------------------------------------------------------------------
//                                      ELIMINAR FICHERO
//---------------------------------------------------------------------------------------------------------------





 case 2:

printf("Introduce el nombre del archivo (Ejemplo: fichero.txt): "); fflush(stdin); gets(nombre_fichero);


//Elimina el archivo
 elimina = remove(nombre_fichero);



//Comprobación
  if (elimina == 0) {
        printf("El archivo ha sido eliminado correctamente.\n");
    } else {
        printf("Error: no se pudo eliminar el archivo.\n");
        return 1;
    }



 break;






//---------------------------------------------------------------------------------------------------------------
//                                      AÑADIR TEXTO
//---------------------------------------------------------------------------------------------------------------



 case 3:

 printf("Introduce el nombre del archivo (Ejemplo: fichero.txt): "); fflush(stdin); gets(nombre_fichero);


 fichero = fopen(nombre_fichero, "a");

 if (fichero == NULL) {
        printf("Error al abrir el archivo!");
        return 1;
    }

 printf("Introduzca el texto que dese guardar en el documento |%s|:",nombre_fichero); fflush(stdin); gets(modificaciones);

 fprintf( fichero, "%s" , modificaciones);



fclose(fichero);


 break;









 //---------------------------------------------------------------------------------------------------------------
//                                      LEER FICHERO
//---------------------------------------------------------------------------------------------------------------



 case 4:


 printf("Introduce el nombre del fichero a crear (Ejemplo: fichero1.txt): "); fflush(stdin); gets(nombre_fichero);


//Lee el fichero
fichero = fopen( nombre_fichero, "r");





 // COMPROBAR SI EXISTE EL FICHERO -----------------------------------------------------------------------------
 if ( fichero != NULL){


    printf("\nEl fichero se ha abierto correctamente.\n");


 }else{

 printf("\nError al leer el fichero.\n");

 }

 //-------------------------------------------------------------------------------------------------------------






//MUESTRA LO QUE HAY ESCRITO EN EL FICHERO ---------------------------------------------------------------------
mostrar = fgetc(fichero);

printf("\nContenido del fichero:\n",fichero);
printf("--------------------------------------------------------------------\n");

    while (mostrar != EOF)
    {
        printf("%c", mostrar);
        mostrar = fgetc(fichero);
    }

    fclose(fichero);

printf("\n--------------------------------------------------------------------\n");

//-------------------------------------------------------------------------------------------------------------




 break;









//-------------------------------------------------------------------------------------------------------------
//CERRAR EL CODIGO

 case 0:

 printf("\nSaliendo...\n");
 return 0;

 break;
//-------------------------------------------------------------------------------------------------------------





}




}

//-------------------------------------------------------------------------------------------------------------------------------------
printf("\n\n\nHola, espero que te haya ayudado este codigo, si quieres la parte 2 de ficheros, escribe a enriquebraquehaisdelara@gmail.com o mira mi Github EnriqueBDL");
printf("\nEste documento es de uso pribado, por lo que si se comparte sin permiso, sera denunciado.\n\n");
//-------------------------------------------------------------------------------------------------------------------------------------


return 0;
}
