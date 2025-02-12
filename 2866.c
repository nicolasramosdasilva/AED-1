//Nicolas Ramos da Silva 178197

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main ()
{

	char palavra[101], saida[101];
	unsigned short casos, i, j, tamanho;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s", palavra);

		tamanho = strlen(palavra);

		i = tamanho - 1;
		j = 0;


		while (tamanho--)
		{

			if (islower(palavra[i]))
				saida[j++] = palavra[i--];
			else
				i--;
		}

		saida[j] = '\0';
		printf("%s\n", saida);
	}
}
