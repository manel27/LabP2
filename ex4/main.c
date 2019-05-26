#include <stdio.h>
#include "pri_queue.h"

int main(){
    PRIQUEUE *q = mk_new_priqueue(1,URGENTE);
    enqueue(q,2,NORMAL);
    enqueue(q,3,URGENTE);
    enqueue(q,4,NORMAL);
    enqueue(q,5,NORMAL);
    enqueue(q,6,NORMAL);
    enqueue(q,7,URGENTE);
    dequeue(q);
    promotion(q);
    print_priqueue(q);
    return 0;
}