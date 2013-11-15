
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int boggle(char **M, char dim, char *string);

int main(int argc, char **argv){
	if(argc!=5){
		printf("Wrong number of parameters passed!\n");
		exit(0);
	}

	char *Min=argv[1];
	char **M;
	int rows=atoi(argv[2]);
	int cols=atoi(argv[2]);
	char *string=argv[3];
	char *fileName=argv[4];

	setvbuf(stdout,(char * __restrict__) _IONBF,0,0);

	int i;

	M=(char**)malloc(sizeof(char*)*rows);
	for (i=0;i<rows;i++)
		M[i]=(char*)malloc(sizeof(char)*cols);

	for(i=0;i<rows*cols;i++)
		M[i/cols][i%cols]=Min[i];

	int res;

	res=boggle(M,rows,string);

	FILE *f=fopen(fileName,"w");
	fprintf(f,"%d\n",res);
	fclose(f);

}
