#include "Header.h"


int main() {

    int opciones;

    struct Lista listas;

    establecer_lista(&listas);

for (;;) {

    opciones = Menu();

switch (opciones) {

//------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                               INSERTAR NOMBRE
//------------------------------------------------------------------------------------------------------------------------------------------------------
case 1:

 insertar_nombre(&listas);

break;

//------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                               ELIMINAR NOMBRE
//------------------------------------------------------------------------------------------------------------------------------------------------------
case 2:

    eliminar_nombre(&listas);

break;
//------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                               IMPRIMIR LISTA
//------------------------------------------------------------------------------------------------------------------------------------------------------
case 3:

 imprimir_lista(&listas);

break;
//------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                    SALIR
//------------------------------------------------------------------------------------------------------------------------------------------------------
case 4:

    printf("Saliendo del programa.\n");

        for (int i = 0; i < listas.longitud; i++) {
            free(listas.nombres[i]);
        }
            free(listas.nombres);

        return 0;

break;

default:

        printf("Opcion invalida. Intente de nuevo.\n");

        }
    }
}
