#include "Header.h"


tipo_cola crear(tipo_cola c) {
    c = (tipo_cola)malloc(sizeof(struct Cola));
    c->cabeza = 0;
    c->cola = 0;
    c->capacidad = 1; // Capacidad inicial
    c->valores = (Avion *)malloc(c->capacidad * sizeof(Avion));
    return c;
}

int suma_uno(tipo_cola c, int i) {
    return ((i + 1) % c->capacidad);
}

Avion primero(tipo_cola c) {
    return (c->valores[c->cabeza]);
}

void apilar(tipo_cola c, Avion avion) {
    if (suma_uno(c, c->cola) == c->cabeza) {
        // La cola está llena, se necesita expandir
        c->capacidad *= 2;
        c->valores = (Avion *)realloc(c->valores, c->capacidad * sizeof(Avion));
    }
    c->valores[c->cola] = avion;
    c->cola = suma_uno(c, c->cola);
}

void suprime(tipo_cola c) {
    if (c->cabeza == c->cola) {
        printf("Error: cola vacia\n");
        return;
    }
    c->cabeza = suma_uno(c, c->cabeza);
    // Si la cantidad de elementos es 1/4 de la capacidad, reducir la capacidad a la mitad
    if ((c->capacidad > 1) && ((c->cola - c->cabeza + c->capacidad) % c->capacidad) <= c->capacidad / 4) {
        c->capacidad /= 2;
        c->valores = (Avion *)realloc(c->valores, c->capacidad * sizeof(Avion));
    }
}
