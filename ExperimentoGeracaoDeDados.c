#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void fillArray(int arr[], int n);

// Função para calcular o tempo médio
double measureTime(void (*sortFunction)(int[], int), int arr[], int n, int iterations) {
    double totalTime = 0;
    int *copy = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < iterations; i++) {
        fillArray(arr, n);
        for (int j = 0; j < n; j++) copy[j] = arr[j];

        clock_t start = clock();
        sortFunction(copy, n);
        clock_t end = clock();

        totalTime += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    free(copy);
    return totalTime / iterations;
}

int main() {
    int nValues[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
    int numTests = sizeof(nValues) / sizeof(nValues[0]);
    int iterations = 3;

    int *arr = (int *)malloc(nValues[numTests - 1] * sizeof(int));

    printf("n,InsertionSort,MergeSort\n");
    for (int i = 0; i < numTests; i++) {
        int n = nValues[i];
        double timeInsertion = measureTime(insertionSort, arr, n, iterations);
        double timeMerge = measureTime(mergeSort, arr, n, iterations);

        printf("%d,%f,%f\n", n, timeInsertion, timeMerge);
    }

    free(arr);
    return 0;
}
