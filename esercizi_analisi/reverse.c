#include <stdio.h>

char* f(char* s, char c)
{
	for (; *s!=c && *s!='\0'; s++) ;
	
	if (*s!='\0') s++;
		
	return s;
}

char* p(char* s, char c)
{
	for (; *s!=c && *s!='\0'; s++)
		printf ("%c",*s);
}

void g(char* s, char c)
{
	if (*s=='\0') return;
	
	g(f(s,c),c);
	p(s,c);
}

int main()
{
	g("sei uno zero",' ');
	printf ("\n");
}