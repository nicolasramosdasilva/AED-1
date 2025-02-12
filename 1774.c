#include <stdio.h>
#include <stdlib.h>

#define MAX_R 60
#define MAX_C 200

typedef struct {
    int origem, destino, custo;
} Aresta;

Aresta arestas[MAX_C];
int pai[MAX_R], rank[MAX_R];

int compara(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->custo - arestaB->custo;
}

int encontrar(int x) {
    if (pai[x] == x) return x;
    return pai[x] = encontrar(pai[x]);
}

void unir(int x, int y) {
    int raizX = encontrar(x);
    int raizY = encontrar(y);

    if (raizX != raizY) {
        if (rank[raizX] > rank[raizY]) {
            pai[raizY] = raizX;
        } else if (rank[raizX] < rank[raizY]) {
            pai[raizX] = raizY;
        } else {
            pai[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].custo);
        arestas[i].origem--;  // Ajuste para índice baseado em zero
        arestas[i].destino--;
    }

    qsort(arestas, C, sizeof(Aresta), compara);

    for (int i = 0; i < R; i++) {
        pai[i] = i;
        rank[i] = 0;
    }

    int custo_total = 0;
    for (int i = 0; i < C; i++) {
        if (encontrar(arestas[i].origem) != encontrar(arestas[i].destino)) {
            unir(arestas[i].origem, arestas[i].destino);
            custo_total += arestas[i].custo;
        }
    }

    printf("%d\n", custo_total);

    return 0;
}
