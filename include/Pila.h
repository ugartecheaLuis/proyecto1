#ifndef __PILA_H__
#define __PILA_H__ 
#include "Nodo.h"
#include <stdbool.h>

struct _pila{
    nodo* head;
    nodo* tail;
    int len;
};

typedef struct _pila pila;

pila* pila_vacia ();
bool is_empty (pila *);
void borrar_pila (pila *);
void push (pila *, char, float);
void pop (pila *);
void printp (pila *);
#endif