/* P1.c */
/* Murillo Rodrigues Gonçalves */
/* 11811EBI001 */

#include <stdio.h>
int main ()
{
	int estad = 0, j = 0;
	char bits [256];
	printf ("Digite o numero binario para ver se eh multipo de 3: \n");
	fgets (bits, 256, stdin);
	while (bits[j] != '\0')
	{
		if (estad == 0 && bits [j] == '0')
			estad = 0;
		else if (estad ==0 && bits [j]=='1')
			estad = 1;
		else if (estad == 1 && bits [j] == '1')
			estad = 0;
		else if (estad== 1 && bits [j]== '0')
			estad = 2;
		else if (estad == 2 && bits [j] == '0')
			estad = 1;
		else if (estad == 2 && bits [j] == '1')
			estad = 2;
		j++;
	}

	printf ("Sequencia original: %s\n", bits);
	if (estad == 0)
		printf ("Eh multiplo de 3");
	else
		printf ("Nao eh");

	return 0;
}
