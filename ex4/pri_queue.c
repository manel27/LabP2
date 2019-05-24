#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pri_queue.h"

static void queue_exit_error(char *msg);

static void queue_exit_error(char *msg) {
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}

PRIQUEUE *mk_new_priqueue(int val, PRIORIDADE pri){
    PRIQUEUE *q = (PRIQUEUE *) malloc(sizeof(PRIQUEUE));
    VAL(q) = val;
    PRI(q) = pri;
    NXT(q) = NULL;
    return q;
}

PRIQUEUE *enqueue(PRIQUEUE *q, int val, PRIORIDADE pri){
    PRIQUEUE *prev = NULL;
    PRIQUEUE *curr = q;
    if(q == NULL){
        return mk_new_priqueue(val, pri);
    }
    if(pri != URGENTE){
        while(curr != NULL){
            prev = curr; 
            curr = NXT(curr);
        }
        NXT(prev) = mk_new_priqueue(val, pri);
        return q;
    }
    else{
        while(curr != NULL && pri == URGENTE){
            prev = curr;
            curr = NXT(curr);
        }
        PRIQUEUE * new = mk_new_priqueue(val,pri);
        NXT(new) = NXT(prev);
        NXT(prev) = new;
        return q;
    }
}