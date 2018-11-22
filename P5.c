/* P5.c */
/* MURILLO RODRIGUES GONÇALVES */
/* 11811EBI001 */

#include <stdio.h>

typedef
	unsigned long long int
Bytes8;

typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual;}
LCG;

void semente(LCG * r, Bytes8 seed) 
{
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) 
{
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r) 
{
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r) 
{
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float produto(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor * produto(inicio_vetor + 1, fim_vetor));
	return 1;	
}

float soma(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1) 
		return (*inicio_vetor + soma(inicio_vetor + 1, fim_vetor));
	return 0;
}

int main()
{
	LCG random;
   	semente(&random, 123456);
	
	int flag;
	float n_aleatorios[50];
	
	gera_numeros(n_aleatorios, 50, 0.5, 1.5, &random);
	
	do
	{
		printf ("O computador criou de forma aleatoria 50 numeros. Deseja: \n\n1) Realizar a somatoria? \n2) Realizar o produtorio? \n3) Sair do programa.");
		scanf ("%i", &flag);
		switch (flag)
		{
			case 1:
				printf ("\nSoma: %.6f \n", soma (&n_aleatorios[0], &n_aleatorios[49]));
				break;
			case 2:
				printf ("\nProduto: %g \n", produto (&n_aleatorios[0], &n_aleatorios[49]));
				break;	
			default:
				if (flag != 3)
					printf ("\nOpcao invalida!");
		}	
	} while (flag != 3);
	return 0;
}

