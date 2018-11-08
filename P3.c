/* P3.c */
/* MURILLO RODRIGUES GONÇALVES */
/* 11811EBI001 */


#include<stdio.h>

int main()
{
	char string[256];
	int i, final, x=0, y;
	
	//declaração a string
	printf("Digite os caracteres: ");
	scanf("%s", string);
	
	//manipulação
	for(i=0; string[i]!= '\0'; i++)
	{
		if(string[i]>=48 && string[i]<=57)
		{
		 	y = string[i] - 48;
			final = y + x; 
			x = final*10;
		}
	}
	
	//mostrar resultado
	printf("resultado: %d", final);
	return 0;
}
