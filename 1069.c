#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001

int contar_diamantes(const char *linha) {
    int pilha = 0, diamantes = 0;

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            pilha++;
        } else if (linha[i] == '>' && pilha > 0) {
            pilha--; 
            diamantes++;
        }
    }

    return diamantes;
}

int main() {
    int N;
    char linha[MAX_LENGTH];

    scanf("%d", &N);
    getchar(); 

    for (int i = 0; i < N; i++) {
        fgets(linha, MAX_LENGTH, stdin);
        
        linha[strcspn(linha, "\n")] = '\0';

        int resultado = contar_diamantes(linha);
        printf("%d\n", resultado);
    }

    return 0;
}
