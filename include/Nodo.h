#ifndef __NODO_H__ 
#define __NODO_H__

typedef struct _nodo nodo;

struct _nodo{
    char op;
    float valor;
    nodo *sig;
};

nodo* crear_nodo (char, float);
void borrar_nodo (nodo *);

#endif