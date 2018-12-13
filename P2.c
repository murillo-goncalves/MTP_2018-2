/*P2.c*/
/* Murillo Gonçalves */
/* 11811EBI001 */

#include <stdio.h>

void trocar (char vet[])
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

int potenciacao (int num, int num2)
{
	int i, pot=1;
	for (i=0; i<num2; i++)
		pot *= num;
	return pot;
}

int b__p (char vet[])
{
	int i, soma = 0;
	trocar(vet);
	for (i=0; vet[i] != '\0'; i++)
	{
		if (vet[i]=='1')
			soma = soma + vet[i] * potenciacao(2,i);
	}
	return soma/49;
}

int decbin (int num)
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

int main()
{
	char aux[256];
	int op, num;
		printf ("TABELA DE CONVERSAO \n\nMENU DE OPCOES: \n\n");
		printf ("Digite para converter:\n\n1. Binario para decimal\n2. Binario para hexadecimal\n3. Hexadecimal para decimal\n4. Hexadecimal para binario\n5. Decimal para binario\n6. Decimal para hexadecimal\n7. Octal para decimal\n8. Decimal para octal\n\n");
		scanf ("%d", &op);
		switch (op)
		{
			case 1:
				printf ("\nDigite o numero binario: ");
				scanf ("%s", &aux[0]);
				printf("\nEm decimal: %d", b__p(aux));
				break;
			case 2:
				printf ("\nDigite o numero binario: ");
				scanf ("%s", &aux[0]);
				printf ("\nEm hexadecimal: %x", b__p(aux));
				break;
			case 3:
				printf ("\nDigite o numero hexadecimal: ");
				scanf ("%x", &num);
				printf ("\n em decimal ele eh %d.", num);
				break;
			case 4: 
				printf ("\nDigite o numero hexadecimal: ");
				scanf ("%x", &num);
				decbin(num);
				break;
			case 5:
				printf ("\nDigite o numero decimal: ");
				scanf ("%d", &num);
				decbin(num);
				break;
			case 6:
				printf ("\nDigite o numero decimal: ");
				scanf ("%d", &num);
				printf ("\n Em hexadecimal: %x", num);
				break;
			case 7:
				printf ("\nDigite o numero octal: ");
				scanf ("%o", &num);
				printf ("\n Em decimal: %d", num);
				break;
			case 8:
				printf ("\nDigite o numero decimal: ");
				scanf ("%d", &num);
				printf ("\n Em octal: %o", num);
				break;
			default:
				printf ("\nOpcao invalida.");
		}
	return 0;
}
