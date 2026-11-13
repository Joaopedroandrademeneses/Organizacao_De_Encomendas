#ifndef NO_H
#define NO_H

#include "encomenda.h"

typedef struct No {
    Encomenda encomenda;
    struct No* proximo;
} No;

#endif