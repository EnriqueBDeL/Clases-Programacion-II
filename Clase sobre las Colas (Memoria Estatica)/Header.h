#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//---------------------------------------------------------------------------------|
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMS 100

typedef struct Avion {
    char id[20];
    char modelo[50];
    int anno_creacion;
    float precio;
} Avion;

typedef struct Cola {
    int cabeza, cola;
    Avion valores[MAX_ELEMS];
} *tipo_cola;


int Menu();

tipo_cola crear(tipo_cola c);
int suma_uno(int i);
Avion primero(tipo_cola c);
void apilar(tipo_cola c, Avion avion);
void suprime(tipo_cola c);




//---------------------------------------------------------------------------------|
#endif // HEADER_H_INCLUDED
