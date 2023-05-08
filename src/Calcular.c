#include <stdio.h>
#include <math.h>
#include "Cola.h"
#include "Pila.h"

cola* calcular (cola *c1){
    cola *c = cola_vacia();
    pila *p = pila_vacia();
    nodo *temp;

    while (es_vacia(c1) == 0){
        printf ("Cola: ");
        imprimir (c);
        printf ("Pila: ");
        printp (p);
        printf ("%c\n", c1->head->op);
        if (97 <= c1->head->op && c1->head->op <=122){
            encolar (c, c1->head->op, c1->head->valor);
            desencolar (c1);
        }else{
            if (is_empty(p)){
                if (c1->head->op == '('){
                    c1->head->valor = 0;
                }
                push (p, c1->head->op, c1->head->valor);
                desencolar (c1);
            }else{
                if(c1->head->op == ')'){
                    for (temp = p->head; temp->op != '('; temp = p->head){
                        encolar (c, p->head->op, p->head->valor);
                        pop (p);
                    }
                    pop (p);
                    desencolar (c1);
                }else{
                    if (c1->head->valor > p->head->valor){
                        if (c1->head->op == '('){
                            c1->head->valor = 0;
                        }
                        push (p, c1->head->op, c1->head->valor);
                        desencolar (c1);
                    }else{
                        encolar (c, p->head->op, p->head->valor);
                        pop (p);
                        push (p, c1->head->op, c1->head->valor);
                        desencolar (c1);
                    }
                }
            }
        }
    }
    while (is_empty(p) == 0){
        encolar (c, c1->head->op, c1->head->valor);
        pop (p);
    }
    return c;
}

