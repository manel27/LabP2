#include <stdio.h>
#include "queue.h"
#include "linkedlist.h"


int main() {

  QUEUE *q = mk_empty_queue(10);

  enqueue(2,q);
  enqueue(3,q);
  enqueue(1,q);

  NODE *list = queue_to_list(q);

  print_llist(list);

  return 0;

}
