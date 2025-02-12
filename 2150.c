//Nicolas Ramos da Silva 178197
#include <stdio.h>
#include <string.h>



int main() {
    char vogais[100], texto[1000];
    
    while (scanf("%s", vogais) != EOF) {
        getchar(); 
        fgets(texto, 1000, stdin);
        
        int c = 0;
        for (int i = 0; texto[i] != '\0'; i++) {
            for (int j = 0; vogais[j] != '\0'; j++) {
                if (texto[i] == vogais[j]) {
                    c++;
                    break;
                }
            }
        }
        
        printf("%d\n", c);
    }
    
    return 0;
}
