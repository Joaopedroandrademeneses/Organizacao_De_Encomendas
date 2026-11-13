#ifndef ENCOMENDA_H
#define ENCOMENDA_H

typedef struct {
    int id;
    char nome[100];
    char endereco[200];
    double peso;
} Encomenda;

Encomenda* criarEncomenda(int id, const char* nome, const char* endereco, double peso);

#endif