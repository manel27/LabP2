#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

char* print_cliente(CLIENTE *c){
    char *str;
    sprintf(str, "[%d:%d]", ITEMS(c), ENTRADA(c));
}

CLIENTE *new_cliente(int items, int n_ciclo, int entrada){
    CLIENTE *c = (CLIENTE *)malloc(sizeof(CLIENTE));
    c->items = items;
    c->n_ciclo = n_ciclo;
    c->entrada = entrada;
}