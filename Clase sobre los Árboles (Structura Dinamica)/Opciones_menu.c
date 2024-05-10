#include "Header.h"
// Crea un arbol vacio
P_NODO_ARBOL crearArbol() {
    return NULL;
}

// Devuelve 1 si el arbol esta vacio
int esVacio(P_NODO_ARBOL a) {
    return (a == NULL);
}

// Reserva memoria para un nuevo nodo
P_NODO_ARBOL alojar_nodo_arbol() {
    return (P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL));
}

// Inserta un coche en el árbol binario
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, COCHE coche) {
    P_NODO_ARBOL p;

    if (arbol == NULL) {
        p = alojar_nodo_arbol();             // Reservamos memoria
        p->izq = p->der = NULL;             // Acabamos de crearlo
        p->coche.marca = strdup(coche.marca);
        p->coche.modelo = strdup(coche.modelo);
        p->coche.ano = coche.ano;
        return p;
    }

    if (strcmp(arbol->coche.marca, coche.marca) == 0)  // El coche ya existe
        return arbol;

    if (strcmp(arbol->coche.marca, coche.marca) > 0) // Insertar a la izquierda
        arbol->izq = insertar(arbol->izq, coche);
    else  // Insertar a la derecha
        arbol->der = insertar(arbol->der, coche);

    return arbol;
}

// Busca un coche por su marca
P_NODO_ARBOL encontrar(P_NODO_ARBOL arbol, char *marca) {
    if (arbol == NULL)    // Arbol vacio
        return NULL;

    if (strcmp(arbol->coche.marca, marca) == 0)  // Coche encontrado
        return arbol;
    else if (strcmp(arbol->coche.marca, marca) > 0)  // Buscar a la izquierda
        return encontrar(arbol->izq, marca);
    else    // Buscar a la derecha
        return encontrar(arbol->der, marca);
}

// Devuelve el padre de un nodo
P_NODO_ARBOL padre_de(P_NODO_ARBOL arbol, P_NODO_ARBOL nodo) {
    if (arbol == NULL)    // Arbol vacio
        return NULL;

    if (arbol->izq == nodo || arbol->der == nodo)  // Nodo encontrado
        return arbol;
    else if (strcmp(arbol->coche.marca, nodo->coche.marca) > 0)  // Buscar a la izquierda
        return padre_de(arbol->izq, nodo);
    else    // Buscar a la derecha
        return padre_de(arbol->der, nodo);
}

// Elimina un nodo del arbol
P_NODO_ARBOL eliminar(P_NODO_ARBOL arbol, char *marca) {
    P_NODO_ARBOL q, p;

    if (arbol == NULL)
        return NULL;

    if (strcmp(arbol->coche.marca, marca) > 0)  // Buscar a la izquierda
        arbol->izq = eliminar(arbol->izq, marca);
    else if (strcmp(arbol->coche.marca, marca) < 0)  // Buscar a la derecha
        arbol->der = eliminar(arbol->der, marca);
    else {
        if (arbol->izq == NULL && arbol->der == NULL) {  // Caso 1: sin hijos
            free(arbol->coche.marca);
            free(arbol->coche.modelo);
            free(arbol);
            return NULL;
        } else if (arbol->der == NULL) {  // Caso 2: un hijo
            q = arbol->izq;
            free(arbol->coche.marca);
            free(arbol->coche.modelo);
            free(arbol);
            return q;
        } else if (arbol->izq == NULL) {  // Caso 2: un hijo
            q = arbol->der;
            free(arbol->coche.marca);
            free(arbol->coche.modelo);
            free(arbol);
            return q;
        } else {  // Caso 3: dos hijos
            p = arbol;
            q = arbol->der;
            while (q->izq != NULL) {
                p = q;
                q = q->izq;
            }
            if (p != arbol)
                p->izq = q->der;
            else
                p->der = q->der;
            arbol->coche = q->coche;
            free(q->coche.marca);
            free(q->coche.modelo);
            free(q);
        }
    }
    return arbol;
}

// PreOrder traversal para listar coches
void preOrder(P_NODO_ARBOL a) {
    if (!esVacio(a)) {
        printf("Marca: %s | Modelo: %s | Ano: %d\n", a->coche.marca, a->coche.modelo, a->coche.ano);
        preOrder(a->izq);
        preOrder(a->der);
    }
}

// PostOrder traversal para listar coches
void postOrder(P_NODO_ARBOL a) {
    if (!esVacio(a)) {
        postOrder(a->izq);
        postOrder(a->der);
        printf("Marca: %s | Modelo: %s | Ano: %d\n", a->coche.marca, a->coche.modelo, a->coche.ano);
    }
}

// InOrder traversal para listar coches
void inOrder(P_NODO_ARBOL a) {
    if (!esVacio(a)) {
        inOrder(a->izq);
        printf("Marca: %s | Modelo: %s | Ano: %d\n", a->coche.marca, a->coche.modelo, a->coche.ano);
        inOrder(a->der);
    }
}
