#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "cliente.h"

#define VAL(P) ((P)->val)
#define NXT(P) ((P)->nxt)

typedef struct node {
  CLIENTE *val;
  struct node *nxt;
} NODE;

NODE *new_node(CLIENTE *c);                 //cria um nó com um valor
NODE *add_last(NODE *lista_instr, CLIENTE *c);  //adiciona ao fim da lista um no com uma instrucao
void print_llist();                          //imprime o conteudo da lista
NODE *last(NODE *lista_instr);               //retorna o ultimo elemento da lista

#endif
