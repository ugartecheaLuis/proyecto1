#include <stdio.h>
#include "Cola.h"
#include "Pila.h"
#include "Calcular.h"

vValor pertenece (cola *c1,char op){
    vValor r;
    nodo *temp=c1->head;
    for(int i=0; i < c1->len; i++){
        if(temp->op == op){
            r.b=1;
            r.valor=temp->valor;
            return r;
        }
        temp= temp->sig;
    }
    r.b=0;
    r.valor=-1;
    return r;
}

void ordenar (cola *c1, cola *c){
    pila *p = pila_vacia();
    nodo *temp;
    while (es_vacia(c1) == 0){
        if (97 <= c1->head->op && c1->head->op <=122){
            encolar (c, c1->head->op, c1->head->valor);
            desencolar (c1);
        }else{
            if (is_empty(p) == 1){
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
}

float calcular (cola *c){
    pila *p = pila_vacia ();
    float x, y, r;
    while (es_vacia(c) == 0){
        if (97 <= c->head->op && c->head->op <= 122){
            push (p, c->head->op, c->head->valor);
            desencolar (c);
        }else{
            y = p->head->valor;
            pop (p);
            x = p->head->valor;
            pop (p);
            switch (c->head->op){
            case '^':
                for(int i = 0;i < y; i++){
                    r *= x;
                }
                break;
            case '+':
                r = x + y;
                break;
            case '-':
                r = x - y;
                break;
            case '*':
                r = x * y;
                break;
            case '/':
                r = x/y;
                break;
            }
            desencolar (c);
            push (p, 'r', r);
        }
    }
    r = p->head->valor;
    return r;
}