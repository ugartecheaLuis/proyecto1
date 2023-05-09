#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"

nodo *crear_nodo (char op, float valor){
    nodo *n;
    n = (nodo *)malloc(sizeof(nodo));
    n->op = op;
    n->valor = valor;
    n->sig= NULL;
    return n;
}

void borrar_nodo(nodo *n){
    if(n->sig == NULL){
        free(n);
        n = NULL;
    }
}