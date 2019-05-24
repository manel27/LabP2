#include <stdio.h>
#include "queue.h"
#include "linkedlist.h"


int main() {

  QUEUE *q1 = mk_empty_queue(10);
  QUEUE *q2 = mk_empty_queue(20);

  enqueue(2,q1);
  enqueue(3,q1);
  enqueue(1,q1);

  enqueue(2,q2);
  enqueue(3,q2);
  enqueue(1,q2);
  enqueue(4,q2);

  printf("teste: %d\n", filas_iguais(q1,q2));

  return 0;

}
