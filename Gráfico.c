#include <stdio.h>
#include <stdlib.h>

// Dados fictícios para o gráfico
double n_values[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
double insertion_times[] = {1.23, 4.98, 11.22, 19.98, 31.32, 44.56, 60.98, 79.43};
double merge_times[] = {0.05, 0.11, 0.17, 0.24, 0.33, 0.42, 0.53, 0.65};

// Função para salvar os dados em um arquivo
void save_data_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "# n_values InsertionSort MergeSort\n");
    for (int i = 0; i < 8; i++) { // 8 é o tamanho dos arrays
        fprintf(file, "%lf %lf %lf\n", n_values[i], insertion_times[i], merge_times[i]);
    }

    fclose(file);
}

// Função para gerar o script gnuplot
void generate_gnuplot_script(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file,
            "set terminal pngcairo size 800,600\n"
            "set output 'grafico_comparativo.png'\n"
            "set title 'Desempenho: InsertionSort vs MergeSort'\n"
            "set xlabel 'Número de Elementos (n)'\n"
            "set ylabel 'Tempo (segundos)'\n"
            "set grid\n"
            "plot 'dados.txt' using 1:2 with linespoints title 'InsertionSort', \\\n"
            "     'dados.txt' using 1:3 with linespoints title 'MergeSort'\n");

    fclose(file);
}

int main() {
    // Passo 1: Salvar os dados em um arquivo
    save_data_to_file("dados.txt");

    // Passo 2: Gerar o script gnuplot
    generate_gnuplot_script("script.gnuplot");

    // Passo 3: Executar o script gnuplot
    system("gnuplot script.gnuplot");

    printf("Gráfico gerado: grafico_comparativo.png\n");
    return 0;
}
