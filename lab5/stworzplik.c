#include "stworzplik.h"
void stworzplik(char * el1, char * el2)
{
	FILE * fp;
	fp = fopen("plik.html","w");
	fputs("<html> \n",fp);
	fputs("<body> \n",fp);
	fputs("<B> \n",fp);
	fputs("parametr </BR> \n",fp);
	fputs(el1,fp);
	fputs(" </BR> \n",fp);
	fputs(el2,fp);
	fputs("</B> \n",fp);
	fputs("</body> \n",fp);
	fputs("</html>",fp);
	fclose(fp);
}