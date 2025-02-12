


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aresta {
    int origem;
    int final;
} Aresta;

typedef struct grafo {
   int V; 
   int A; 
   Aresta* arestas;
} Grafo;

Grafo* criarGrafo (int V, int A) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo -> V = V;
    grafo -> A = A;
    grafo -> arestas = (Aresta*)malloc(A * sizeof(Aresta));
    return grafo;
}

void DFS(int N, bool visitado[], Grafo* grafo, bool arestaVisitada[]) {
    visitado[N] = true;
    
    for (int i = 0; i < grafo -> A; i++) {
        if (!arestaVisitada[i]) {
            if (grafo -> arestas[i].origem == N && !visitado[grafo -> arestas[i].final]) {
                arestaVisitada[i] = true;
                DFS(grafo -> arestas[i].final, visitado, grafo, arestaVisitada);
            }
            if (grafo -> arestas[i].final == N && !visitado[grafo -> arestas[i].origem]) {
                arestaVisitada[i] = true;
                DFS(grafo -> arestas[i].origem, visitado, grafo, arestaVisitada);
            }
        }
    }
}

int calcularMinMovimentos(Grafo* grafo, int N) {
    bool* visitado = (bool*)malloc(grafo -> V * sizeof(bool));
    bool* arestaVisitada = (bool*)malloc(grafo -> A * sizeof(bool));
    
    for (int i = 0; i < grafo -> V; i++) {
        visitado[i] = false;
    }
    
    for (int i = 0; i < grafo -> A; i++) {
        arestaVisitada[i] = false;
    }
    
    DFS(N, visitado, grafo, arestaVisitada);
    
    int movimentos = 0;
    
    for (int i = 0; i < grafo -> A; i++) {
        if (arestaVisitada[i]) {
            movimentos++;
        }
    }
    
    free(visitado);
    free(arestaVisitada);
    
    return movimentos * 2;
}

int main() {
    int T, N, V, A;
    int origem, final;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        scanf("%d %d", &V, &A);
        
        Grafo* grafo = criarGrafo(V, A);
        
        for (int j = 0; j < A; j++) {
            scanf("%d %d", &origem, &final);
            grafo -> arestas[j].origem = origem;
            grafo -> arestas[j].final = final;
        }
        
        int movimentos = calcularMinMovimentos(grafo, N);
        printf("%d\n", movimentos);
        
        free(grafo -> arestas);
        free(grafo);
    }
    
    return 0;
}
