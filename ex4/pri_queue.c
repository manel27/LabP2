#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pri_queue.h"

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
    if(pri == NORMAL){
        while(curr != NULL){
            prev = curr; 
            curr = NXT(curr);
        }
        NXT(prev) = mk_new_priqueue(val, pri);
        return q;
    }
    else{ // tarefa URGENTE
        if(PRI(q) == NORMAL){
            PRIQUEUE *new = mk_new_priqueue(val,pri);
            VAL(new)= VAL(q);
            NXT(new) = NXT(q);
            PRI(new) = PRI(q);
            VAL(q)= val;
            NXT(q)= new;
            PRI(q) = pri;
            return q;
        }
        else{
            while(curr != NULL && PRI(curr) == URGENTE){
                prev = curr;
                curr = NXT(curr);
            }
            PRIQUEUE * new = mk_new_priqueue(val,pri);
            NXT(new) = NXT(prev);
            NXT(prev) = new;
            return q;
        }
    }
}

int dequeue(PRIQUEUE *q){
    if(q == NULL){
        printf("Erro! Lista vazia\n");
    }
    int valor = VAL(q);
    VAL(q) = VAL(NXT(q));
    NXT(q) = NXT(NXT(q));
    PRI(q) = PRI(NXT(q));
    return valor;
}

void promotion(PRIQUEUE *q){
    PRIQUEUE *curr = q;
    if(q == NULL){
        printf("Fila vazia\n");
    }
    while(PRI(curr) == URGENTE){
        curr = NXT(curr);
    }
    PRI(curr) = URGENTE;
}

void print_priqueue(PRIQUEUE *q){
    PRIQUEUE *curr = q;
    printf("-------------------------------------\n");
    if(q == NULL) printf("Lista vazia\n");
    while(curr!=NULL){
        printf("Val: %d && pri: %d\n", VAL(curr), PRI(curr));
        curr = NXT(curr);
    }
    printf("-------------------------------------\n");

}
