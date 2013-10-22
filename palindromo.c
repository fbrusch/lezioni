int palindromo(int numero){

  int numero_palindromo = 0;
  int copianumero=numero; //questo serve perchè poi eseguo il controllo con il parametro della funzione
  
  if(numero < 10) //il numero deve avere almeno 2 cifre uguali
    return 0;
    
  for(; copianumero > 0; copianumero = copianumero / 10) //prendo ogni cifra del numero in ingresso
    numero_palindromo = numero_palindromo * 10 + copianumero % 10;
    
  if(numero_palindromo == numero)
    return 1;
  else
    return 0;
}
