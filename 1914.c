

#include <stdio.h>

// Estrutura para armazenar nome e escolha do jogador
typedef struct {
    char nome[50];
    char escolha[10];
} Jogador;

int main() {
    int numTestes, valor1, valor2;
    
    // Lê o número de casos de teste
    scanf("%d", &numTestes);

    // Loop para processar cada caso de teste
    while (numTestes--) {
        Jogador jogador1, jogador2;

        // Lê os nomes e escolhas dos jogadores
        scanf("%s %s %s %s", jogador1.nome, jogador1.escolha, jogador2.nome, jogador2.escolha);
        
        // Lê os valores escolhidos pelos jogadores
        scanf("%d %d", &valor1, &valor2);
        
        // Determina o vencedor com base na soma e na escolha (PAR/IMPAR)
        int soma = valor1 + valor2;
        char *vencedor = (soma % 2 == 0) ? (strcmp(jogador1.escolha, "PAR") == 0 ? jogador1.nome : jogador2.nome)
                                          : (strcmp(jogador1.escolha, "IMPAR") == 0 ? jogador1.nome : jogador2.nome);
        
        // Exibe o vencedor
        printf("%s\n", vencedor);
    }

    return 0;
}
