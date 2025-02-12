//Nicolas Ramos da Silva 178197

#include <stdio.h>
#include <string.h>

#define MAX_NODES 52

 
void construirPosOrdem(char *preOrdem, char *inOrdem, char *posOrdem, int *posIndex, int inInicio, int inFim, int *posOrdemIndex) {
    if (inInicio > inFim) {
        return;
    }

    
    char raiz = preOrdem[(*posIndex)++];

     
    int raizIndex;
    for (raizIndex = inInicio; raizIndex <= inFim; raizIndex++) {
        if (inOrdem[raizIndex] == raiz) {
            break;
        }
    }

    
    construirPosOrdem(preOrdem, inOrdem, posOrdem, posIndex, inInicio, raizIndex - 1, posOrdemIndex);

    
    construirPosOrdem(preOrdem, inOrdem, posOrdem, posIndex, raizIndex + 1, inFim, posOrdemIndex);

     
    posOrdem[(*posOrdemIndex)++] = raiz;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int n;
        char preOrdem[MAX_NODES], inOrdem[MAX_NODES], posOrdem[MAX_NODES];
        
        scanf("%d %s %s", &n, preOrdem, inOrdem);

        
        memset(posOrdem, 0, sizeof(posOrdem));
        int posIndex = 0, posOrdemIndex = 0;
 
        construirPosOrdem(preOrdem, inOrdem, posOrdem, &posIndex, 0, n - 1, &posOrdemIndex);

         
        posOrdem[posOrdemIndex] = '\0';

        
        printf("%s\n", posOrdem);
    }

    return 0;
}
