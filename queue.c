#include <stdio.h>

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


