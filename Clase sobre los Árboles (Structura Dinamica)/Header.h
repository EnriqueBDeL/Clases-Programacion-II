#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Coches {
    char *marca;
    char *modelo;
    int ano;
} COCHE;


// Redefinir el nodo del árbol para trabajar con coches
typedef struct nodo_arbol {
    COCHE coche;                     // Campo donde almacenaremos el coche
    struct nodo_arbol *izq;    // Puntero al hijo izquierdo
    struct nodo_arbol *der;    // Puntero al hijo derecho
} NODO_ARBOL, *P_NODO_ARBOL;


int menu();



P_NODO_ARBOL crearArbol();
int esVacio(P_NODO_ARBOL a);
P_NODO_ARBOL alojar_nodo_arbol();
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, COCHE coche);
P_NODO_ARBOL encontrar(P_NODO_ARBOL arbol, char *marca);
P_NODO_ARBOL padre_de(P_NODO_ARBOL arbol, P_NODO_ARBOL nodo);
P_NODO_ARBOL eliminar(P_NODO_ARBOL arbol, char *marca);
void preOrder(P_NODO_ARBOL a);
void postOrder(P_NODO_ARBOL a);
void inOrder(P_NODO_ARBOL a);



#endif // HEADER_H_INCLUDED
