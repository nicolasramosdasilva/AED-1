#include <stdio.h>
#include <string.h>

int fatorial(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    char numero_acm[6];

    while (1) {
        scanf("%s", numero_acm);

        if (strcmp(numero_acm, "0") == 0) {
            break;
        }

        int tamanho = strlen(numero_acm);
        int resultado = 0;

        for (int i = 0; i < tamanho; i++) {
            int digito = numero_acm[i] - '0';
            resultado += digito * fatorial(tamanho - i);
        }

        printf("%d\n", resultado);
    }

    return 0;
}
