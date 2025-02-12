//Nicolas Ramos da Silva 178197
#include <stdio.h>
#include <string.h>

void inserirAmigos(char lista[][20], int *t, char novosAmigos[][20], int nnamigos, int p) {
    for (int i = *t - 1; i >= p; i--) {
        strcpy(lista[i + nnamigos], lista[i]);
    }
    for (int i = 0; i < nnamigos; i++) {
        strcpy(lista[p + i], novosAmigos[i]);
    }
    *t += nnamigos;
}

int main() {
    char lista[100][20], novosAmigos[100][20], onde[20];
    int tlista = 0, Tna = 0;

    while (scanf("%s", lista[tlista]) == 1) {
        tlista++;
        if (getchar() == '\n') break;
    }

    while (scanf("%s", novosAmigos[Tna]) == 1) {
        Tna++;
        if (getchar() == '\n') break;
    }

    scanf("%s", onde);

    int p = -1;
    if (strcmp(onde, "nao") != 0) {
        for (int i = 0; i < tlista; i++) {
            if (strcmp(lista[i], onde) == 0) {
                p = i;
                break;
            }
        }
    }

    if (p != -1) {
        inserirAmigos(lista, &tlista, novosAmigos, Tna, p);
    } else {
        inserirAmigos(lista, &tlista, novosAmigos, Tna, tlista);
    }

    for (int i = 0; i < tlista; i++) {
        printf("%s", lista[i]);
        if (i < tlista - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
