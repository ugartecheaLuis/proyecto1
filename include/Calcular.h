#include <stdio.h>
#include <math.h>
#include "Cola.h"
#include "Pila.h"

struct _variableValor{
    int b;
    int valor;
};

typedef struct _variableValor vValor;

vValor pertenece (cola *c1,char op);
void ordenar (cola *c1, cola *c);
int calcular (cola *c);