//Nicolas Ramos da Silva 178197

#include <stdio.h>
#include <string.h>

char digitos[10][5][4] = {
    {"***", "* *", "* *", "* *", "***"}, // 0
    {"  *", "  *", "  *", "  *", "  *"}, // 1
    {"***", "  *", "***", "*  ", "***"}, // 2
    {"***", "  *", "***", "  *", "***"}, // 3
    {"* *", "* *", "***", "  *", "  *"}, // 4
    {"***", "*  ", "***", "  *", "***"}, // 5
    {"***", "*  ", "***", "* *", "***"}, // 6
    {"***", "  *", "  *", "  *", "  *"}, // 7
    {"***", "* *", "***", "* *", "***"}, // 8
    {"***", "* *", "***", "  *", "***"}  // 9
};

int reconhecer_digito(char entrada[5][4]) {
    for (int d = 0; d < 10; d++) {
        int igual = 1;
        for (int i = 0; i < 5; i++) {
            if (strcmp(entrada[i], digitos[d][i]) != 0) {
                igual = 0;
                break;
            }
        }
        if (igual) return d;
    }
    return -1;
}

int main() {
    char entrada[5][101];
    for (int i = 0; i < 5; i++) {
        fgets(entrada[i], sizeof(entrada[i]), stdin);
    }

    int tamanho = (strlen(entrada[0]) + 1) / 4;
    int numero = 0;
    int valido = 1;

    for (int d = 0; d < tamanho; d++) {
        char digito_ascii[5][4];
        for (int i = 0; i < 5; i++) {
            strncpy(digito_ascii[i], &entrada[i][d * 4], 3);
            digito_ascii[i][3] = '\0';
        }

        int digito = reconhecer_digito(digito_ascii);
        if (digito == -1) {
            valido = 0;
            break;
        }
        numero = numero * 10 + digito;
    }

    if (valido && numero > 0 && numero % 6 == 0) {
        printf("BEER!!\n");
    } else {
        printf("BOOM!!\n");
    }

    return 0;
}
