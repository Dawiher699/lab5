#include "informacja.h"
#include "stworzplik.h"
int main(int ile,char * arg[])
{
	char info[50];
	if(ile!=3)
	{
		informacja();
		return 0;
	}
	FILE * semaphore;
	FILE * wynik;
	FILE * blad;
	bool blokada=true;
	while(blokada)
	{
		semaphore = fopen("sem","r");
		if(semaphore == NULL)
		{
			blokada = false;
		}
		else
		{
			blokada = true;
			fclose(semaphore);
		}
	}
	semaphore = fopen("sem","w");
	stworzplik(arg[1],arg[2]);
	FILE *fp;
	fp = fopen("ready","w");
	fclose(fp);
	blokada = true;
	while(blokada)
	{
		blad = fopen("error","r");
		wynik = fopen("gotowe","r");
		if(wynik == NULL)
		{
			if(blad==NULL)
			{
				blokada = true;
			}
			else
			{
				blokada = false;
				puts("podano nieprawidlowe dane");
				fclose(blad);
				return 0;
			}
		}
		else
		{
			fp = fopen("wynik.html","r");
			blokada = false;
			fscanf(fp,"%s",info);
			bool niekoniec = true;
			while(niekoniec&&info[0]=='<')
			{
				if(fscanf(fp,"%s",info)!=1)
					niekoniec = false;
			}
			puts("twoj wynik to:");
			puts(info);
			fclose(fp);
			remove("wynik.html");
			fclose(wynik);
		}
	}
	remove("gotowe");
	fclose(semaphore);
	remove("sem");
	return 0;
}