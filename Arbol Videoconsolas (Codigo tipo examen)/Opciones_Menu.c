#include "Header.h"


P_NODO_ARBOL crearArbol() {
	return NULL;
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
int esVacio(P_NODO_ARBOL a) {
	return (a==NULL);
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
P_NODO_ARBOL alojar_nodo_arbol() {
    return((P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL)));
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
P_NODO_ARBOL borraNodo(P_NODO_ARBOL nodo){
	free(nodo);

    return NULL;
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, VCONSOLA vconsola) {
    P_NODO_ARBOL p;

    if (arbol == NULL)
    {
        p = alojar_nodo_arbol();
        p->izq = p->der = NULL;
        p->vconsola.empresa = strdup(vconsola.empresa);
        p->vconsola.modelo = strdup(vconsola.modelo);
        p->vconsola.ano = vconsola.ano;
        p->vconsola.precio = vconsola.precio;
        return (p);
    }

    if (strcmp(arbol->vconsola.empresa, vconsola.empresa) == 0)

        return (arbol);

    if (strcmp(arbol->vconsola.empresa, vconsola.empresa) > 0)

        arbol->izq = insertar(arbol->izq, vconsola);
    else
        arbol->der = insertar(arbol->der, vconsola);

    return (arbol);
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, char *modelo){

    if (arbol == NULL)
        return (NULL);

    if (strcmp(arbol->vconsola.modelo, modelo) == 0)
        return (arbol);

    else if (strcmp(arbol->vconsola.modelo, modelo) > 0)

        return(encontrar(arbol->izq, modelo));

    else

        return(encontrar(arbol->der, modelo));
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
P_NODO_ARBOL padre_de(P_NODO_ARBOL arbol, P_NODO_ARBOL nodo) {

    if (arbol == NULL)
        return (NULL);

    if (arbol->izq == nodo || arbol->der == nodo)

        return (arbol);

    else if (strcmp(arbol->vconsola.modelo, nodo->vconsola.modelo) > 0)

        return(padre_de(arbol->izq, nodo));

    else

        return(padre_de(arbol->der, nodo));
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
P_NODO_ARBOL eliminar(P_NODO_ARBOL a, char *modelo){

    P_NODO_ARBOL q,p;

    if (a == NULL) return a;

    if (strcmp(a->vconsola.modelo, modelo) > 0) a->izq = eliminar(a->izq, modelo);

    else if (strcmp(a->vconsola.modelo, modelo) < 0) a-> der = eliminar (a->der, modelo);

    else{

        if ((a->der == NULL)&&(a->izq == NULL)) //caso 1
            return borraNodo(a);

        //Caso 2
        if (a->der == NULL){
            q = a->izq;
            borraNodo (a);
            return q;
        }
        if (a->izq == NULL){
            q = a->der;
            borraNodo (a);
            return q;
        }

        //Caso 3
        for(p=a,q=a->izq; q->der != NULL; q = q->der)
            p=q;
        if (p!=a)
            p-> der = q->izq;
        else
            p->izq =q->izq;
        a->vconsola =q->vconsola;
        borraNodo(q);
    }
    return a;
}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void preOrder(P_NODO_ARBOL a)//Posterior
{
	if (!esVacio(a))
	{
		preOrder(a->izq);
		preOrder(a->der);


        printf("\n%s | %s | %d | %f", a->vconsola.empresa,a->vconsola.modelo,a->vconsola.ano,a->vconsola.precio);
    }

}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void postOrder(P_NODO_ARBOL a)//Previo
{
	if (!esVacio(a))
	{

        printf("\n%s | %s | %d | %f", a->vconsola.empresa,a->vconsola.modelo,a->vconsola.ano,a->vconsola.precio);		postOrder(a->izq);

		postOrder(a->der);
	}

}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void inOrder(P_NODO_ARBOL a)//Simetrico
{
	if (!esVacio(a))
	{
  		inOrder(a->izq);

        printf("\n%s | %s | %d | %f", a->vconsola.empresa,a->vconsola.modelo,a->vconsola.ano,a->vconsola.precio);  		inOrder(a->der);
	}
}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


