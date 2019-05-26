#ifndef CLIENTE_H
#define CLIENTE_H

#define artigos(P) ((P) -> items)
#define tempo_entrada(P) ((P) -> entrada)


typedef struct cliente {
    int items;
    int entrada;
} CLIENTE;

// cria um novo cliente
CLIENTE *novo_cliente(int items, int entrada);
// Retorna uma setring que representa o cliente
char* repr_cliente(CLIENTE *c);

#endif
