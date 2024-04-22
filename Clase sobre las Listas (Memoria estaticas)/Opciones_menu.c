#include "Header.h"

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
El operador "->" en C simplifica el acceso a los miembros de una estructura o unión a través de un puntero a esa estructura o unión.
Es especialmente útil cuando trabajamos con estructuras a través de punteros, evitando la necesidad de usar la notación de desreferenciación (*) junto con la notación de punto (.).
La sintaxis "lista->longitud" es más legible y se usa comúnmente en programas que hacen un uso intensivo de punteros a estructuras.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
*/

// Función para inicializar la lista
void inicializarLista(struct Lista *lista) {

    lista->longitud = 0;

}

//----------------------------------------------------------------------------------------------

// Función para insertar un elemento al final de la lista
void insertar(struct Lista *lista, int valor) {

    if (lista->longitud < MAX_ELEMENTOS) {

        lista->elementos[lista->longitud] = valor;
        lista->longitud++;

        printf("Elemento insertado correctamente.\n");

    } else {

        printf("Error: La lista está llena, no se puede insertar más elementos.\n");

    }
}

//----------------------------------------------------------------------------------------------

// Función para imprimir todos los elementos de la lista
void imprimirLista(struct Lista *lista) {

    printf("Lista: ");

    for (int i = 0; i < lista->longitud; i++) {

        printf("%d -> ", lista->elementos[i]);

    }
    printf("NULL\n");
}
