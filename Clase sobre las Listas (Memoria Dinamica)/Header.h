#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//--------------------------------------------------------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Menu();

//][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][

struct Lista{

    char **nombres;
    int longitud;
};


//][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][

void establecer_lista(struct Lista *listas);
void insertar_nombre( struct Lista *listas);
void eliminar_nombre(struct Lista *listas);
void imprimir_lista(struct Lista *listas);

//--------------------------------------------------------------------------------------------------|
#endif // HEADER_H_INCLUDED
