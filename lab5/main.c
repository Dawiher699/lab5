#include "zglosblad.h"
#include "pobierz.h"
int main()
{
	FILE *error;
	while(true)
	{
		if(pobierz()==1)
		{
			error = fopen("error","w");
			zglosblad();
			fclose(error);
		}
	}
	return 0;
}