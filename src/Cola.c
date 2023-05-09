#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nodo.h"
#include <stdbool.h>

cola* cola_vacia(){
    cola *c;
    c = (cola *)malloc(sizeof(cola));
    c->len=0;
    c->head = c->tail = NULL; 
    return c;
}

bool es_vacia(cola *c){
    bool b;
    if(c->len==0){
        return true;
    }else{
        return false;
    }
}

void borrar_cola(cola *c){
    if(c->len == 0){
        free(c);
        c = NULL;
    }
}

void encolar (cola *c, char op, float valor){
    nodo *nuevo;
    nuevo = crear_nodo (op, valor);
    if (c->len == 0){
        c->head = c->tail = nuevo;
        c->len++;
    }else{
        c->tail->sig = nuevo;
        c->tail = c->tail->sig;
        c->len++;
    }
}

void desencolar(cola *c){
    nodo *temp;
    if(c->len >0){
        temp = c->head;
        c->head = c->head->sig;
        temp->sig=NULL;
        borrar_nodo(temp);
        c->len--;
    }
}

void imprimir(cola *c){
    nodo *temp;
    temp = c->head;
    printf ("[ ");
    for(int i=0; i < c->len; i++){
        printf("%c ", temp->op);
        temp= temp->sig;
    }
    printf ("]\n");
}
