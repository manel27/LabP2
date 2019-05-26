#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"
#include "caixa.h"

void simula_supermercado(int afluencia, int apetencia, int n_caixas, int ciclos);
void trata_clientes(int tempo, CAIXA **caixas, int n_caixas);
void processa_resultados(CAIXA **caixas, int n_caixas);
void mostra_caixas(CAIXA **caixas, int n_caixas);
BOOL existem_caixas_com_fila(CAIXA **caixas, int n_caixas);
char * int2str(int n);

int main() {

    int afluencia;
    int apetencia;
    int n_caixas;
    int ciclos;

    printf("Afluencia:\n");
    scanf("%d", &afluencia);
    printf("Apetencia:\n");
    scanf("%d", &apetencia);
    printf("N_Caixas:\n");
    scanf("%d", &n_caixas);
    printf("Ciclos\n");
    scanf("%d", &ciclos);

    simula_supermercado(afluencia, apetencia, n_caixas, ciclos);

    return 0;

}


void simula_supermercado(int afluencia, int apetencia, int n_caixas, int ciclos) {

    CAIXA* caixas[n_caixas];

    //inicializar as caixas
    for(int i=0; i<n_caixas; i++){
        caixas[i] = nova_caixa(i);
    }

    for (int i=0; i<ciclos; i++) {

        printf("== CICLO == %d\n", i);

        // processa os clientes nas caixas

        trata_clientes(i, caixas, n_caixas);

        //decide a criação de novo cliente e númerp de compras

        srand(time(0));
        double aleatorio = (double) rand() / (double)RAND_MAX;
        double limar = afluencia/100;

        if (aleatorio < limar) { //um novo cliente é criado

            srand(time(0));
            int num_compras = (((double) rand() / (double)RAND_MAX) * 3 * apetencia) + 1;
            printf("--> Criado cliente com %d artigos\n", num_compras);
            CLIENTE *c = novo_cliente(num_compras,i);

            // insere o cliente na fila de uma caixa

            srand(time(0));
            int nb_cx = ((double) rand() / (double)RAND_MAX) * n_caixas; //seleciona a caixa



            enqueue(c,fila_caixa(caixas[nb_cx]));

            mostra_caixas(caixas,n_caixas);


        }

    }

    // processa as filas depois do fecho de entradas

    int i = ciclos+1;

    printf("Entradas fechadas\n");

    while (existem_caixas_com_fila(caixas,n_caixas)) {
        printf(" == CILCO == %d\n", i);

        // processa os clientes nas caixas
        trata_clientes(i,caixas,n_caixas);

        mostra_caixas(caixas,n_caixas);
        i = i + 1;
    }

    processa_resultados(caixas, n_caixas);

}



void trata_clientes(int tempo, CAIXA **caixas, int n_caixas) {

    for (int i=0; i<n_caixas; i++) {

        if (!queue_is_empty(fila_caixa(caixas[i]))) {
            // se a fila associada à caixa não está vazia
            // verificar se o atendimento ao cliente terminou
            CLIENTE *c = TOPO(fila_caixa(caixas[i]));
            int nb_artigos = artigos(c);
            int t_atendimento = tempo - info_caixa(caixas[i]);
            int artigos_prcds = nb_artigos/produtos_processados_ciclo(caixas[i]);

            if (artigos_prcds < t_atendimento) {
                // o cliente sai da fila da caixa
                int t_entrada_fila = tempo_entrada(c);
                int t_espera = tempo - t_entrada_fila;
                printf("--> Processado cliente com %d artigos na caixa %d tempo de espera %d\n", nb_artigos, num_caixa(caixas[i]), t_espera);
                muda_info_caixa(caixas[i], tempo+1);
                aumenta_clientes_atendidos(caixas[i]);
                muda_info_produtos(caixas[i],nb_artigos);
                muda_info_t_espera(caixas[i],t_espera);
                dequeue(fila_caixa(caixas[i])); //o cliente sai da fila
            }

        }

        else {

            // para as caixas vazias atualiza o tempo potencial para atendimento

            muda_info_caixa(caixas[i],tempo);

        }

    }

}

void processa_resultados(CAIXA **caixas, int n_caixas) {

    for (int i=0; i<n_caixas; i++) {

        int c_t = clientes_atendidos(caixas[i]);

        if (c_t !=0) {

            printf("Caixa %d (atendimento %d produtos por ciclo):", num_caixa(caixas[i]), produtos_processados_ciclo(caixas[i]));
            printf(" %d clientes atendidos, média produtos/cliente %d,\n", c_t, (info_produtos(caixas[i])/c_t));
            printf("tempo médio de espera %d\n", info_t_espera(caixas[i]));

        }

        else {

            printf("Caixa %d: não atendeu clientes\n", num_caixa(caixas[i]));

        }

    }

}

void mostra_caixas(CAIXA **caixas, int n_caixas) {

    for (int i=0; i<n_caixas; i++) {

        printf("%s\n",repr_caixa(caixas[i]));

    }

}

BOOL existem_caixas_com_fila(CAIXA **caixas, int n_caixas) {

    for (int i=0; i<n_caixas; i++) {

        if (!queue_is_empty(fila_caixa(caixas[i]))) {
            return TRUE;
        }

    }

    return FALSE;

}

// char *int2str(int n) {
//
//     int ndigits = (int)log10(n)+1;
//     char *res = malloc(sizeof(char)*(ndigits+1));
//     int i;
//     res[ndigits] = '\0';
//     ndigits--;
//     do {
//         res[ndigits--] = (n%10)+'0';
//         n = n/10;
//     } while(n!=0);
//
//     return res;
// }
