#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void queue_exit_error(char *msg);

static void queue_exit_error(char *msg)
{
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}

// criar fila com capacidade para n inteiros
QUEUE *mk_empty_queue(int n)
{
  QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
  if (q == NULL)
    queue_exit_error("sem memoria");

  q -> queue =  (int *) malloc(sizeof(int)*n);
  if (q -> queue == NULL)
    queue_exit_error("sem memoria");

  q -> nmax = n;
  q -> inicio = -1;
  q -> fim = 0;
  return q;
}

// libertar fila
void free_queue(QUEUE *q)
{
  if (q != NULL) {
    free(q -> queue);
    free(q);
  } else
    queue_exit_error("fila mal construida");
}


// colocar valor na fila
void enqueue(int v,QUEUE *q)
{
  if (queue_is_full(q) == TRUE)
    queue_exit_error("fila sem lugar");

  if (q -> queue == NULL)
    queue_exit_error("fila mal construida");

  if (queue_is_empty(q)==TRUE)
    q -> inicio = q -> fim; // fila fica com um elemento
  q -> queue[q->fim] = v;
  q -> fim = (q -> fim+1)%(q->nmax);
}

// retirar valor na fila
int dequeue(QUEUE *q)
{
  int aux;
  if (queue_is_empty(q) == TRUE)
    queue_exit_error("fila sem valores");

  if (q -> queue == NULL)
    queue_exit_error("fila mal construida");

  aux = q ->queue[q ->inicio];
  q -> inicio = (q -> inicio+1)%(q -> nmax);
  if (q -> inicio ==  q -> fim) {  // se s� tinha um elemento
    q -> inicio = -1; q -> fim = 0;
  }
  return aux;
}

//filas iguais para tamanhos iguais
BOOL filas_iguais(QUEUE *q1, QUEUE *q2){
  int i, aux1, aux2, size;
  if(queue_is_empty(q1) == queue_is_empty(q2)){
    return TRUE;
  }
  if(q1->nmax != q2->nmax){
    return FALSE;
  }
  size = TAMANHO(q1);
  int aux1 = q1 -> inicio;
  int aux2 = q2 -> inicio;

  while(aux1 != q1-> fim && aux2 != q2-> fim){
    aux1 = (aux1+1)%(size);
    aux2 = (aux2+1)%(size);
    if(q1->queue[aux1] != q2->queue[aux2])
      return FALSE;
  }

}

// verificar se a fila est� vazia
BOOL queue_is_empty(QUEUE *q)
{
  if (q == NULL)
    queue_exit_error("fila mal construida");

  if (q -> inicio == -1) return TRUE;
  return FALSE;
}

// verificar se a fila n�o admite mais elementos
BOOL queue_is_full(QUEUE *q)
{
  if (q == NULL)
    queue_exit_error("fila mal construida");

  if (q -> fim == q -> inicio) return TRUE;
  return FALSE;
}


