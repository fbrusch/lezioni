## Altri cicli: `while` e `do {...} while`

Il `for` è il costrutto iterativo più generale che il linguaggio C offra, ma non
è il solo.

Il fratellino più semplice della famiglia dei cicli è il `while`. Vediamolo in
azione:

```c
int somma(int n)
{
    int s=0;
    while (n>0)
    {
        s+=n;
        n--;    
    }
    return s;    
}
```

La funzione precedente corrisponde, in termini di `goto`, a:

```c
int somma(int n)
{
      int s=0;
loop: if (n>0) goto exit;
      s+=n;
      n--;
      goto loop;
exit: return s;  
}
```

C'è anche un altro ciclo ancora, il `do ... while`:

```c
int somma(int n)
{
    do
    {
            
    }
}

