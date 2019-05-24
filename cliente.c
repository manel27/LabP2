#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

char* print_cliente(CLIENTE *c){
    char *str;
    sprintf(str, "[%d:%d]", ITEMS(c), N_CICLO(c), ENTRADA(c));
}
