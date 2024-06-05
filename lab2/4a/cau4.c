#include<stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	int x;
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	if(*argv[3]=='+')
	{
		x=add(a,b);
		printf("Ket qua: %d",x);
	}
	else if(*argv[3]=='-')
	{
		x=sub(a,b);
		printf("Ket qua: %d",x);
	}
	else 
	{
		printf("Doi so truyen khong dung");
	}
	return 0;
}
	