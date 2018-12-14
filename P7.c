/* P7.c */
/* MURILLO RODRIGUES GONÇALVES */
/* 11811EBI001 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct ponto
{
	double x, y;
};



struct ponto *criar(int n_pontos)
{
	int j;
	struct ponto *p = (struct ponto*) malloc(n_pontos*sizeof(struct ponto));
	for(j = 0; j < n_pontos; j++)
	{
		p[j].y = sin(j * 2.0 * M_PI / (n_pontos - 1));
		p[j].x = cos(j * 2.0 * M_PI / (n_pontos - 1));
	//	printf("(%.3lf, %.3lf)\n", p->x, p->y);
	}
	return p;
}

void save (struct ponto *p, int n_pontos)
{
	FILE *arq;
	arq = fopen("pontos.dat", "w");
	
	
	int i, j;
	for(i = 0; i < n_pontos; i++) 
	{
        for(j = 0; j < 20; j++) 
		{
            fprintf(arq, "%d\t%d\t\t", p[i].x, p[i].y);
        }    
        fprintf(arq, "\n");
    }
    
    fclose(arq);
}


void arquivo (struct ponto *p, int n_pontos)
{
    FILE * arq;
    arq = fopen("pontos.dat", "wb");
    fwrite (p, n_pontos, sizeof(struct ponto), arq);
    fclose (arq);
}


struct ponto *read (unsigned int *pn)
{
    struct ponto *p = (struct ponto *) malloc(sizeof(struct ponto));
    
    unsigned int n = 0;
    
    FILE *arq;
    arq = fopen("pontos.dat", "rb");
    
    while(1) 
	{
        fread(p, 1, sizeof(struct ponto), arq);
        if(feof(arq)) 
			break;
        n++;
    }
    
    rewind(arq);
    
    p = (struct ponto *) realloc(p, n*sizeof(struct ponto));
    fread(p, n, sizeof(struct ponto), arq);
    
    fclose(arq);
    
    *pn = n;
    
    return p;
}



void exibir_ponto (struct ponto *p, struct ponto *pf)
 {
    if(p < pf)
	{
		printf("(%.3lf , %.3lf) \n", (*p).x, (*p).y);
		exibir_ponto (p+1, pf);
	}
}


int main()
{
	int n_pontos, opcao;
	struct ponto *p;
	do
	    {
		system ("cls");
		printf(" MENU \n\n1. Gravar arquivo com pontos. \n2. Recuperar pontos de arquivo. \n3. Sair.\n\n");
		scanf("%i", &opcao);
		switch (opcao)
		{
		    case 1:
			printf ("\nDigite o numero de pontos que deseja encontrar: ");
			scanf ("%d", &n_pontos);
			getchar();
			p = criar(n_pontos);

			save (p, n_pontos);
			arquivo(p, n_pontos);

			printf ("\nArquivo gravado");
			getch();
			break;
		    case 2:
			p = read(&n_pontos);
			exibir_ponto (p, p+n_pontos);
			getch ();
			break;
		    default:
			if (opcao != 3)
			    printf("Opcao invalida!");
			getch();
			break;
		}
	    } while(opcao != 3);

	printf ("Deseja mesmo sair do programa?");
	free(p);
	return 0;
	
//printf("Digite a quantidade de pontos que deseja dividir igualmente o circulo trignometrico: ");
//	scanf("%i", &n_pontos); 
//	getchar();
//	p = criar(n_pontos);
//	free(p);
	return 0;
}
