#include "zglosblad.h"
void zglosblad()
{
	char log[50];
	FILE *error;
	error = fopen("ero.txt","a");
	fputs("blad: \0",error);
	FILE *fp;
	fp = fopen("plik.html","r");
	while(fscanf(fp,"%s",log))
	{
		fputs(log,error);
		fputs("\n",error);
	}
	fclose(error);
	fclose(fp);
	remove("plik.html");
	
}