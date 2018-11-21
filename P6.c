/* P6.c */
/* MURILLO RODRIGUES GONÇALVES */
/* 11811EBI001 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct
{
  double x, y;
}ponto;



ponto *criar(int n_pontos)
{
	int j;
	ponto *p = (ponto*) malloc(n_pontos*sizeof(ponto));
	for(j = 0; j < n_pontos; j++)
	{
		p->y = sin(j * 2.0 * M_PI / (n_pontos - 1));
		p->x = cos(j * 2.0 * M_PI / (n_pontos - 1));
		printf("(%.3lf, %.3lf)\n", p->x, p->y);
	}
	return p;
}



int main()
{
	int n_pontos;
	ponto *p;
	printf("Digite a quantidade de pontos que deseja dividir igualmente o circulo trignometrico: ");
	scanf("%i", &n_pontos); 
	getchar();
	p = criar(n_pontos);
	free(p);
	return 0;
}

