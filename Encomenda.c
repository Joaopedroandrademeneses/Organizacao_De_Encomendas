#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encomenda.h"

Encomenda* criarEncomenda(int id, const char* nome, const char* endereco, double peso) {
    if (peso <= 0) {
        fprintf(stderr, "Erro: O peso da encomenda deve ser maior que zero.\n");
        return NULL;
    }
    Encomenda* nova = malloc(sizeof(Encomenda));
    if (nova == NULL) return NULL;
    nova->id = id;
    strncpy(nova->nome, nome, sizeof(nova->nome) - 1);
    nova->nome[sizeof(nova->nome) - 1] = '\0';
    strncpy(nova->endereco, endereco, sizeof(nova->endereco) - 1);
    nova->endereco[sizeof(nova->endereco) - 1] = '\0';
    nova->peso = peso;
    return nova;
}