#include "Header.h"

void establecer_lista(struct Lista *lista) {

    lista->nombres = NULL;
    lista->longitud = 0;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------|

void insertar_nombre(struct Lista *lista) {


    lista->longitud++;

    //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    lista->nombres = (char **)realloc(lista->nombres, lista->longitud * sizeof(char *));
    //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    if (lista->nombres == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    lista->nombres[lista->longitud - 1] = (char *)malloc(sizeof(char) * 100);               // Supongamos un máximo de 100 caracteres por nombre
    //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


    if (lista->nombres[lista->longitud - 1] == NULL) {

        printf("Error al asignar memoria.\n");
        return;
    }

    printf("\n\nIntroduce un nombre: "); scanf("%s", lista->nombres[lista->longitud - 1]);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------|

void eliminar_nombre(struct Lista *listas) {

    if (listas->longitud > 0) {

        int indice;

        printf("Ingrese el indice del nombre a eliminar (1-%d): ", listas->longitud); scanf("%d", &indice);

        if (indice >= 1 && indice <= listas->longitud) {

            free(listas->nombres[indice - 1]); // Liberar la memoria del nombre

            for (int i = indice - 1; i < listas->longitud - 1; i++) {

                listas->nombres[i] = listas->nombres[i + 1]; // Desplazar los nombres restantes
            }
            listas->longitud--;

            //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
            listas->nombres = (char **)realloc(listas->nombres, listas->longitud * sizeof(char *));
            //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

            if (listas->nombres == NULL && listas->longitud > 0) {

                printf("Error al liberar memoria.\n");
                return;
            }

            printf("Nombre eliminado correctamente.\n");
        } else {

            printf("Indice invalido. Intente nuevamente.\n");
        }

    } else {

        printf("La lista esta vacia. No hay nombres para eliminar.\n");
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------|

void imprimir_lista(struct Lista *listas){

    printf("Lista de nombres:\n");

    for (int i = 0; i < listas->longitud; i++) {

                    printf("%d: %s\n", i + 1, listas->nombres[i]);
    }
}
