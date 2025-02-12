//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Eachianos I feito em 09/02 para estudo

#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 10001
#define MAX_PALAVRA 51

int main() {
    char texto[MAX_TEXTO], palavra[MAX_PALAVRA];
    int n, posicoes[MAX_TEXTO], contador = 0;

    // Lê a linha de texto
    fgets(texto, sizeof(texto), stdin);

    // Lê o número de palavras a serem pesquisadas
    scanf("%d", &n);
    getchar(); // Consome a quebra de linha restante

    // Processa cada palavra a ser buscada
    while (n--) {
        scanf("%s", palavra);
        
        int tamanhoTexto = strlen(texto);
        int tamanhoPalavra = strlen(palavra);
        contador = 0;

        // Percorre o texto procurando ocorrências da palavra
        for (int i = 0; i <= tamanhoTexto - tamanhoPalavra; i++) {
            if ((i == 0 || texto[i - 1] == ' ') && 
                strncmp(&texto[i], palavra, tamanhoPalavra) == 0 &&
                (texto[i + tamanhoPalavra] == ' ' || texto[i + tamanhoPalavra] == '\0' || texto[i + tamanhoPalavra] == '\n')) {
                
                posicoes[contador++] = i;
            }
        }

        // Imprime as posições encontradas ou -1 se não houver ocorrências
        if (contador == 0) {
            printf("-1");
        } else {
            for (int i = 0; i < contador; i++) {
                printf("%d", posicoes[i]);
                if (i < contador - 1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
