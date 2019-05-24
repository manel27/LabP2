# LabP2
2nd assignment

## Geral

- [ ] Comparar a implementação de filas de prioridade  - suporte por vetores e por listas ligadas

----

## Funções QUEUE

#### Construtor
- [x] (```QUEUE *mk_empty_queue(int n)```) - Cria uma nova fila do nada

----
#### Selectores
- [x] (```inicio()```) - Elemento no inicio da fila
- [ ] (```comprimento()```) - Devolve o nº de elementos da fila

----
#### Modificadores
- [x] (```void enqueue(int v,QUEUE *q)```) - Inserção no fim da fila (retorna fila resultante)
- [x] (```int dequeue(QUEUE *q)```) - Retira o elemento no início da fila (retorna fila resultante, se for fazia retorna NULL)

----
#### Transformadores
- [x] (```fila_para_lista()```) - Retorna elementos da queue numa lista ligada

----
#### Reconhecedores
- [x] (```e_fila()```) - Recebe como argumento um elemento de qualquer tipo e verifica se é o tipo do tipo fila
- [x] (```fila_vazia()```) - Decide se é vazia

----
#### Testes
- [x] (```filas_iguais()```) - Recebe duas filas e decide se são iguais

----
