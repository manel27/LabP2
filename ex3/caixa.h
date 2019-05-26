# ifndef CASHIER_H
# define CASHIER_H

#include "queue.h"

#define QSize 20
#define MINPC 1
#define MAXPC 5

#define fila_caixa(P) ((P)->fila)
#define num_caixa(P) ((P)->n_c)
#define info_caixa(P) ((P)->pronta_em)
#define clientes_atendidos(P) ((P)->cts_atend)
#define info_produtos(P) ((P)->produtos_processados)
#define info_t_espera(P) ((P)->total_espera)
#define produtos_processados_ciclo(P) ((P)->prods_ut)


typedef struct caixa {

    QUEUE *fila;

    int pronta_em;
    int cts_atend;
    int produtos_processados;
    int total_espera;
    int n_c;
    int prods_ut;

} CAIXA;

CAIXA *nova_caixa(int numero);
void muda_info_caixa(CAIXA *c, int valor);
void aumenta_clientes_atendidos(CAIXA *c);
void muda_info_produtos(CAIXA *c, int produtos);
void muda_info_t_espera(CAIXA *c, int t);
char *repr_caixa(CAIXA *c);



# endif
