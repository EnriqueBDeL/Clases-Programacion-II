#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//---------------------------------------------------------------------------------|
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Avion {
    char *id;
    char *modelo;
    int anno_creacion;
    float precio;
} Avion;

typedef struct Cola {
    int cabeza, cola;
    int capacidad;
    Avion *valores;
} *tipo_cola;


int Menu();
tipo_cola crear(tipo_cola c);
int suma_uno(tipo_cola c, int i);
Avion primero(tipo_cola c);
void apilar(tipo_cola c, Avion avion);
void suprime(tipo_cola c);
void liberar_cola(tipo_cola c);




//---------------------------------------------------------------------------------|
#endif // HEADER_H_INCLUDED
