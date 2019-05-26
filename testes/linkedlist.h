#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define VAL(P) ((P)->val)
#define NXT(P) ((P)->nxt)

typedef struct node {
  int val;
  struct node *nxt;
} NODE;

NODE *new_node(int val);                 //cria um nó com um valor
NODE *add_last(NODE *lista_instr, int val);  //adiciona ao fim da lista um no com uma instrucao
void print_llist();                          //imprime o conteudo da lista
NODE *last(NODE *lista_instr);               //retorna o ultimo elemento da lista

#endif
