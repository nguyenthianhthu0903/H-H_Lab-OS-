#include <stdio.h>
#include <math.h>

int main(int argc , char ** argv[]){
	if(argc > 2)
	{
		printf("CO QUA NHIEU DOI SO\n");
	}
	else
	{
		if(atoi(argv[1]) <= 0)
		{
			printf("DOi SO KHONG PHAI LA SO NGUYEN DUONG\n");
		}
		int S=0;
		for(int i =0; i<=atoi(argv[1]) ;i++)
		{
			S = S+i;
		}
		printf("ket qua la : %d\n",S);
	}
	return 0;
}
