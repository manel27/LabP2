#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define VAL(P) ((P) -> val)
#define PRI(P) ((P) -> pri)
#define NXT(P) ((P) -> next)

typedef enum prioridade{URGENTE, NORMAL} PRIORIDADE;

typedef struct priqueue{
  int val;
  PRIORIDADE pri;
  struct priqueue *next;
} PRIQUEUE;


// cria nova priqueue
PRIQUEUE *mk_new_priqueue(int val, PRIORIDADE pri);
// adiciona um elemento a fila
PRIQUEUE *enqueue(PRIQUEUE *q, int val, PRIORIDADE pri);
// retira o elemento com mais prioridade na fila
int dequeue(PRIQUEUE *q);
// aumenta a prioridade do 1º elemento da fila NORMAL
void promotion(PRIQUEUE *q);
#endif
