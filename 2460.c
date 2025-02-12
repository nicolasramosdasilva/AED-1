//Nicolas Ramos da Silva 178197

#include <stdio.h>
#include <stdlib.h>

#define MAX 50000
#define MAX_ID 100001 // Ajustado para cobrir identificadores até 100000

int main() {
    int N, M, i, primeiro = 1; // Flag para controle de espaço
    int fila[MAX], removidos[MAX];
    int presentes[MAX_ID] = {0}; // Vetor aumentado para evitar acessos inválidos
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
        if (fila[i] < MAX_ID) { // Garantia de acesso válido
            presentes[fila[i]] = 1; // Marca como presente inicialmente
        }
    }
    
    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &removidos[i]);
        if (removidos[i] < MAX_ID) { // Garantia de acesso válido
            presentes[removidos[i]] = 0; // Marca como removido
        }
    }
    
    for (i = 0; i < N; i++) {
        if (fila[i] < MAX_ID && presentes[fila[i]]) { // Verificação antes de imprimir
            if (!primeiro) {
                printf(" "); // Adiciona espaço entre os números
            }
            printf("%d", fila[i]); // Imprime sem espaço extra no final
            primeiro = 0;
        }
    }
    printf("\n"); // Garante que a saída termina corretamente
    
    return 0;
}
