//Nicolas Ramos da Silva 178197
#include <stdio.h>
 
int main() {
 
    int idade, anos, meses, dias;
    scanf ("%d", &idade);
    anos = idade / 365;
    meses = idade - (365 * anos);
    meses = meses / 30;
    dias = idade - (365 * anos) - (30 * meses);
    printf ("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
   
}
