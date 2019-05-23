#include "pobierz.h"
int pobierz()
{
	FILE *fp;
	int n;
	bool czekaj = true;
	while(czekaj)
	{
		fp = fopen("ready","r");
		if(fp == NULL)
		{
			czekaj = true;
		}
		else
		{
			remove("ready");
			czekaj=false;
			fclose(fp);
		}
	}
	char *text = malloc(50*sizeof(char));
	memset(text,0,50);
	fp = fopen("plik.html","r");
	if(fp==NULL)
	{
		free(text);
		return 2;
	}
	char *informacja=malloc(50*sizeof(char));
	fscanf(fp,"%s",informacja);
	while(informacja[0]=='<')
	{
		fscanf(fp,"%s",informacja);
	}
	fscanf(fp,"%s",informacja);
	while(informacja[0]=='<')
	{
		if(fscanf(fp,"%s",informacja)==0)
		{
			free(informacja);	
			free(text);
			fclose(fp);
			return 1;
		}
	}
	int i=0;
	while(informacja[i]!='\0'&&informacja[i]!='<')
	{
		text[i]=informacja[i];
		i++;
	}
	fscanf(fp,"%s",informacja);
	while(informacja[0]=='<')
	{
		if(fscanf(fp,"%s",informacja)==0)
		{
			free(informacja);	
			free(text);
			fclose(fp);
			return 1;
		}
		
	}
	n=atoi(informacja);
	informacja = tlumacz(text,n);
	zwroc(informacja);
	loguj(informacja,text);
	free(informacja);	
	free(text);
	remove("plik.html");
	fclose(fp);
	fp = fopen("gotowe","w");
	fclose(fp);
	return 0;
}