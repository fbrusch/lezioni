/*
*	(Possibile Soluzione)
*	Eseguibile che dato un numero intero ritorna la minor cifra piu' frequente nello stesso.
*	Inserire il numero da valutare nell'apposita variabile all'interno di della funzione main.
*	
*	Giaguaro9 23/10/2013
*
*/

int moda(int n){
	int i,cifra, best = 0;
	int conta, record = 0;
	int bozza;
	for(i=0; i<10; i++){
		bozza = n;
		conta = 0;
		do{
			cifra = bozza%10;
			if(cifra == i) conta++;
			bozza = bozza/10;
		}while(bozza>0);

		if (conta > record ){
			record = conta;
			best = i;
		}
		
	}
	
	return best;
}

int main(){
	
	// Numero da valutare
	int numero = 1221; 

	
	if(numero<0) numero = -numero;
	printf("Attenzione: il tipo INT supporta valori minori di 2147483648 \n\n");
	printf("Numero Inserito: %i \n", numero);
	printf("Moda: %i \n", moda(numero));	
	return 0;
}
