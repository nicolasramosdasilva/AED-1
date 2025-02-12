

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool ja_usado(char *str, int inicio, int atual) {
    for (int i = inicio; i < atual; i++) {
        if (str[i] == str[atual]) {
            return true;
        }
    }
    return false;
}

void ordenar_substring(char *str, int inicio) {
    int len = strlen(str);
    for (int i = inicio; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                trocar(&str[i], &str[j]);
            }
        }
    }
}

void gerar_permutacoes(char *str, int pos) {
    if (pos == strlen(str)) {
        printf("%s\n", str);
        return;
    }
    
    for (int i = pos; i < strlen(str); i++) {
        if (i != pos && ja_usado(str, pos, i)) continue;
        
        trocar(&str[pos], &str[i]);
        ordenar_substring(str, pos + 1); 
        gerar_permutacoes(str, pos + 1);
        ordenar_substring(str, pos + 1); 
        trocar(&str[pos], &str[i]);
    }
}

void ordenar_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                trocar(&str[i], &str[j]);
            }
        }
    }
}

int main() {
    int n;
    char str[11]; 
    
    scanf("%d", &n);
    getchar(); 
    
    while (n--) {
        scanf("%s", str);
        ordenar_string(str); 
        gerar_permutacoes(str, 0);
        printf("\n"); 
    }
    
    return 0;
}
