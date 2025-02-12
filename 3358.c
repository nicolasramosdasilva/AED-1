//Nicolas Ramos da Silva 178197

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 43

int eh_consoante(char c) {
    c = tolower(c);
    return c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || 
           c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || 
           c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w' || 
           c == 'x' || c == 'y' || c == 'z';
}

int eh_dificil(char *sobrenome) {
    int cont_consoantes = 0;
    for (int i = 0; sobrenome[i] != '\0'; i++) {
        if (eh_consoante(sobrenome[i])) {
            cont_consoantes++;
            if (cont_consoantes == 3) {
                return 1; // nao eh facil
            }
        } else {
            cont_consoantes = 0;
        }
    }
    return 0; // eh facil
}

int main() {
    int num_casos;
    scanf("%d", &num_casos);

    char sobrenome[TAM_MAX];
    for (int i = 0; i < num_casos; i++) {
        scanf("%s", sobrenome);

        if (eh_dificil(sobrenome)) {
            printf("%s nao eh facil\n", sobrenome);
        } else {
            printf("%s eh facil\n", sobrenome);
        }
    }

    return 0;
}
