/*P2.c*/
/* Murillo Rodrigues Gonçalves */
/* 11811EBI001 */

#include <stdio.h>

void inv (char vet[])
{
	int i, j, flag = 0, aux;
	for(i = 0; vet[i] != '\0'; i++, flag++);
	j = flag - 1;
	for(i = 0; i < j; i++, j--){
		aux = vet[i];
		vet[i] = vet[j];
		vet[j] = aux;
	}
	vet[flag] = '\0';
}

int exp (int num, int num2)
{
	int i, pot=1;
	for (i=0; i<num2; i++)
		pot *= num;
	return pot;
}



int decimalbinario (int num)
{
	int i, flag = 0, vet[256], j;
	j = num;
	for(i = 0; flag < 1; i++)
	{
		vet[i] = j % 2;
		j=j/2;
		if(j == 0 || j == 1)
		{
			vet[i + 1] = j;
			j = i + 1;
			flag++;
		}
	}
	printf("\n Em binario ele eh ");
	for(j; j >= 0; j--){
		printf("%d", vet[j]);
	}
}

int binariodecimal (char vet[])
{
	int i, soma = 0;
	inv(vet);
	for (i=0; vet[i] != '\0'; i++)
	{
		if (vet[i]=='1')
			soma = soma + vet[i] * exp(2,i);
	}
	return soma/49;
}


int main()
{
	char str[256];
	int x, y;
		printf ("TABELA DE CONVERSAO\nMENU DE OPCOES\n\nDIGITE PARA CONVERTER:\n\n1 - BINARIO PARA DECIMAL\n2 - BINARIO PARA HEXADECIMAL\n3 - HEXADECIMAL PARA DECIMAL\n4 - HEXADECIMAL PARA BINARIO\n5 - DECIMAL PARA BINARIO\n6 - DECIMAL PARA HEXADECIMAL\n7 - OCTAL PARA DECIMAL\n8 - DECIMAL PARA OCTAL\n\n");
		scanf ("%d", &x);
		switch (x)
		{
			case 1:
				printf ("\nDigite o numero binario: ");
				scanf ("%s", &str[0]);
				printf("\nEm decimal ele eh %d", binariodecimal(str));
				break;
			case 2:
				printf ("\nDigite o numero binario: ");
				scanf ("%s", &str[0]);
				printf ("\nEm hexadecimal ele eh %x", binariodecimal(str));
				break;
			case 3:
				printf ("\nDigite o numero hexadecimal: ");
				scanf ("%x", &y);
				printf ("\n em decimal ele eh %d.", y);
				break;
			case 4: 
				printf ("\nDigite o numero hexadecimal: ");
				scanf ("%x", &y);
				decimalbinario(y);
				break;
			case 5:
				printf ("\nDigite o numero decimal: ");
				scanf ("%d", &y);
				decimalbinario(y);
				break;
			case 6:
				printf ("\nDigite o numero decimal: ");
				scanf ("%d", &y);
				printf ("\n Em hexadecimal ele eh %x", y);
				break;
			case 7:
				printf ("\nDigite o numero octal: ");
				scanf ("%o", &y);
				printf ("\n Em decimal ele eh %d", y);
				break;
			case 8:
				printf ("\nDigite o numero decimal: ");
				scanf ("%d", &y);
				printf ("\n Ele em octal eh %o", y);
				break;
			default:
				printf ("\nOpcao invalida.");
		}
	return 0;
}
