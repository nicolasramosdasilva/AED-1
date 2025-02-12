#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);

        char produtos[M][51];
        float precos[M];

        for (int j = 0; j < M; j++) {
            scanf("%s", produtos[j]);
            scanf("%f", &precos[j]);
        }

        int P;
        scanf("%d", &P);

        float total = 0.0;
        for (int j = 0; j < P; j++) {
            char produto[51];
            int quantidade;
            scanf("%s %d", produto, &quantidade);

            for (int k = 0; k < M; k++) {
                if (strcmp(produto, produtos[k]) == 0) {
                    total += precos[k] * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2f\n", total);
    }

    return 0;
}
