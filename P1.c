/* P1.c */
/* Murillo Rodrigues Gonçalves */
/* 11811ebi001 */



#include <stdio.h>

int main ()
{
	int estado = 0, i;
	char bits [256];
	printf ("Digite uma sequencia de numeros (zeros e ums) para verificar se eh multiplo de 3: ");
	fflush (stdin);
	gets (bits);
	for (i=0; bits[i] != '\0'; i++)
	{
		if (estado == 0 )
		{
			if (bits[i]=='0')
			{
				estado = 0;
			}
			else{
				estado = 1;
			}
		}
		else if (estado == 1)
		{
			if (bits[i]=='0')
			{
				estado = 2;
			}
			else{
				estado = 0;
			}
		}
		else if (estado == 2)
		{
			if (bits[i]=='0')
			{
				estado = 1;
			}
			else{
				estado = 2;
			}
		}
	}
	printf ("\n\nSequencia original: \n");
	for (i=0; bits[i] != '\0'; i++)
	{
		printf ("%c", bits[i]);
	}
	
	
	if (estado == 0)
	{
		printf ("\n\ne multiplo de 3");
	}
	else
	{
		printf ("\n\nnao e");
	}
	getch ();
	return 0;
}

