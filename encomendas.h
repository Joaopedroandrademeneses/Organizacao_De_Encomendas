#ifndef ENCOMENDAS_H
#define ENCOMENDAS_H

#include "no.h"

typedef struct {
    No *inicio;
    No *fim;
} Encomendas;

void inicializarEncomenda(Encomendas* encomendas);
int adicionarEncomenda(Encomendas* encomendas, Encomenda encomenda);

#endif