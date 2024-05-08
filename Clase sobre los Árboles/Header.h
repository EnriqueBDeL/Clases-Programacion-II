
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Coches {
    char marca[50];
    char modelo[50];
    int ano;
} COCHE;


// Redefinir el nodo del árbol para trabajar con coches
typedef struct nodo_arbol {
    COCHE coche;                     // Campo donde almacenaremos el coche
    struct nodo_arbol *izq;    // Puntero al hijo izquierdo
    struct nodo_arbol *der;    // Puntero al hijo derecho
} NODO_ARBOL, *P_NODO_ARBOL;


P_NODO_ARBOL crearArbol();
int esVacio(P_NODO_ARBOL a);
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, COCHE coche);
P_NODO_ARBOL encontrar(P_NODO_ARBOL arbol, int ano) ;
P_NODO_ARBOL eliminar(P_NODO_ARBOL arbol, int ano);
void inOrder(P_NODO_ARBOL a);
