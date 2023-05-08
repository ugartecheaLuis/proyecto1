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
    c = cola_vacia();

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
    
    ordenar (c1, c);
    imprimir (c);
    printf ("El resultado es: %d\n", calcular(c));

    return 0;
}