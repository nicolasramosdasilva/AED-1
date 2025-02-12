//Nicolas Ramos da Silva 178197

#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>   

//Define o número máximo de itens em uma lista de compras
#define MAX_ITENS 1000       
//Define o tamanho máximo para cada item (máximo de 20 caracteres + terminador de string)
#define MAX_TAM_ITEM 21     


// Função de comparação para strings, usada para ordenar os itens em ordem alfabética
int comparaStrings(const void *a, const void *b) {
    // Converte os ponteiros para strings e usa strcmp para comparar as strings
    return strcmp(*(const char **)a, *(const char **)b);
}

// Função para remover itens duplicados de uma lista já ordenada
int removeDuplicados(char *itens[], int n) {
    int j = 0; // Índice para armazenar os itens únicos na lista
    for (int i = 1; i < n; i++) {  // Começa do segundo item, já que o primeiro é sempre único
        // Compara o item atual com o último item único
        if (strcmp(itens[j], itens[i]) != 0) {
            j++;                    // Incrementa o índice de itens únicos
            itens[j] = itens[i];    // Atualiza o próximo item único
        }
    }
    return j + 1; // Retorna o novo tamanho da lista com itens únicos
}

int main() {
    int n; // Quantidade de listas de compras a serem lidas
    scanf("%d", &n); // Lê o número de listas de compras
    getchar(); // Limpa o buffer de nova linha deixado pelo scanf

    for (int i = 0; i < n; i++) { // Loop para processar cada lista de compras
        char linha[10000]; // Buffer para armazenar a linha inteira com os itens da lista de compras
        fgets(linha, sizeof(linha), stdin); // Lê a linha completa contendo os itens da lista de compras

        // Remove o caractere de nova linha ao final da entrada, se houver
        linha[strcspn(linha, "\n")] = '\0';

        // Vetor de ponteiros para armazenar cada item individual da lista
        char *itens[MAX_ITENS];
        int numItens = 0; // Inicializa o número de itens na lista

        // Usa strtok para dividir a linha em itens, separados por espaço
        char *token = strtok(linha, " ");
        while (token != NULL) {         // Continua enquanto houver itens na linha
            itens[numItens] = token;    // Armazena o item atual no vetor de itens
            numItens++;                 // Incrementa o número de itens
            token = strtok(NULL, " ");  // Vai para o próximo item
        }

        // Ordena os itens em ordem alfabética usando a função qsort
        qsort(itens, numItens, sizeof(char *), comparaStrings);

        // Remove os itens duplicados da lista ordenada
        numItens = removeDuplicados(itens, numItens);

        // Imprime a lista de compras sem duplicados e em ordem alfabética
        for (int j = 0; j < numItens; j++) {
            printf("%s", itens[j]);        // Imprime o item atual
            if (j < numItens - 1) {        // Se não for o último item, imprime um espaço
                printf(" ");
            }
        }
        printf("\n"); // Nova linha para a próxima lista
    }

    return 0; // Indica que o programa terminou com sucesso
}
