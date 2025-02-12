//Nicolas Ramos da Silva 178197
#include <stdio.h>

void formatar_moeda(long long dolares, int centavos) {
    char resultado[50]; 
    int i = 0, j, count = 0;

     
    if (dolares == 0) {
        printf("$0.%02d\n", centavos);
        return;
    }

    
    long long temp = dolares;
    int num_digitos = 0;
    do {
        num_digitos++;
        temp /= 10;
    } while (temp > 0);

    int tam_formatado = num_digitos + (num_digitos - 1) / 3; 
    resultado[tam_formatado] = '\0';  
 
    while (dolares > 0) {
        if (count == 3) {
            resultado[--tam_formatado] = ',';
            count = 0;
        }
        resultado[--tam_formatado] = (dolares % 10) + '0';
        dolares /= 10;
        count++;
    }

     
    printf("$%s.%02d\n", resultado, centavos);
}

int main() {
    long long dolares;
    int centavos;

    while (scanf("%lld %d", &dolares, &centavos) == 2) {
        formatar_moeda(dolares, centavos);
    }

    return 0;
}
