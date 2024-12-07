#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função InsertionSort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função auxiliar para preencher vetor com valores aleatórios
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// Função principal para testar o InsertionSort
int main() {
    int n = 100000; // Ajuste conforme necessário
    int *arr = (int *)malloc(n * sizeof(int));
    fillArray(arr, n);

    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("InsertionSort levou %f segundos para ordenar %d elementos.\n", time_taken, n);

    free(arr);
    return 0;
}
