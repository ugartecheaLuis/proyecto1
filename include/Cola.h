#ifndef __COLA_H__ 
#define __COLA_H__
#include "Nodo.h"
#include <stdbool.h>

struct _cola{
    nodo* head;
    nodo* tail;
    int len;
};

typedef struct _cola cola;

cola *cola_vacia ();
bool es_vacia (cola*);
void borrar_cola (cola*);
void encolar (cola *, char, float);
void desencolar (cola *);
int primero (cola *);
void imprimir (cola *);

#endif