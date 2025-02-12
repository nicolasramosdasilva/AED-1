//Nicolas Ramos da Silva 178197
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct equacao {
    char conta[1000];
    struct equacao *proximo;
} equacao;

equacao* addequa(char *conta) {
    equacao* novo = (equacao*) malloc(sizeof(equacao));
    strcpy(novo->conta, conta);
    novo->proximo = NULL;
    return novo;
}

int checar(equacao *cabeca) {
    equacao *atual = cabeca;
    char tudo[1000];
    strcpy(tudo, atual->conta);
    int a = 0;
    for (int i = 0; i < strlen(tudo); i++) {
        if (tudo[i] == '(')
            a = a + 1;
        else if (tudo[i] == ')')
            a = a - 1;
        if (a < 0) {
            return 0;
        }
    }
    return a == 0;
}

void freeM(equacao *cabeca) {
    equacao *atual = cabeca;
    while (atual != NULL) {
        equacao *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    equacao *cabeca = NULL, *atual = NULL;
    char conta[1000];

    while (fgets(conta, 1000, stdin) != NULL) {
        conta[strcspn(conta, "\n")] = '\0';

        equacao *novaEquacao = addequa(conta);
        if (cabeca == NULL) {
            cabeca = novaEquacao;
            atual = cabeca;
        } else {
            atual->proximo = novaEquacao;
            atual = novaEquacao;
        }

        if (checar(novaEquacao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    freeM(cabeca);
    return 0;
}
