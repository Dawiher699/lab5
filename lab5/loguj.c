#include "loguj.h"
void loguj(char * po, char * przed)
{
	FILE * log;
	log = fopen("log.txt","a");
	fputs(przed, log);
	fputs(" --> ",log);
	fputs(po,log);
	fputs("\n",log);
	fclose(log);
}