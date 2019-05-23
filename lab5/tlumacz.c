#include "tlumacz.h"
char* tlumacz(char text[50],int n)
{
	char *result;
	result = malloc(50*sizeof(char));
	strcpy(result,text);
	for(int i=0;i<50;i++)
	{
		if(text[i]<91&&text[i]>64)
		{
			result[i]=text[i]+n;
			while(result[i]<64)
				result[i]=result[i]+26;
			while(result[i]>91)
				result[i]=result[i]-26;
		}
		if(text[i]<122&&text[i]>96)
		{
			result[i]=text[i]+n;
			while(result[i]<97)
				result[i]=result[i]+26;
			while(result[i]>122)
				result[i]=result[i]-26;
		}
	}
	return result;
}