#include <stdio.h>
#include "queue.h"
#include "linkedlist.h"


int main() {

  QUEUE *q1 = mk_empty_queue(10);
  QUEUE *q2 = mk_empty_queue(10);

  enqueue(5,q1);
  enqueue(5,q1);
  enqueue(5,q1);
  enqueue(5,q1);

  enqueue(5,q2);
  enqueue(5,q2);
  enqueue(5,q2);
  enqueue(5,q2);

  printf("filas iguais? %d\n", filas_iguais(q1,q2));

  return 0;

}
