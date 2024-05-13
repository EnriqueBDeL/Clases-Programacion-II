#include "Header.h"

int main()
{

    Pila pila;
    int opcion, anio;
    float precio;
    char modelo[50];
    int i;

for(;;){

opcion = Menu();


switch (opcion){
  case 1: pila = pila_crear();
                    break;

            case 2: if(pila_longitud(pila) == 0){
                          printf("\n\nLa pila esta vacia");
                    }else{
                          printf("\n\nLa pila no esta vacia");
                    }
                    break;

            case 3:  if(pila_longitud(pila) != 0){
              struct moto *tope = pila_localizar(pila, pila_longitud(pila));
              printf("\nEl tope de la pila es: Modelo: %s, Ano: %d, Precio: %.2f", tope->modelo, tope->anio, tope->precio);
            }else{
              printf("\n\nLa pila esta vacia");
            }
            break;

            case 4: printf("\nIntroduce modelo: ");
                    scanf("%s", modelo);
                    printf("\nIntroduce ano: ");
                    scanf("%d", &anio);
                    printf("\nIntroduce precio: ");
                    scanf("%f", &precio);
                    pila_insertar(pila, pila_ultimo(pila), modelo, anio, precio);
                    break;

            case 5: if(pila_longitud(pila) != 0){
                          pila_borrar(pila, pila_ultimo(pila));
                    }else{
                          printf("\n\nLa pila esta vacia");
                    }
                    break;

            case 6: if(pila != NULL){
                        for(i = 1; i <= pila_longitud(pila); i++){
                                struct moto *actual = pila_localizar(pila, i);
                                printf("Modelo: %s, Ano: %d, Precio: %.2f\n", actual->modelo, actual->anio, actual->precio);
                        }
                    }else{
                          printf("\n\nLa pila esta vacia");
                    }
                    break;

            case 7:
                printf("Presiona enter para salir...");
                return 0;
                break;
        }
    }
}
