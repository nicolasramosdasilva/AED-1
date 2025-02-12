#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *esquerda;
    struct Nodo *direita;
} Nodo;

typedef struct Fila {
    Nodo *nodo;
    struct Fila *proximo;
} Fila;

Nodo* criarNodo(int valor) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para inserir um valor na árvore binária de busca
Nodo* inserir(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return criarNodo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Funções para manipular a fila
void enfileirar(Fila** frente, Fila** tras, Nodo* nodo) {
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->nodo = nodo;
    novo->proximo = NULL;
    if (*tras != NULL) {
        (*tras)->proximo = novo;
    }
    *tras = novo;
    if (*frente == NULL) {
        *frente = novo;
    }
}

Nodo* desenfileirar(Fila** frente, Fila** tras) {
    if (*frente == NULL) {
        return NULL;
    }
    Nodo* nodo = (*frente)->nodo;
    Fila* temp = *frente;
    *frente = (*frente)->proximo;
    if (*frente == NULL) {
        *tras = NULL;
    }
    free(temp);
    return nodo;
}

// Função para realizar o percurso por nível
void percursoPorNivel(Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }

    Fila* frente = NULL;
    Fila* tras = NULL;

    enfileirar(&frente, &tras, raiz);

    int primeiro = 1;
    while (frente != NULL) {
        Nodo* atual = desenfileirar(&frente, &tras);

        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esquerda != NULL) {
            enfileirar(&frente, &tras, atual->esquerda);
        }
        if (atual->direita != NULL) {
            enfileirar(&frente, &tras, atual->direita);
        }
    }
}

int main() {
    int casos;
    scanf("%d", &casos);

    for (int i = 1; i <= casos; i++) {
        int n;
        scanf("%d", &n);

        Nodo* raiz = NULL;

        // Inserir os valores na árvore
        for (int j = 0; j < n; j++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        // Imprimir o caso e o percurso por nível
        printf("Case %d:\n", i);
        percursoPorNivel(raiz);
        printf("\n\n");

    }

    return 0;
}
