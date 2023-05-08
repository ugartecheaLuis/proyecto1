#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

pila* pila_vacia (){
    pila *p;
    p = (pila *)malloc(sizeof(pila));
    p->len = 0;
    p->head = p->tail = NULL;
    return p;
}

bool is_empty (pila *p){
    bool b;
    if(p->len==0){
        return true;
    }else{
        return false;
    }
}

void borrar_pila (pila *p){
    if(p->len==0){
        free(p);
        p=NULL;
    }
}

void push (pila *p, char op, int valor){
    nodo *nuevo = crear_nodo (op, valor);
    if(p->len==0){
        p->head = p->tail = nuevo;
        p->len++;
    }else{
        nuevo->sig = p->head;
        p->head = nuevo;
        p->len++;
    }
}

void pop (pila *p){
    if(p->len > 0){
        nodo *temp = p->head;
        p->head = p->head->sig;
        temp->sig = NULL;
        borrar_nodo(temp);
        p->len--;
    }
}

int top (pila *p){
    if(p->len > 0){
        return p->head->valor;
    }else{
        printf("la pila esta vacia\n");
        return -1;
    }
}

void printp (pila *p){
    nodo *temp;
    temp = p->head;
    printf ("[ ");
    for(int i=0; i < p->len; i++){
        printf("%c ", temp->op);
        temp= temp->sig;
    }
    printf ("]\n");
}




