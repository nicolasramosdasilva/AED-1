//Nicolas Ramos da Silva 178197
#include <stdio.h>

int main()
{
    int i, j=0, lnth;
    char x[60], y[60];
    scanf("%s", x);
    for(i=0; x[i]; i++)
    {
        if(x[i]=='a' || x[i]=='e' || x[i]=='i' || x[i]=='o' || x[i]=='u')
        {
            y[j] = x[i];
            j++;
        }
    }
    y[j] = '\0';
    lnth = strlen(y);
    for(i=0, j=lnth-1; i < lnth; i++, j--)
    {
        if(y[i] != y[j])
        {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}
