    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void insertion_sort(int v[], int N) {
        int i, j, aux;
        for (i = 1; i < N; i++) {
            aux = v[i];
            for (j = i; j > 0 && v[j - 1] > aux; j--) 
                v[j] = v[j - 1];
            
            v[j] = aux;
        }
    }

    void merge(int vetor[], int esq, int meio, int dir) {
        int i, j, k;
        int n1 = meio - esq + 1;
        int n2 = dir - meio;
        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = vetor[esq + i];
        for (j = 0; j < n2; j++)
            R[j] = vetor[meio + 1 + j];

        i = 0;
        j = 0;
        k = esq;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                vetor[k++] = L[i++];
            else
                vetor[k++] = R[j++];
        }

        while (i < n1)
            vetor[k++] = L[i++];

        while (j < n2)
            vetor[k++] = R[j++];
    }

    void merge_sort(int vetor[], int esq, int dir) {
        if (esq < dir) {
            int meio = esq + (dir - esq) / 2;
            merge_sort(vetor, esq, meio);
            merge_sort(vetor, meio + 1, dir);
            merge(vetor, esq, meio, dir);
        }
    }

    void troca(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int dividir(int vetor[], int baixo, int alto) {
        int pivo = vetor[alto];
        int i = (baixo - 1);

        for (int j = baixo; j <= alto - 1; j++) {
            if (vetor[j] <= pivo) {
                i++;
                troca(&vetor[i], &vetor[j]);
            }
        }
        troca(&vetor[i + 1], &vetor[alto]);
        return (i + 1);
    }

    void quick_sort(int vetor[], int baixo, int alto) {
        if (baixo < alto) {
            int pi = dividir(vetor, baixo, alto);
            quick_sort(vetor, baixo, pi - 1);
            quick_sort(vetor, pi + 1, alto);
        }
    }

    // Funções auxiliares
    void gerar_numeros(int vetor[], int tamanho) {
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = rand() % 1000000;  // Números aleatórios de 0 a 999999
        }
    }

    void copiar_vetor(int origem[], int destino[], int tamanho) {
        for (int i = 0; i < tamanho; i++) {
            destino[i] = origem[i];
        }
    }

    double medir_tempo_insertion(void (*algoritmo)(int[], int), int vetor[], int N) {
        clock_t inicio, fim;
        inicio = clock();
        algoritmo(vetor, N);
        fim = clock();
        return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    }

    double medir_tempo_merge_quick(void (*algoritmo)(int[], int, int), int vetor[], int N) {
        clock_t inicio, fim;
        inicio = clock();
        algoritmo(vetor, 0, N - 1);
        fim = clock();
        return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    }

    int main() {
        srand(time(NULL));
        int N;
        printf("Digite a quantidade de números aleatórios a serem gerados: ");
        scanf("%d", &N);

        int vetor_original[N], vetor_aux[N];
        gerar_numeros(vetor_original, N);

        copiar_vetor(vetor_original, vetor_aux, N);  // Medir tempo para Insertion Sort
        double tempo_insertion = medir_tempo_insertion(insertion_sort, vetor_aux, N);

        copiar_vetor(vetor_original, vetor_aux, N);  // Medir tempo para Merge Sort
        double tempo_merge = medir_tempo_merge_quick(merge_sort, vetor_aux, N);

        copiar_vetor(vetor_original, vetor_aux, N);  // Medir tempo para Quick Sort
        double tempo_quick = medir_tempo_merge_quick(quick_sort, vetor_aux, N);

        // Exibir os tempos
        printf("Tempo de execução:\n");
        printf("Insertion Sort: %.6f segundos\n", tempo_insertion);
        printf("Merge Sort: %.6f segundos\n", tempo_merge);
        printf("Quick Sort: %.6f segundos\n", tempo_quick);

        return 0;
    }
