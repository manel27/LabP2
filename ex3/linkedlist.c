#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

NODE *new_node(CLIENTE *c) {
  NODE *l = (NODE *)malloc(sizeof(NODE));
  l->val = c;
  l->nxt = NULL;
  return l;
}

NODE *add_last(NODE *lista_instr, CLIENTE *c) {
  NODE *prev = NULL;
  NODE *curr = lista_instr;
  if (lista_instr == NULL) {
    return new_node(c);
  }
  while (curr != NULL) {
    prev = curr;
    curr = NXT(curr);
  }

  NXT(prev) = new_node(c);

  return lista_instr;
}

NODE *last(NODE *lista_instr) {
  while (NXT(lista_instr) != NULL) {
    lista_instr = NXT(lista_instr);
  }

  return lista_instr;
}

void print_llist(NODE *lista_instr) {
  NODE *curr = lista_instr;
  if (curr == NULL) printf("Lista vazia\n");
  while (curr != NULL) {
    printf("%s\n", repr_cliente(curr->val));
    curr = NXT(curr);
  }
}
