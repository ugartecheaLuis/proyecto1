#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"
//misma variable y espacios
int main(){
    cola *c1, *c;
    int valor;
    char op;
    bool b;
    nodo *temp;

    c1 = cola_vacia();

    printf ("Ingresa la ecuacion\n");
    char ec[100];
    setbuf(stdin, NULL);
    scanf("%100[^\n]", ec);
    getchar();
    printf ("%s\n", ec);
    for (int i = 0; i < strlen(ec); i++){
        switch (ec[i]){
        case '^':
            encolar (c1, ec[i], 3);
            break;
        case '+':
            encolar (c1, ec[i], 1);
            break;
        case '-':
            encolar (c1, ec[i], 1);
            break;
        case '*':
            encolar (c1, ec[i], 2);
            break;
        case '/':
            encolar (c1, ec[i], 2);
            break;
        case '(':
            encolar (c1, ec[i], 5);
            break;
        case ')':
            encolar (c1, ec[i], -1);
            break;
        case ' ':
            break;
        default:
            if ( 65 <= ec[i] && ec[i] <=90){
                ec[i] += 32;
            }
            if ( 97 <= ec[i] && ec[i] <=122){
                printf ("Cual es el valor de %c?\n", ec[i]);
                scanf ("%d", &valor);
                encolar (c1, ec[i], valor);
            }else{
                printf ("Caracter invalido");
            }
            break;
        }
    }
    imprimir (c1);

    c = calcular (c1);

    
    return 0;
}



    /*
    for (int i = c1->len; i > 0; i--){
        if (c1->head->op != '^' && c1->head->op != '+' && c1->head->op!='-' && c1->head->op!='*' && c1->head->op != '/' && c1->head->op != '(' && c1->head->op != ')'){
            encolar (c, c1->head->op, c1->head->valor);
            desencolar (c1);
        }else{
            if (es_vacia (c1) == true){
                if (is_empty(p) == true){
                    break;
                }else{
                    for (int i = p->len; i > 0; i--){
                        encolar (c, p->head->op, p->head->valor);
                        pop (p);
                    }
                }
            }else{
                if (c1->head->op == ')'){
                    for (temp = p->head; temp->op != '('; temp = temp->sig){
                        encolar (c, p->head->op, p->head->valor);
                        pop (p);
                    }
                    pop (p);
                }else{
                    if (is_empty (p) == true){
                        push (p, c1->head->op, c1->head->valor);
                        if (p->head->op == '('){
                            p->head->valor = 0;
                        }
                        if (p->head->op == '^'){
                            p->head->valor = 3;
                        }
                    }else{
                        if (c1->head->valor > p->head->valor){
                            push (p, c1->head->op, c1->head->valor);
                            if (p->head->op == '('){
                                p->head->valor = 0;
                            }
                            if (p->head->op == '^'){
                                p->head->valor = 3;
                            }
                        }else{
                            encolar (c, p->head->op, p->head->valor);
                            pop (p);
                            push (p, c1->head->op, c1->head->valor);
                            if (p->head->op == '('){
                                p->head->valor = 0;
                            }
                            if (p->head->op == '^'){
                                p->head->valor = 3;
                            }
                        }
                    }
                }
                desencolar (c1);
            }     
        }
    }
    */
