#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// error
static void queue_exit_error(char *msg);

static void queue_exit_error(char *msg) {
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}

// criar fila com capacidade para n clientes
QUEUE *mk_empty_queue(int n)
{
  QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
  if (q == NULL)
    queue_exit_error("sem memoria");

  q -> queue = (CLIENTE **) malloc(sizeof(CLIENTE)*n);
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
void enqueue(CLIENTE *v,QUEUE *q) {
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
CLIENTE* dequeue(QUEUE *q) {
  CLIENTE *aux;
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

// //filas iguais
// BOOL filas_iguais(QUEUE *q1, QUEUE *q2){
//   int aux1, aux2;
//   if(queue_is_empty(q1) == 1  && queue_is_empty(q2) == 1) {
//     printf("uma das filas está vazia\n");
//     return TRUE;
//   }
//
//   aux1 = q1 -> inicio;
//   aux2 = q2 -> inicio;
//
//   while(aux1 != q1-> fim && aux2 != q2-> fim){
//       printf("q1: %d && q2: %d\n", q1->queue[aux1],  q2->queue[aux2]);
//     if(q1->queue[aux1] != q2->queue[aux2]){
//       return FALSE;
//     }
//     aux1 = (aux1+1)%(TAMANHO(q1));
//     aux2 = (aux2+1)%(TAMANHO(q2));
//   }
//   if(aux1 != q1-> fim || aux2 != q2-> fim)
//     return FALSE;
//   return TRUE;
// }

int comprimento(QUEUE *q){
  if(queue_is_empty(q))
    return 0;
  if(INICIO(q)<FIM(q))
    return (FIM(q) - INICIO(q));
  else{
    return ((TAMANHO(q) - INICIO(q) + FIM(q)));
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


NODE *queue_to_list(QUEUE *q) {

  NODE *lista = NULL;

  if (q -> queue == NULL) {
    queue_exit_error("fila mal construida");
  }

  if (queue_is_empty(q)==TRUE) {
    return lista;
  }

  int aux = q -> inicio;

  while (aux!=q->fim) {

    lista=add_last(lista,q -> queue[aux]);
    aux = (aux+1)%(q->nmax);

  }

  return lista;

}

// char * int2str(int n) {
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
//
char *queue2str(QUEUE *q) {

    char *res=NULL;

    strcat(res,"<");

    int aux = q->inicio;

    while(aux!=q->fim) {
        strcat(res,repr_cliente(q->queue[aux]));
    }

    strcat(res," <");

    return res;

}
