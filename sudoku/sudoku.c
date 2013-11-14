#include <stdio.h>
#include <unistd.h>
#define ORDINE 5
#define DIM (ORDINE*ORDINE)

// (condizione ? se_vero : se_falso)

int giusta(int m[DIM][DIM], int n, int cr)
{
    int cifre[DIM];
    int i;
    for(i=0;i<DIM;i++)
        cifre[i]=0;

    for(i=0;i<DIM;i++)
        if(m[cr==0?i:n][cr==0?n:i]>0)
            if(cifre[m[cr==0?i:n][cr==0?n:i]-1]>0)
                return 0;
            else
                cifre[m[cr==0?i:n][cr==0?n:i]-1]++;

    return 1;
}

int colonna_giusta(int m[DIM][DIM], int c)
{
    return giusta(m,c,0);
}

int riga_giusta(int m[DIM][DIM], int r)
{
    return giusta(m,r,1);
}

int cella_quadro_x(int x, int y, int n) // ritorna la riga dell'n-simo elemento del quadro x,y
{
    return x*ORDINE+n/ORDINE;
}
int cella_quadro_y(int x, int y, int n)
{
    return y*ORDINE+n%ORDINE;
}


int quadro_giusto(int m[DIM][DIM], int x, int y)
{
    int cifre[DIM];
    int i;
    for (i=0;i<DIM;i++)
        cifre[i]=0;

    for(i=0;i<DIM;i++)
        if(m[cella_quadro_x(x,y,i)][cella_quadro_y(x,y,i)]>0)
        {
            if(cifre[m[cella_quadro_x(x,y,i)][cella_quadro_y(x,y,i)]-1]>0)
                return 0;
            else
            {
                cifre[m[cella_quadro_x(x,y,i)][cella_quadro_y(x,y,i)]-1]++;
            }
        }
    return 1;
}

int schema_giusto(int m[DIM][DIM])
{
    int i;
    for(i=0;i<DIM;i++)
    {
        if(riga_giusta(m,i)==0)
            return 0;
        if(colonna_giusta(m,i)==0)
            return 0;
        if(quadro_giusto(m,i/ORDINE,i%ORDINE)==0)
            return 0;
    }
    return 1;
}

void stampa_sudoku(int m[DIM][DIM])
{
    int i,j;
    for (i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            printf("%i ",m[i][j]);
            if(m[i][j]<10) printf(" ");
            if((j+1)%ORDINE==0) printf("  ");
        }
        printf("\n");
        if((i+1)%ORDINE==0) printf("\n");
    }
}


int risolvi_sudoku(int m[DIM][DIM])
{
    int i,j,k;
    if(schema_giusto(m)==0)
        return 0;

    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            if(m[i][j]==0)
            {
                for(k=1;k<=DIM;k++)
                {
                    m[i][j]=k;
                    if(risolvi_sudoku(m)==1)
                        return 1;
                }
                m[i][j]=0;
                return 0;
            }
    return 1;
}

int test()
{
    int s[4][4] = {
        {1,2,0,0},
        {3,4,4,0},
        {3,2,1,4},
        {1,2,3,4}
    };

    int s2[4][4] = {
        {1,2,3,4},
        {3,4,1,2},
        {0,0,0,0},
        {2,3,4,1}

    };
    int i,j;

    if(riga_giusta(s,0)==1)
        printf("ok, test per riga 0 superato\n");
    else
        printf("tu dici che la riga 0 non è giusta, ma a me sembra che lo sia.\n");

    if(riga_giusta(s,1)==0)
        printf("ok, test per riga 1 superato\n");
    else
        printf("hai toppato la riga 1\n");

    if(colonna_giusta(s,2)==1)
        printf("ok, test per colonna 2 superato\n");
    else
        printf("hai toppato per colonna 2\n");
    if(colonna_giusta(s,0)==0)
        printf("ok, test per colonna 0 superato\n");
    else
        printf("hai toppato per colonna 0");

    if(quadro_giusto(s,0,0)==1)
        printf("ok, test per quadro 0,0 superato\n");
    else
        printf("test per quadro 0,0 toppato\n");

    if(quadro_giusto(s,1,1)==0)
        printf("ok, testo per quadro 1,1 superato\n");
    else
        printf("test per quadro 0,1 toppato\n");


    if(schema_giusto(s)==0)
        printf("ok, in effetti lo schema s è sbagliato\n");
    else
        printf("sotto l'effetto di quale acido s ti sembra giusto?\n");

    if(schema_giusto(s2)==1)
        printf("ok, s2 è in effetti giusto\n");
    else
        printf("s2 è giusto, controlla meglio!");

    stampa_sudoku(s2);
    risolvi_sudoku(s);
    stampa_sudoku(s2);

}

int svuota_sudoku(int s[DIM][DIM])
{
    int i,j;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            s[i][j]=0;
}

int main()
{
    int s[DIM][DIM];

    /*test();*/
    svuota_sudoku(s);
    risolvi_sudoku(s);
    stampa_sudoku(s);

}
