//Nicolas Ramos da Silva 178197
#include <stdio.h>
#include <string.h>

void p1(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || 
           (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] = str[i] + 3;
        }
    }
}

void p2(char *str) {
    int tam = strlen(str);
    char aux;
    for(int i = 0; i < tam/2; i++) {
        aux = str[i];
        str[i] = str[tam-1-i];
        str[tam-1-i] = aux;
    }
}


void p3(char *str) {
    int tam = strlen(str);
    int meio = tam/2;
    for(int i = meio; i < tam; i++) {
        str[i] = str[i] - 1;
    }
}

int main() {
    int N;
    char linha[1001];
    
    scanf("%d\n", &N);
    
    for(int i = 0; i < N; i++) {
       
        fgets(linha, 1001, stdin);
        
        int tam = strlen(linha);
        if(linha[tam-1] == '\n') {
            linha[tam-1] = '\0';
            tam--;
        }
       
        p1(linha);
        p2(linha);
        p3(linha);
        
        printf("%s\n", linha);
    }
    
    return 0;
}
