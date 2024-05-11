#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//----------------------------------------------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct vconsola{

    char *empresa;
    char *modelo;
    int ano;
    float precio;

}VCONSOLA;


typedef struct nodo_arbol
{
    VCONSOLA vconsola;

    struct nodo_arbol *izq;
    struct nodo_arbol *der;

}NODO_ARBOL, *P_NODO_ARBOL;


//------------------------------------------------|
int Menu();
//------------------------------------------------|
P_NODO_ARBOL crearArbol();
//------------------------------------------------|
int esVacio(P_NODO_ARBOL a);
//------------------------------------------------------------|
P_NODO_ARBOL borraNodo(P_NODO_ARBOL nodo);
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, VCONSOLA vconsola);
P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, char *modelo);
P_NODO_ARBOL padre_de(P_NODO_ARBOL arbol, P_NODO_ARBOL nodo);
P_NODO_ARBOL eliminar(P_NODO_ARBOL a, char *modelo);
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""|
void preOrder(P_NODO_ARBOL a);
void postOrder(P_NODO_ARBOL a);
void inOrder(P_NODO_ARBOL a);
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""|

//----------------------------------------------------------------------------------------|
#endif // HEADER_H_INCLUDED
