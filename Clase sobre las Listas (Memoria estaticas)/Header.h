#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//---------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//.......................
#define MAX_ELEMENTOS 100
//.......................


int Menu();

//][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][

struct Lista{

    int elementos[MAX_ELEMENTOS];
    int longitud;

};

//][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][

void inicializarLista(struct Lista *lista);
void insertar(struct Lista *lista, int valor) ;
void imprimirLista(struct Lista *lista);


//-----------------------------------------------------|
#endif // HEADER_H_INCLUDED
