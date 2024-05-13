#include "Header.h"


tipo_cola crear(tipo_cola c){
    c = (tipo_cola) malloc(sizeof(struct Cola));
    c->cabeza = 0;
    c->cola = 0;
    return c;
}
//------------------------------------------------------------------|
int suma_uno(int i){
    return ((i + 1) % MAX_ELEMS);
}
//------------------------------------------------------------------|
Avion primero(tipo_cola c){
    return (c->valores[c->cabeza]);
}
//------------------------------------------------------------------|
void apilar(tipo_cola c, Avion avion){
    if (suma_uno(c->cola) == c->cabeza){
        printf("Error: cola llena \n");
    }else{
        c->valores[c->cola] = avion;
        c->cola = suma_uno(c->cola);
    }
}
//------------------------------------------------------------------|
void suprime(tipo_cola c){
    if(c->cabeza == c->cola){
        printf("Error: cola vacia\n");
    }else{
        c->cabeza = suma_uno(c->cabeza);
    }
}
