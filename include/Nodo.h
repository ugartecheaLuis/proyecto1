#ifndef __NODO_H__ 
#define __NODO_H__

typedef struct _nodo nodo;

struct _nodo{
    char op;
    int valor;
    nodo *sig;
};

nodo* crear_nodo (char, int);
void borrar_nodo (nodo *);

#endif