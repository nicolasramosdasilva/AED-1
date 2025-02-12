//Nicolas Ramos da Silva 178197

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int a, b;
    double peso;
} Aresta;

typedef struct {
    int x, y;
} Ponto;

int encontrar(int pai[], int i) {
    if (pai[i] == i) return i;
    return pai[i] = encontrar(pai, pai[i]);
}

void unir(int pai[], int rank[], int a, int b) {
    int raiz_a = encontrar(pai, a);
    int raiz_b = encontrar(pai, b);
    
    if (raiz_a != raiz_b) {
        if (rank[raiz_a] > rank[raiz_b]) {
            pai[raiz_b] = raiz_a;
        } else if (rank[raiz_a] < rank[raiz_b]) {
            pai[raiz_a] = raiz_b;
        } else {
            pai[raiz_b] = raiz_a;
            rank[raiz_a]++;
        }
    }
}

int comparar_arestas(const void *x, const void *y) {
    Aresta *ar1 = (Aresta *)x;
    Aresta *ar2 = (Aresta *)y;
    return (ar1->peso > ar2->peso) - (ar1->peso < ar2->peso);
}

double kruskal(Aresta arestas[], int n, int qtd_arestas) {
    int pai[n], rank[n];
    for (int i = 0; i < n; i++) {
        pai[i] = i;
        rank[i] = 0;
    }

    qsort(arestas, qtd_arestas, sizeof(Aresta), comparar_arestas);

    double soma_peso = 0.0;
    int usadas = 0;
    
    for (int i = 0; i < qtd_arestas && usadas < n - 1; i++) {
        if (encontrar(pai, arestas[i].a) != encontrar(pai, arestas[i].b)) {
            soma_peso += arestas[i].peso;
            unir(pai, rank, arestas[i].a, arestas[i].b);
            usadas++;
        }
    }

    return soma_peso;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int n;
        scanf("%d", &n);
        
        Ponto pontos[n];
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pontos[i].x, &pontos[i].y);
        }

        Aresta arestas[n * (n - 1) / 2];
        int qtd_arestas = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = sqrt(pow(pontos[i].x - pontos[j].x, 2) + pow(pontos[i].y - pontos[j].y, 2)) / 100.0;
                arestas[qtd_arestas++] = (Aresta){i, j, dist};
            }
        }

        printf("%.2lf\n", kruskal(arestas, n, qtd_arestas));
    }

    return 0;
}
