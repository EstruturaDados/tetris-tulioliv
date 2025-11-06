#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5

typedef struct {
    int id;
} Peca;

typedef struct {
    Peca fila[TAMANHO];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

// Gera uma nova peça com ID aleatório
Peca gerarPeca() {
    Peca nova;
    nova.id = rand() % 100; // ID entre 0 e 99
    return nova;
}

// Inicializa a fila com 5 peças
void inicializarFila(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
    for (int i = 0; i < TAMANHO; i++) {
        f->fila[i] = gerarPeca();
        f->fim = (f->fim + 1) % TAMANHO;
        f->quantidade++;
    }
}

// Exibe o estado atual da fila
void visualizarFila(FilaCircular *f) {
    printf("\nFila atual:\n");
    if (f->quantidade == 0) {
        printf("Fila vazia.\n");
        return;
    }
    int i = f->inicio;
    for (int count = 0; count < f->quantidade; count++) {
        printf("Peca ID: %d\n", f->fila[i].id);
        i = (i + 1) % TAMANHO;
    }
}

// Remove a peça da frente (dequeue)
void jogarPeca(FilaCircular *f) {
    if (f->quantidade == 0) {
        printf("Não há peças para jogar.\n");
        return;
    }
    printf("Jogando peça ID: %d\n", f->fila[f->inicio].id);
    f->inicio = (f->inicio + 1) % TAMANHO;
    f->quantidade--;
}

// Insere uma nova peça no final (enqueue)
void inserirPeca(FilaCircular *f) {
    if (f->quantidade == TAMANHO) {
        printf("Fila cheia. Não é possível inserir nova peça.\n");
        return;
    }
    f->fila[f->fim] = gerarPeca();
    printf("Inserida nova peça ID: %d\n", f->fila[f->fim].id);
    f->fim = (f->fim + 1) % TAMANHO;
    f->quantidade++;
}

// Menu principal
int main() {
    FilaCircular fila;
    int opcao;

    srand(time(NULL));
    inicializarFila(&fila);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Visualizar fila\n");
        printf("2. Jogar peça\n");
        printf("3. Inserir nova peça\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                visualizarFila(&fila);
                break;
            case 2:
                jogarPeca(&fila);
                visualizarFila(&fila);
                break;
            case 3:
                inserirPeca(&fila);
                visualizarFila(&fila);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}