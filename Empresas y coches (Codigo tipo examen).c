#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------------------------------------------------------------------------------------------------------------------------
struct Coche {
    char *c_nombre;
    float precio;
};
//------------------------------------------------------------------------------------------------------------------------------------
struct Empresa {
    char *e_nombre;
    int e_ano;
    struct Coche *coches;
    int num_coches;
};
//------------------------------------------------------------------------------------------------------------------------------------
int Menu() {
    int opciones;
    printf("\n\n****MENU****\n");
    printf("\n1. Anadir Empresa.");
    printf("\n2. Eliminar Empresa.");
    printf("\n3. Anadir Coche.");
    printf("\n4. Eliminar Coche.");
    printf("\n5. Mostrar datos guardados.");
    printf("\n6. Salir del programa.\n");
    return opciones;
}
//------------------------------------------------------------------------------------------------------------------------------------
int main() {


//]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[
    int opciones = 0;
    int numero_de_empresas = 0;
//]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[
    char empresa_eliminar[50];
    char empresa_coche[50];
    char empresa_eliminar_coche[50];
//]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[
    struct Empresa *empresas = NULL;
//]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[]||[


    for (;;) {

    Menu();
    printf("\nIntroduce una opcion: "); scanf("%d", &opciones);

        switch (opciones) {

//-----------------------------------------------------------------------------------------------------------------------------------
//                                                          AÑADIR EMPRESA
//-----------------------------------------------------------------------------------------------------------------------------------
            case 1:

                numero_de_empresas++;

                //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--
                empresas = (struct Empresa*)realloc(empresas, numero_de_empresas * sizeof(struct Empresa));
                //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--

                if (empresas == NULL) {
                    printf("Error al asignar memoria.");
                    return 1;
                }

                //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--
                empresas[numero_de_empresas-1].e_nombre = (char*)malloc(50 * sizeof(char));
                //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--


            if (empresas[numero_de_empresas-1].e_nombre == NULL) {
                    printf("Error al asignar memoria.");
                    return 1;
                }

                printf("\nIntroduce el nombre de la empresa: "); scanf("%s", empresas[numero_de_empresas-1].e_nombre);

                printf("\nIntroduce el ano de fundacion de la empresa: "); scanf("%d", &empresas[numero_de_empresas-1].e_ano);

                empresas[numero_de_empresas-1].num_coches = 0;
                empresas[numero_de_empresas-1].coches = NULL;

                break;

//-----------------------------------------------------------------------------------------------------------------------------------
//                                                          ELIMINAR EMPRESA
//-----------------------------------------------------------------------------------------------------------------------------------
               case 2:

                printf("Introduce el nombre de la empresa que deseas eliminar: "); scanf("%s", empresa_eliminar);

                for (int j = 0; j < numero_de_empresas; j++) {

                    if (strcmp(empresas[j].e_nombre, empresa_eliminar) == 0) {

                        for (int k = 0; k < empresas[j].num_coches; k++) {

                            free(empresas[j].coches[k].c_nombre);
                        }
                        free(empresas[j].coches);
                        free(empresas[j].e_nombre);

                        for (int k = j; k < numero_de_empresas - 1; k++) {
                            empresas[k] = empresas[k + 1];
                        }

                        //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--
                        empresas = (struct Empresa *)realloc(empresas, (numero_de_empresas - 1) * sizeof(struct Empresa));
                        //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--

                        numero_de_empresas--;

                        printf("\nEmpresa eliminada correctamente.");
                    }
                }
                break;

//-----------------------------------------------------------------------------------------------------------------------------------
//                                                          AÑADIR COCHE
//-----------------------------------------------------------------------------------------------------------------------------------
        case 3:



                printf("Introduce el nombre de la empresa a la que le deseas añadir un coche: "); scanf("%s", empresa_coche);

                for (int j = 0; j < numero_de_empresas; j++) {
                    if (strcmp(empresas[j].e_nombre, empresa_coche) == 0) {
                        empresas[j].num_coches++;

                        //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--
                        empresas[j].coches = (struct Coche*)realloc(empresas[j].coches, empresas[j].num_coches * sizeof(struct Coche));
                        //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--


                        if (empresas[j].coches == NULL) {
                            printf("Error al asignar memoria.");
                            return 1;
                        }

                        //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--
                        empresas[j].coches[empresas[j].num_coches-1].c_nombre = (char*)malloc(50 * sizeof(char));
                        //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--

                        if (empresas[j].coches[empresas[j].num_coches-1].c_nombre == NULL) {
                            printf("Error al asignar memoria.");
                            return 1;
                        }

                        printf("\nIntroduce el nombre del coche: "); scanf("%s", empresas[j].coches[empresas[j].num_coches-1].c_nombre);

                        printf("\nIntroduce el precio del coche: "); scanf("%f", &empresas[j].coches[empresas[j].num_coches-1].precio);
                        break;
                    }
                }
                break;

//-----------------------------------------------------------------------------------------------------------------------------------
//                                                          ELIMINAR COCHE
//-----------------------------------------------------------------------------------------------------------------------------------
               case 4:
                printf("Introduce el nombre de la empresa de la que deseas eliminar un coche: "); scanf("%s", empresa_eliminar_coche);

    for (int j = 0; j < numero_de_empresas; j++) {
        if (strcmp(empresas[j].e_nombre, empresa_eliminar_coche) == 0) {
            if (empresas[j].num_coches > 0) {
                printf("Introduce el nombre del coche que deseas eliminar: ");
                char coche_eliminar[50];
                scanf("%s", coche_eliminar);

                int indice_coche = -1;
                for (int k = 0; k < empresas[j].num_coches; k++) {
                    if (strcmp(empresas[j].coches[k].c_nombre, coche_eliminar) == 0) {
                        indice_coche = k;
                        break;
                    }
                }

                if (indice_coche != -1) {
                    free(empresas[j].coches[indice_coche].c_nombre);
                    for (int k = indice_coche; k < empresas[j].num_coches - 1; k++) {
                        empresas[j].coches[k] = empresas[j].coches[k + 1];
                    }
                    empresas[j].num_coches--;

                    //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--
                    empresas[j].coches = (struct Coche*)realloc(empresas[j].coches, empresas[j].num_coches * sizeof(struct Coche));
                    //--||----||----||----||----||----||----||----||----||----||----||----||----||----||----||--

                    printf("\nCoche eliminado correctamente.");
                } else {
                    printf("\nEl coche especificado no existe en esta empresa.");
                }
            } else {
                printf("\nLa empresa no tiene coches para eliminar.");
            }
            break;
        }
    }
                break;

//-----------------------------------------------------------------------------------------------------------------------------------
//                                                          LISTAR DATOS
//-----------------------------------------------------------------------------------------------------------------------------------
               case 5:
                for (int i = 0; i < numero_de_empresas; i++) {


                    printf("\nNombre: %s", empresas[i].e_nombre);
                    printf("\nFundacion: %d", empresas[i].e_ano);
                    printf("\nCoches:\n");

                    for (int k = 0; k < empresas[i].num_coches; k++) {

                        printf("\tNombre: %s, Precio: %.2f\n", empresas[i].coches[k].c_nombre, empresas[i].coches[k].precio);

                    }
                }
                break;
//-----------------------------------------------------------------------------------------------------------------------------------
//                                                          SALIR
//-----------------------------------------------------------------------------------------------------------------------------------
            case 6:
                free(empresas);
                return 0;
                break;
        }
    }
}
