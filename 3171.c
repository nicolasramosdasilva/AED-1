//Nicolas Ramos da Silva 178197


#include <stdio.h>
#include <stdbool.h>

#define MAX 101

void dfs(int grafo[MAX][MAX], bool visitado[MAX], int v, int N) {
    visitado[v] = true;
    for (int i = 1; i <= N; i++) {
        if (grafo[v][i] && !visitado[i]) {
            dfs(grafo, visitado, i, N);
        }
    }
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    int grafo[MAX][MAX] = {0};
    bool visitado[MAX] = {false};

    for (int i = 0; i < L; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        grafo[X][Y] = 1;
        grafo[Y][X] = 1;
    }

    dfs(grafo, visitado, 1, N);

    bool completo = true;
    for (int i = 1; i <= N; i++) {
        if (!visitado[i]) {
            completo = false;
            break;
        }
    }

    printf("%s\n", completo ? "COMPLETO" : "INCOMPLETO");

    return 0;
}
