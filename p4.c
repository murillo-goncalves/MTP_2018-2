/* P4.c */
/* MURILLO RODRIGUES GONÇALVES*/
/* 11811EBI001 */

#include <stdio.h>

double ackermann(float m, float n)
{
	if(m==0) 
		return n+1;
	else if(m>0 && n==0) 
		return ackermann(m-1,1);
	else if(m>0 && n>0) 
		return ackermann(m-1, ackermann(m, n-1));
}

int main ()
{
	float m, n;
	
	
	printf ("Digite dois valores p aplicar a funcao de ackermann: ");
	scanf ("%f  %f", &m, &n);
	
	
	printf("%.1f + %.1f = %.1lf", m, n, ackermann(m,n));
	
	return 0;
}
