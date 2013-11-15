#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int s1, int s2)
{
	if (s1>s2) return s1;
	return s2;
}

char* s(char* s1, char* s2)
{
	char* r=(char*)malloc(sizeof(char)*max(strlen(s1),strlen(s2))+1);
	int c=0;
	int i;
	
	for (i=0;s1[i]!='\0';i++)
	{
		r[i]=((s1[i]-'a')+(s2[i]-'a')+c)%2+'a';
		c=((s1[i]-'a')+(s2[i]-'a')+c)/2;
	}
	r[i++]=c+'a';
	r[i]='\0';
	
	return r;
}

int main()
{
	printf ("%s\n",s("aaba","aabb"));
	printf ("%s\n",s("abab","baba"));
	printf ("%s\n",s("aaaa","bbbb"));
}