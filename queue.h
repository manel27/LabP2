#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

#define INICIO(P) ((P) -> queue[(P) -> inicio])
#define TAMANHO(P) ((P) -> nmax)


typedef enum bool{FALSE,TRUE} BOOL;


typedef struct fila {
  int inicio, fim, nmax;
  int *queue;
} QUEUE;


// criar fila com capacidade para n inteiros
QUEUE *mk_empty_queue(int n);
// colocar valor na fila
void enqueue(int v,QUEUE *f);
// retirar valor na fila
int dequeue(QUEUE *f);
// verificar se a fila est� vazia
BOOL queue_is_empty(QUEUE *f);
// verificar se a fila n�o admite mais elementos
BOOL queue_is_full(QUEUE *f);
// liberta fila
void free_queue(QUEUE *f);


NODE *queue_to_list(QUEUE *q);
BOOL filas_iguais(QUEUE *q1, QUEUE *q2);
#endif
