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

    char *res=NULL;

    cats(&res,"[");
    cats(&res,int2str(artigos(c)));
    cats(&res,":");
    cats(&res,int2str(tempo_entrada(c)));
    cats(&res,"]");

    return res;
}
