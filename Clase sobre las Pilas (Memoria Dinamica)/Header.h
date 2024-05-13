#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//-------------------------------------------------------------------------------|
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct moto {
    char *modelo;
    int anio;
    float precio;
    struct moto *psig;
};

typedef struct moto *Pila;
typedef struct moto *Posicion;

int Menu();

struct moto* pila_crear(void);
struct moto* pila_insertar(struct moto *pila, struct moto *pindice, char *modelo, int anio, float precio);
struct moto* pila_primero(struct moto *pila);
struct moto* pila_ultimo(struct moto *pila);
struct moto* pila_siguiente(struct moto *pila, struct moto *pindice);
int pila_longitud(struct moto *pila);
struct moto* pila_localizar(struct moto *pila, const int posicion);
void pila_borrar(struct moto *pila, struct moto *pindice);
void pila_destruir(struct moto *pila);

//-------------------------------------------------------------------------------|
#endif // HEADER_H_INCLUDED
