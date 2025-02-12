#include <stdio.h>
#include <limits.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        long long D;
        int I, B;
        scanf("%lld %d %d", &D, &I, &B);

        int preco_ingrediente[I];
        for (int i = 0; i < I; i++) {
            scanf("%d", &preco_ingrediente[i]);
        }

        int max_bolos = 0;

        for (int b = 0; b < B; b++) {
            int Q;
            scanf("%d", &Q);

            long long custo_bolo = 0;
            for (int q = 0; q < Q; q++) {
                int ingrediente, quantidade;
                scanf("%d %d", &ingrediente, &quantidade);
                custo_bolo += (long long)preco_ingrediente[ingrediente] * quantidade;
            }

            if (custo_bolo > 0) {
                int bolos_possiveis = D / custo_bolo;
                if (bolos_possiveis > max_bolos) {
                    max_bolos = bolos_possiveis;
                }
            }
        }

        printf("%d\n", max_bolos);
    }

    return 0;
}
