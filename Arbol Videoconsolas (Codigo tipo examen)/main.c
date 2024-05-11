#include "Header.h"

int main (){

    int opcion,orden_opc;
    char palabra[100];

    P_NODO_ARBOL a = crearArbol();

    VCONSOLA vconsola;

for(;;){

    opcion = Menu();

   switch(opcion){

   case 1:

        printf("\nIntroduce el nombre de la empresa: "); scanf("%s", palabra);
        vconsola.empresa = strdup(palabra);

        printf("Introduce el nombre modelo: ");scanf("%s", palabra);
        vconsola.modelo = strdup(palabra);

        printf("Introduce el ano de salida: ");scanf("%d", &vconsola.ano);
        printf("Introduce el precio: ");scanf("%f", &vconsola.precio);
        a = insertar(a, vconsola);

        printf("\nConsola ingresada.");
       break;


   case 2:

    printf("\nIntroduce el modelo de la consola a eliminar: "); scanf("%s", palabra);
    a = eliminar(a, palabra);
    printf("Consola eliminado.\n");

    break;


   case 3:

        printf("\n1.Orden previo\n");
        printf("2.Orden simetrico\n");
        printf("3.Orden posterior\n");
        printf("\nIntroduce una opcion: "); scanf("%d",&orden_opc);


         switch (orden_opc)
            {
            case 1:
                preOrder(a);
                break;

            case 2:
                inOrder(a);
                break;

            case 3:
                postOrder(a);
                break;
            }
    break;

    case 4:

    printf("Presione enter para salir....");
    return 0;

    break;

        }
    }
}
