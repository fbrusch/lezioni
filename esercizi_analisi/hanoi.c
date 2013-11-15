#include <stdio.h>

void sposta_piramide(int partenza, int arrivo, int n)
{
	int appoggio = 6-partenza-arrivo;

	if (n==1)
	{
		printf ("sposta dal piolo %i al piolo %i\n",partenza,arrivo);
		return;
	}

	sposta_piramide(partenza, appoggio, n-1);

	/* sposta una piramide di altezza n-1
	   sul piolo di appoggio (il terzo rispetto
		a partenza e arrivo) */

	sposta_piramide(partenza, arrivo, 1);

	/* sposta il disco rimasto da partenza ad
		arrivo */
	/* sposta la piramide di altezza n-1
		dal piolo di appoggio al piolo di
		arrivo */
	
	sposta_piramide(appoggio, arrivo, n-1);
}

int main()
{
	int dim;
	printf ("di quanti dischi e' la piramide che vuoi spostare? ");
	scanf ("%i",&dim);
	sposta_piramide(1,2,dim);
}


