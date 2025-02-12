#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, c;
} Estrada;

int comparar(const void *a, const void *b) {
    return ((Estrada*)a)->c - ((Estrada*)b)->c;
}

int encontrar(int *conjunto, int x) {
    if (conjunto[x] != x) conjunto[x] = encontrar(conjunto, conjunto[x]);
    return conjunto[x];
}

void unir(int *conjunto, int *rank, int x, int y) {
    x = encontrar(conjunto, x);
    y = encontrar(conjunto, y);
    if (x != y) {
        if (rank[x] > rank[y]) conjunto[y] = x;
        else if (rank[x] < rank[y]) conjunto[x] = y;
        else {
            conjunto[y] = x;
            rank[x]++;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Estrada *estradas = malloc(m * sizeof(Estrada));
    int *conjunto = malloc((n + 1) * sizeof(int));
    int *rank = calloc((n + 1), sizeof(int));
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &estradas[i].u, &estradas[i].v, &estradas[i].c);
    }
    
    qsort(estradas, m, sizeof(Estrada), comparar);
    
    for (int i = 1; i <= n; i++) conjunto[i] = i;
    
    int custo_total = 0, arestas = 0;
    for (int i = 0; i < m && arestas < n - 1; i++) {
        if (encontrar(conjunto, estradas[i].u) != encontrar(conjunto, estradas[i].v)) {
            unir(conjunto, rank, estradas[i].u, estradas[i].v);
            custo_total += estradas[i].c;
            arestas++;
        }
    }
    
    printf("%d\n", custo_total);
    
    free(estradas);
    free(conjunto);
    free(rank);
    
    return 0;
}
