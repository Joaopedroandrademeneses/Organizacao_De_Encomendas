#include <stdio.h>
#include <stdlib.h>
#include "encomenda.h"
#include "encomendas.h"

static int total = 0, passou = 0;

#define TESTE(desc, cond) do { \
    total++; \
    if (cond) { passou++; printf("[OK]   %s\n", desc); } \
    else { printf("[FALHA] %s\n", desc); } \
} while (0)

static int contar(Encomendas* e) {
    int n = 0;
    for (No* p = e->inicio; p != NULL; p = p->proximo) n++;
    return n;
}

static void listar(Encomendas* e) {
    for (No* p = e->inicio; p != NULL; p = p->proximo) {
        printf("  #%d | %s | %s | %.2f kg\n",
               p->encomenda.id, p->encomenda.nome,
               p->encomenda.endereco, p->encomenda.peso);
    }
}

static void liberar(Encomendas* e) {
    No* p = e->inicio;
    while (p != NULL) {
        No* prox = p->proximo;
        free(p);
        p = prox;
    }
    e->inicio = e->fim = NULL;
}

int main(void) {
    Encomendas lista;

    printf("== Teste: inicializar ==\n");
    inicializarEncomenda(&lista);
    TESTE("inicio NULL", lista.inicio == NULL);
    TESTE("fim NULL", lista.fim == NULL);

    printf("\n== Teste: criarEncomenda ==\n");
    Encomenda* e1 = criarEncomenda(1, "Joao", "Rua A, 10", 2.5);
    Encomenda* e2 = criarEncomenda(2, "Maria", "Rua B, 20", 10.0);
    Encomenda* e3 = criarEncomenda(3, "Pedro", "Rua C, 30", 0.75);
    TESTE("e1 criada", e1 != NULL && e1->id == 1 && e1->peso == 2.5);
    TESTE("e2 criada", e2 != NULL);
    TESTE("e3 criada", e3 != NULL);
    TESTE("peso zero retorna NULL", criarEncomenda(4, "X", "Y", 0) == NULL);
    TESTE("peso negativo retorna NULL", criarEncomenda(5, "X", "Y", -3) == NULL);

    printf("\n== Teste: adicionarEncomenda ==\n");
    TESTE("adicionar e1", adicionarEncomenda(&lista, *e1) == 1);
    TESTE("inicio == fim com 1 elemento", lista.inicio == lista.fim);
    TESTE("adicionar e2", adicionarEncomenda(&lista, *e2) == 1);
    TESTE("adicionar e3", adicionarEncomenda(&lista, *e3) == 1);
    TESTE("tamanho == 3", contar(&lista) == 3);
    TESTE("ordem: inicio id=1", lista.inicio->encomenda.id == 1);
    TESTE("ordem: fim id=3", lista.fim->encomenda.id == 3);
    TESTE("ordem: segundo id=2", lista.inicio->proximo->encomenda.id == 2);
    TESTE("fim->proximo NULL", lista.fim->proximo == NULL);

    printf("\n== Lista ==\n");
    listar(&lista);

    liberar(&lista);
    TESTE("lista vazia após liberar", lista.inicio == NULL && lista.fim == NULL);

    free(e1); free(e2); free(e3);

    printf("\nResultado: %d/%d testes passaram\n", passou, total);
    return (passou == total) ? 0 : 1;
}