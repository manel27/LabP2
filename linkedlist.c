#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

NODE *new_node(int val) {
  NODE *l = (NODE *)malloc(sizeof(NODE));
  l->val = val;
  l->nxt = NULL;
  return l;
}

NODE *add_last(NODE *lista_instr, int val) {
  NODE *prev = NULL;
  NODE *curr = lista_instr;
  if (lista_instr == NULL) {
    return new_node(val);
  }
  while (curr != NULL) {
    prev = curr;
    curr = NXT(curr);
  }

  NXT(prev) = new_node(val);

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
    printf("%d\n", curr->val);
    curr = NXT(curr);
  }
}
