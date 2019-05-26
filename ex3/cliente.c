#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"



CLIENTE *novo_cliente(int items, int entrada) {

    CLIENTE *c = (CLIENTE *)malloc(sizeof(CLIENTE));

    c->items = items;
    c->entrada = entrada;

    return c;
}

char* repr_cliente(CLIENTE *c) {

    char *str=NULL;
    sprintf(str, " [%d:%d]", artigos(c), tempo_entrada(c));

    return str;
}
