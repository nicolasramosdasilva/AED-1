//Nicolas Ramos da Silva 178197
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

typedef struct {
    int x, y;
} Posicao;

int movimentosX[] = {2, 2, 1, 1, -1, -1, -2, -2};
int movimentosY[] = {1, -1, 2, -2, 2, -2, 1, -1};

int valido(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int bfs(Posicao inicio, Posicao fim) {
    int visitado[N][N];
    memset(visitado, 0, sizeof(visitado));
    
    Posicao fila[N*N];
    int frente = 0, traseira = 0;
    
    fila[traseira++] = inicio;
    visitado[inicio.x][inicio.y] = 1;
    
    while (frente < traseira) {
        Posicao atual = fila[frente++];
        
        if (atual.x == fim.x && atual.y == fim.y) {
            return visitado[atual.x][atual.y] - 1;
        }
        
        for (int i = 0; i < 8; i++) {
            int novoX = atual.x + movimentosX[i];
            int novoY = atual.y + movimentosY[i];
            
            if (valido(novoX, novoY) && !visitado[novoX][novoY]) {
                visitado[novoX][novoY] = visitado[atual.x][atual.y] + 1;
                fila[traseira++] = (Posicao){novoX, novoY};
            }
        }
    }
    
    return -1; // Caso nunca chegue ao destino (não deveria ocorrer em um tabuleiro de xadrez)
}

int main() {
    char origem[3], destino[3];
    
    while (scanf("%2s %2s", origem, destino) == 2) {
        Posicao inicio = {origem[0] - 'a', origem[1] - '1'};
        Posicao fim = {destino[0] - 'a', destino[1] - '1'};
        
        int movimentos = bfs(inicio, fim);
        
        printf("To get from %s to %s takes %d knight moves.\n", origem, destino, movimentos);
    }
    
    return 0;
}
