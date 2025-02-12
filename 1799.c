

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_PONTOS 4001
#define MAX_CONEXOES 5001
#define MAX_NOME 51

typedef struct No {
    int destino;
    struct No* proximo;
} No;

typedef struct {
    int numVertices;
    No* listaAdj[MAX_PONTOS];
    char nomes[MAX_PONTOS][MAX_NOME];
} Grafo;

typedef struct {
    int vertice;
    int distancia;
} ElementoHeap;

void trocar(ElementoHeap *a, ElementoHeap *b) {
    ElementoHeap temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(ElementoHeap *heap, int tamanho, int idx) {
    int menor = idx;
    int esq = 2 * idx + 1;
    int dir = 2 * idx + 2;

    if (esq < tamanho && heap[esq].distancia < heap[menor].distancia)
        menor = esq;

    if (dir < tamanho && heap[dir].distancia < heap[menor].distancia)
        menor = dir;

    if (menor != idx) {
        trocar(&heap[idx], &heap[menor]);
        minHeapify(heap, tamanho, menor);
    }
}

void inicializarGrafo(Grafo* grafo) {
    grafo->numVertices = 0;
    for (int i = 0; i < MAX_PONTOS; i++) {
        grafo->listaAdj[i] = NULL;
    }
}

void adicionarAresta(Grafo* grafo, int origem, int destino) {
    No* novoNo = malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNo;

    novoNo = malloc(sizeof(No));
    novoNo->destino = origem;
    novoNo->proximo = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = novoNo;
}

int bfsDistancia(Grafo* grafo, int inicio, int fim) {
    int distancia[MAX_PONTOS];
    int visitado[MAX_PONTOS] = {0};
    int fila[MAX_PONTOS], frente = 0, tras = 0;

    for (int i = 0; i < grafo->numVertices; i++) {
        distancia[i] = INT_MAX;
    }
    
    distancia[inicio] = 0;
    visitado[inicio] = 1;
    fila[tras++] = inicio;

    while (frente < tras) {
        int atual = fila[frente++];
        
        if (atual == fim) {
            return distancia[atual];
        }

        for (No* v = grafo->listaAdj[atual]; v != NULL; v = v->proximo) {
            if (!visitado[v->destino]) {
                visitado[v->destino] = 1;
                distancia[v->destino] = distancia[atual] + 1;
                fila[tras++] = v->destino;
            }
        }
    }

    return -1;
}

int main() {
    int numPontos, numConexoes;
    Grafo grafo;
    
    scanf("%d %d", &numPontos, &numConexoes);
    inicializarGrafo(&grafo);

    int indiceEntrada = -1, indiceQueijo = -1, indiceSaida = -1;

    for (int i = 0; i < numConexoes; i++) {
        char origem[MAX_NOME], destino[MAX_NOME];
        scanf("%s %s", origem, destino);

        int idxOrigem = -1, idxDestino = -1;
        
        for (int j = 0; j < grafo.numVertices; j++) {
            if (strcmp(grafo.nomes[j], origem) == 0) {
                idxOrigem = j;
                break;
            }
        }
        if (idxOrigem == -1) {
            idxOrigem = grafo.numVertices;
            strcpy(grafo.nomes[grafo.numVertices], origem);
            grafo.numVertices++;
        }

        for (int j = 0; j < grafo.numVertices; j++) {
            if (strcmp(grafo.nomes[j], destino) == 0) {
                idxDestino = j;
                break;
            }
        }
        if (idxDestino == -1) {
            idxDestino = grafo.numVertices;
            strcpy(grafo.nomes[grafo.numVertices], destino);
            grafo.numVertices++;
        }

        adicionarAresta(&grafo, idxOrigem, idxDestino);

        if (strcmp(origem, "Entrada") == 0) indiceEntrada = idxOrigem;
        if (strcmp(destino, "Entrada") == 0) indiceEntrada = idxDestino;
        if (strcmp(origem, "*") == 0) indiceQueijo = idxOrigem;
        if (strcmp(destino, "*") == 0) indiceQueijo = idxDestino;
        if (strcmp(origem, "Saida") == 0) indiceSaida = idxOrigem;
        if (strcmp(destino, "Saida") == 0) indiceSaida = idxDestino;
    }

    int caminho1 = bfsDistancia(&grafo, indiceEntrada, indiceQueijo);
    int caminho2 = bfsDistancia(&grafo, indiceQueijo, indiceSaida);

    printf("%d\n", caminho1 + caminho2);

    return 0;
}
