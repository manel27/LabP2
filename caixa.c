#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "caixa.h"


CAIXA *init(int numero) {

    CAIXA *c = (CAIXA *) malloc(sizeof(CAIXA));

    c->fila = mk_empty_queue(QSize);
    c->pronta_em = 0;
    c->cts_atend = 0;
    c->produtos_processados = 0;
    c->total_espera = 0;
    c->n_c = numero;
    srand(time(0));
    c->prods_ut = (rand() % (MAXPC - MINPC +1)) + MINPC;

    return c;
}

void muda_info_caixa(CAIXA *c, int valor) {
    info_caixa(c) = valor;
}

void aumenta_clientes_atendidos(CAIXA *c) {
    clientes_atendidos(c)++;
}

void muda_info_produtos(CAIXA *c, int produtos) {
    info_produtos(c)+=produtos;
}

void muda_info_t_espera(CAIXA *c, int t) {
    info_t_espera(c)+=t;
}

char *repr(CAIXA c) {

    char *rep;
    sprintf(rep, "Caixa %d (%d): %d");

}


char * int2str(int n) {

    int ndigits = (int)log10(n)+1;
    char *res = malloc(sizeof(char)*(ndigits+1));
    int i;
    res[ndigits] = '\0';
    ndigits--;
    do {
        res[ndigits--] = (n%10)+'0';
        n = n/10;
    } while(n!=0);

    return res;
}
