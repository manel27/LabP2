#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "caixa.h"


CAIXA *nova_caixa(int numero) {

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


char *repr_caixa(CAIXA *c) {

    char *repr =NULL;

    cats(&repr,"Caixa ");
    cats(&repr,int2str(num_caixa(c)));
    cats(&repr," (");
    cats(&repr,int2str(info_caixa(c)));
    cats(&repr,"): ");
    cats(&repr,queue2str(c->fila));

    return repr;

}
