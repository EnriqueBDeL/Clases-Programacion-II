#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//--------------------------------------------------------------------------
struct GPU{
char *identificador;
char *modelo;
char *nombre_marca;
int ano_lanzamiento;
};
//--------------------------------------------------------------------------
int Menu(){
int opciones;
printf("\n\n****MENU****:");
printf("\n1.Insertar nueva GPU.");
printf("\n2.Borrar una GPU.");
printf("\n3.Mostar todas las GPUs.");
printf("\n4.Salir.");
return opciones;
}
//--------------------------------------------------------------------------
int main()
{
//||||||||||||||||||||||||||||
    FILE *fichero;
//----------------------------
    int opciones;
    int numero_gpus = 0;
//----------------------------
    char nombre_fichero[100];
    char id_eliminar[50];
//----------------------------
    struct GPU *gpu = NULL;
//||||||||||||||||||||||||||||
    for(;;){

        Menu();
    printf("\nIntroduce una opcion: "); scanf("%d",&opciones);

    switch(opciones){
//------------------------------------------------------------------------------------------------
//                                  INSERTAR NUEVA GPU
//------------------------------------------------------------------------------------------------
    case 1:

        printf("\nIntroduce el nombre del archivo: "); fflush(stdin); gets(nombre_fichero);

        fichero = fopen(nombre_fichero,"r");

        numero_gpus++;

        //--||----||----||----||----||----||----||----||----||----||----||----||--
            gpu = (struct GPU*)realloc(gpu, numero_gpus * sizeof(struct GPU));
        //--||----||----||----||----||----||----||----||----||----||----||----||--

        //--||----||----||----||----||----||----||----||----||----||----||----||--
            gpu[numero_gpus-1].identificador = (char*)malloc(50 * sizeof(char));
        //--||----||----||----||----||----||----||----||----||----||----||----||--

        //--||----||----||----||----||----||----||----||----||----||----||----||--
            gpu[numero_gpus - 1].modelo = (char *)malloc(50 * sizeof(char));
        //--||----||----||----||----||----||----||----||----||----||----||----||--

        //--||----||----||----||----||----||----||----||----||----||----||----||--
            gpu[numero_gpus - 1].nombre_marca = (char *)malloc(50 * sizeof(char));
        //--||----||----||----||----||----||----||----||----||----||----||----||--


        fscanf(fichero, "%s %s %s %d",gpu[numero_gpus - 1].identificador,gpu[numero_gpus - 1].modelo, gpu[numero_gpus - 1].nombre_marca,&gpu[numero_gpus - 1].ano_lanzamiento);

        fclose(fichero);

        printf("GPU insertada correctamente.\n");

        break;
//------------------------------------------------------------------------------------------------
//                                  BORRAR UNA GPU
//------------------------------------------------------------------------------------------------
case 2:
    printf("\nIntroduce el nombre del archivo que contiene el ID a eliminar: ");
    fflush(stdin);
    gets(nombre_fichero);

    fichero = fopen(nombre_fichero, "r");
    if (fichero == NULL) {
        printf("\nNo se pudo abrir el archivo.\n");
        break;
    }

    // Leer el ID del archivo
    fscanf(fichero, "%s", id_eliminar);
    fclose(fichero);

    // Buscar la GPU con el ID especificado y eliminarla si se encuentra
    int encontrado = 0;
    for (int i = 0; i < numero_gpus; i++) {
        if (strcmp(gpu[i].identificador, id_eliminar) == 0) {
            encontrado = 1;
            // Eliminar la GPU encontrada moviendo las demás hacia arriba en el arreglo
            for (int j = i; j < numero_gpus - 1; j++) {
                strcpy(gpu[j].identificador, gpu[j + 1].identificador);
                strcpy(gpu[j].modelo, gpu[j + 1].modelo);
                strcpy(gpu[j].nombre_marca, gpu[j + 1].nombre_marca);
                gpu[j].ano_lanzamiento = gpu[j + 1].ano_lanzamiento;
            }
            // Reducimos el contador de GPUs
            numero_gpus--;
            // Redimensionamos el arreglo de GPUs
            gpu = realloc(gpu, numero_gpus * sizeof(struct GPU));
            printf("\nGPU con ID %s eliminada correctamente.\n", id_eliminar);
            break; // Salimos del bucle después de eliminar la primera ocurrencia
        }
    }

    if (!encontrado)
        printf("\nNo se encontró ninguna GPU con el ID %s especificado.\n", id_eliminar);

    break;
//------------------------------------------------------------------------------------------------
//                                  MOSTRAR TODAS LAS GPUs
//------------------------------------------------------------------------------------------------
    case 3:

        printf("\nLista de GPUs:");

        for(int j = 0; j<numero_gpus; j++){

        printf("\n\n\tID: %s",gpu[j].identificador);
        printf("\n\tModelo: %s",gpu[j].modelo);
        printf("\n\tMarca: %s",gpu[j].nombre_marca);
        printf("\n\tAno de lanzamiento: %d",gpu[j].ano_lanzamiento);

        }
        break;
//------------------------------------------------------------------------------------------------
    case 4:
        printf("\n\nPresiona enter para salir...");
        free(gpu);
        return 0;
        break;
        }//end switch
    }//end for
}//end main
