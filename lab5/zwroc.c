#include "zwroc.h"
void zwroc(char *informacja)
{
	FILE *fp;
	fp = fopen("wynik.html","w");
	fputs("<html> \n",fp);
	fputs("<body> \n",fp);
	fputs("<B> \n",fp);
	fputs(informacja,fp);
	fputs(" </BR> \n",fp);
	fputs("</B> \n",fp);
	fputs("</body> \n",fp);
	fputs("</html>",fp);
	fclose(fp);
}