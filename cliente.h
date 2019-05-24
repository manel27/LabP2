#ifndef CLIENTE_H
#define CLIENTE_H

#define ITEMS(P) ((P) -> items)
#define N_CICLO(P) ((P) -> n_ciclo)
#define ENTRADA(P) ((P) -> entrada)


typedef struct cliente {
    int items, n_ciclo, entrada;
} CLIENTE;

// cria um novo cliente
CLIENTE *new_cliente(int items, int n_ciclo, int entrada);
// imprime o conteudo do cliente
char* print_cliente(CLIENTE *c);

#endif