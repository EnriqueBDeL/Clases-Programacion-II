#include "Header.h"

struct moto* pila_crear(void)
{
    struct moto *paux; /* Crea el nodo cabecera*/
    paux = (struct moto *) (malloc(sizeof (struct moto)));
    if  (paux  != NULL) {
         paux->psig = NULL;
    }
    return (paux);
}

struct moto* pila_insertar(struct moto *pila, struct moto *pindice, char modelo[], int anio, float precio)
{
    struct moto *paux;

    paux = (struct moto *) malloc(sizeof (struct moto));
    strcpy(paux->modelo, modelo);
    paux->anio = anio;
    paux->precio = precio;
    paux->psig = pindice->psig;
    pindice->psig = paux;

    return (pila->psig);
}

struct moto* pila_primero(struct moto *pila)
{
    return (pila);   /* Devuelve un puntero al nodo cabecera*/
}

struct moto* pila_ultimo(struct moto *pila)
{
    struct moto *paux;    /*El último elemento de la pila es NULL.*/
    paux = pila;
    while (paux->psig != NULL)
        paux = paux->psig;
    return (paux);
}

struct moto* pila_siguiente(struct moto *pila, struct moto *pindice)
{
    return (pindice->psig);
}

int pila_longitud(struct moto *pila)
{
    int contador;
    struct moto *paux;
    paux = pila;
    contador = 0;
    while (paux->psig != NULL) {
        contador++;
        paux = paux->psig;
    }
    return (contador);
}

struct moto* pila_localizar(struct moto *pila, const int posicion)
{
    struct moto* paux;
    int c;
    paux = pila;
    c = posicion;
    while ( (c > 0) && (paux->psig != NULL) ) {
        paux = paux->psig;
        c--;
    }
    if(c != 0 ) paux = NULL;
    return (paux);
}

void pila_borrar(struct moto *pila, struct moto *pindice)
{
    struct moto *paux;
    paux = pila_localizar(pila, pila_longitud(pila) - 1);
    paux->psig = pindice->psig;
    free(pindice);
}

void pila_destruir(struct moto *pila)
{
    struct moto *pborra;
    struct moto *paux;
    paux = pila;
    while (paux != NULL) {
        pborra = paux;
        paux = paux->psig;
        free (pborra);
    }
}
