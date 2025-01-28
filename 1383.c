#include <stdio.h>

int verificacao(int mat[9][9]){
    /* verificação das linhas */
    for(int i=0;i<9;i++){
        int linha[10] = {0};
        for(int j=0;j<9;j++){
            int x = mat[i][j];
            if (x < 1 || x > 9 || linha[x] == 1){
                return 0;
            }
            linha[x] = 1; 
            
        }
    }
    /* verificação das colunas */
    for(int j=0;j<9;j++){
        int coluna[10] = {0};
        for(int i=0;i<9;i++){
            int x = mat[i][j];
            if (x < 1 || x > 9 || coluna[x] == 1){
                return 0; 
            }
            coluna[x] = 1;
        }
    }
    /*verificação de blocos*/
    for (int blocoI = 0; blocoI < 3; blocoI++) {
        for (int blocoJ = 0; blocoJ < 3; blocoJ++) {
            int submatriz[10] = {0}; // Array para contar ocorrências de 1 a 9
            for (int i = blocoI * 3; i < (blocoI + 1) * 3; i++) {
                for (int j = blocoJ * 3; j < (blocoJ + 1) * 3; j++) {
                    int x = mat[i][j];
                    if (x < 1 || x > 9 || submatriz[x] == 1) {
                        return 0; // Número inválido ou repetido na submatriz
                    }
                    submatriz[x] = 1; // Marca o número como encontrado
                }
            }
        }
    }
    return 1;
}

int main(){
    int n;
    int mat[9][9];
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        printf("Instancia %d \n", i + 1);
        if (verificacao(mat) == 1) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }
    return 0;
}
