#include <stdio.h>

#define MOD 1000000007

// Função para calcular o número de maneiras de descer a escada
long long countWays(int N) {
    if (N == 1) return 1;
    if (N == 2) return 2;
    if (N == 3) return 4;

    long long a = 1, b = 2, c = 4, d;

    for (int i = 4; i <= N; i++) {
        d = (a + b + c) % MOD;
        a = b;
        b = c;
        c = d;
    }

    return c;
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%lld\n", countWays(N));
    
    return 0;
}
