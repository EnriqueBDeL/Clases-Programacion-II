#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE_MODELO 40


//-------------------------------------------------------------------
//                           FICHEROS PARTE 4
//-------------------------------------------------------------------


/* Este codigo sirve para introducir los difrentes modelos de bugatti y los
almacena en un struct con varios campos */



//En el fichero debe estar lo mismo que en el struct.

/*

Nombre de modelo
Numero de modelos

*/

struct Bugatti{

char nombre_modelo[MAX_NOMBRE_MODELO];
int  numero_de_modelos;

};





//--------------------------------------------------------------
int Menu(){

int opciones;

printf("\n\n****MENU****");
printf("\n1. Introduce un modelo.");
printf("\n2. Mostrar modelos agregados.");


return opciones;
}
//--------------------------------------------------------------





int main()
{

    FILE *Fichero;

    char nombre_del_fichero[80]; //Recuera simepre ponerle un tamaño nombre_del_fichero [Tamaño]

    struct Bugatti b[4];

    int i = 0;

    int opciones;


//-------------------------------------------------------------------------------------------------------------------------------
for(;;){

   Menu();
   printf("\n\nItroduce una opcion: "); scanf("%d",&opciones);


switch(opciones){



case 1:



if(i<5){


    printf("\n\nIntroduce el nombre del archivo (Ejemplo: fichero.txt): "); fflush(stdin); gets(nombre_del_fichero);

    Fichero = fopen(nombre_del_fichero,"r");





    if(Fichero == NULL){

        printf("\ERRO:Arhivo no econtrado");


    }else{

    printf("\nArhivo econtrado");



//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    fgets(b[i].nombre_modelo,MAX_NOMBRE_MODELO,Fichero); //Lee la primera fila y la mete en b.nombre_modelo


   b[i].nombre_modelo[strcspn(b[i].nombre_modelo, "\n")] = '\0'; //Esta sentencia sirve para eliminar el salto de linea del fuchero.txt
                                                            /*Lo que hace es: de "b.nombre_modelo" busca la posición de "\n" que
                                                            es el salto de linea. Ejem: Tenemos "b.nombre_modelo[40]" y con esto detecta
                                                            que el salto está en "b.nombre_modelo[13]".

                                                            Una vez detectado susitulle el "\n" por el caracter nulo '\0'.
                                                            */

    fscanf(Fichero,"%d",&b[i].numero_de_modelos);  //Lee la segunda fila y la mete en b.numero_de_modelos


    fclose(Fichero);
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||





    printf("\n\n------------------------");

    printf("\n%s",b[i].nombre_modelo);
    printf("\n%d",b[i].numero_de_modelos);

    printf("\n------------------------");

    i++;



  }
  }  else{

    printf("\nNo se pueden agregar más coches");

}







break;










case 2:


for(int j=0; j<i; j++){ //Bucle para mostrar todos los coches leidos

        printf("\n\n------------------------");

        printf("\n%s",b[j].nombre_modelo);
        printf("\n%d",b[j].numero_de_modelos);

        printf("\n------------------------");
    }

break;


case 3:

//-------------------------------------------------------------------------------------------------------------------------------------
printf("\n\n\nHola, espero que te haya ayudado este codigo, si quieres la parte 4 de ficheros, mira mi Github EnriqueBDL.");
printf("\n\nEste documento es de uso pribado, por lo que si se comparte sin permiso, sera denunciado.\n\n");
//-------------------------------------------------------------------------------------------------------------------------------------


printf("\nSaliendo...");
return 0;

    break;



}

}
    return 0;
}
