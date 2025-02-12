//Nicolas Ramos da Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    char cor[10];
    char tamanho;
} Camiseta;

 
int compara(const void *a, const void *b) {
    Camiseta *camisetaA = (Camiseta *)a;
    Camiseta *camisetaB = (Camiseta *)b;

    
    int corCmp = strcmp(camisetaA->cor, camisetaB->cor);
    if (corCmp != 0) {
        return corCmp;
    }

   
    if (camisetaA->tamanho != camisetaB->tamanho) {
        return camisetaB->tamanho - camisetaA->tamanho;
    }

    
    return strcmp(camisetaA->nome, camisetaB->nome);
}

int main() {
    int n;
    int firstCase = 1;

    while (1) {
        
        scanf("%d", &n);
        if (n == 0) break;  

        Camiseta camisetas[n];

       
        for (int i = 0; i < n; i++) {
            getchar(); // Consumir quebra de linha
            fgets(camisetas[i].nome, 51, stdin);
            camisetas[i].nome[strcspn(camisetas[i].nome, "\n")] = 0;  
            scanf("%s %c", camisetas[i].cor, &camisetas[i].tamanho);
        }

       
        qsort(camisetas, n, sizeof(Camiseta), compara);

        
        if (!firstCase) {
            printf("\n");
        }
        firstCase = 0;

        
        for (int i = 0; i < n; i++) {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }

    return 0;
}
