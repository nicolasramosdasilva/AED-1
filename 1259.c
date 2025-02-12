//Nicolas Ramos da Silva 178197
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int impar;
} N;

int compare(const void* a, const void* b) {
    N* nA = (N*)a;
    N* nB = (N*)b;

    if (nA->impar != nB->impar) {
        return nA->impar - nB->impar;
    }

    if (!nA->impar) {
        return nA->value - nB->value;
    }

    return nB->value - nA->value;
}

int main() {
    int X;
    scanf("%d", &X);

    N* numbers = (N*)malloc(X * sizeof(N));

    for (int i = 0; i < X; i++) {
        scanf("%d", &numbers[i].value);
        numbers[i].impar = (numbers[i].value % 2 != 0);
    }

    qsort(numbers, X, sizeof(N), compare);

    for (int i = 0; i < X; i++) {
        printf("%d\n", numbers[i].value);
    }

    free(numbers);

    return 0;
}
