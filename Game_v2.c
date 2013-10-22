int vincente(int n)
{
	int i;
  	if (n<3) return 1;  
  	if (n<6) return 0;
  	for(i=0;i<=n;i++)
      if (vincente(i)==0 && vincente(n-i)==0)
      	return 1;
	return 0;
}

int codifica(int numero1, int numero2)
{
  return numero1*1000+numero2;
}

int decodifica1(int numero)
{
  return numero/1000;
}

int decodifica2(int numero)
{
  return numero%1000;
}

int decodifica(int numero, int param)
{
  if(param==1)
    return numero/1000;
  return numero%1000;
}

int p1a(int numero1, int numero2)
{
    return numero1;
}

int p1b(int numero)
{
  	return codifica(numero-3,3);
}


int p2a(int numero1, int numero2)
{
    return numero1;
}

int p2b(int numero)
{
  	return codifica(numero-4,4);
}

int mossa(int numero1, int numero2, int giocatore)
{
    int risultato;
    
    if(giocatore==1)
    {
	   risultato = p1a(numero1, numero2);
       risultato = p1b(risultato);
    }
  	else
    {
	   risultato = p2a(numero1, numero2);
       risultato = p2b(risultato);
    }
    
    giocatore=3-giocatore;
    
    if(decodifica1(risultato)<3 || decodifica2(risultato)<3)
        return giocatore;
    
    return mossa(decodifica1(risultato), decodifica2(risultato), giocatore);
}
