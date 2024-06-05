#include<stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	int i,j,c=0,a[100],t;
	for(j=1;j<argc;j++)
	{
		a[j]=atoi(argv[j]);
	}
	for(j=1;j<argc;j++)
	{
		if(a[j]==0)
		{
			c++;
			for(i=j;i<argc-1;i++)
			{
				a[i]=a[i+1];
			}
		}
	}
	for(i=1;i<argc-c;i++)
	{
		for(j=i+1;j<argc-c;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("Da tang la: ");
	for(j=1;j<argc-c;j++)
	{
		printf(" %d ",a[j]);
	}
	return 0;
}