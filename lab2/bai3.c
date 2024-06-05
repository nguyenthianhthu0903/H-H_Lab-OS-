#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char ** argv){
	int a[100];
	
	for(int i = 1; i<argc;i++)
	{
		if(isalnum(argv[i]) != 0)
		{
			printf("%d ,",a[i]);
		}
	}
	int tg;
	for(int i = 1; i<argc;i++)
	{
		for(int j = 1;j<argc;j++)
		{
			if(a[i]<a[j])
			{
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	printf("Mang sau khi sap xep la: \n");
	for(int i = 1; i<argc;i++)
	{
		printf("%d ,",a[i]);
	}
	return 0;
}

