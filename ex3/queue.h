#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include "cliente.h"

#define TOPO(P) ((P) -> queue[(P) -> inicio])
#define TAMANHO(P) ((P) -> nmax)
#define INICIO(P) ((P) -> inicio)
#define FIM(P) ((P) -> fim)

typedef enum bool{FALSE,TRUE} BOOL;


typedef struct fila {
  int inicio, fim, nmax;
  CLIENTE* *queue;
} QUEUE;


// criar fila com capacidade para n inteiros
QUEUE *mk_empty_queue(int n);
// liberta fila
void free_queue(QUEUE *f);
// colocar valor na fila
void enqueue(CLIENTE *v,QUEUE *q);
// retirar valor na fila
CLIENTE* dequeue(QUEUE *q);

// verifica se listas sao iguais
// BOOL filas_iguais(QUEUE *q1, QUEUE *q2);

// retorna o numero de elementos na fila
int comprimento(QUEUE *q);
// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE *f);
// verificar se a fila n�o admite mais elementos
BOOL queue_is_full(QUEUE *f);
// fila para lista ligada
NODE *queue_to_list(QUEUE *q);

// Converte inteiro numa string
// char * int2str(int n);
// converte queue em string
char *queue2str(QUEUE *q);

#endif
