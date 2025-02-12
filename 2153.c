//Nicolas Ramos da Silva 178197
#include <stdio.h>
#include <string.h>

#define TAM_MAX 31

int temRep(char *str, int ini, int tam) {
    int len = strlen(str);
    if (ini + tam > len) return 0;
    
    for (int i = 0; i < tam; i++) {
        if (str[ini + i] != str[len - tam + i]) {
            return 0;
        }
    }
    return 1;
}

void corrige(char *pal) {
    int len = strlen(pal);
    
    for (int t = 1; t <= len/2; t++) {
        if (temRep(pal, len - t * 2, t)) {
            pal[len - t] = '\0';
            return;
        }
    }
}

int main() {
    char pal[TAM_MAX];
    
    while (scanf("%s", pal) != EOF) {
        corrige(pal);
        printf("%s\n", pal);
    }
    
    return 0;
}
