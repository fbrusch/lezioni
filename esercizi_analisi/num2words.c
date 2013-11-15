#include <stdio.h>
#include <string.h>

void num2words(int n)
{
    char* until19[20]={"zero",
                     "uno",
                     "due",
                     "tre",
                     "quattro",
                     "cinque",
                     "sei","sette","otto","nove","dieci",
                     "undici","dodici","tredici","quattordici",
                     "quindici","sedici","diciassette",
                     "diciotto","diciannove"};


    char* decine[]={"zero","dieci","venti","trenta","quaranta",
                    "cinquanta","sessanta","settanta","ottanta",
                    "novanta"};

    if (n<=19)
        printf("%s\n",until19[n]);
    else if (n<=100)
        printf ("")
        printf("\n");



}

int main(int argc, char** argv)
{
    num2words(atoi(argv[1]));
}
