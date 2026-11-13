#include <stdio.h>
#include <stdlib.h>
#include "encomendas.h"

void inicializarEncomenda(Encomendas* encomendas) {
    encomendas->inicio = NULL;
    encomendas->fim = NULL;
}

int adicionarEncomenda(Encomendas* encomendas, Encomenda encomenda) {
    No* novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        return 0;
    }
    novoNo->encomenda = encomenda;
    novoNo->proximo = NULL;

    if (encomendas->fim == NULL) {
        encomendas->inicio = novoNo;
    } else {
        encomendas->fim->proximo = novoNo;
    }
    encomendas->fim = novoNo;

    return 1;
}