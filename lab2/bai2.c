#include <stdio.h>
#include <math.h>

int main(int argc , char ** argv[]){
	if(argc > 2)
		{
			printf("CO QUA NHIEU DOI SO\n");
		}
	if(atoi(argv[1]) <= 0)
		{
			printf("DOi SO KHONG PHAI LA SO NGUYEN DUONG\n");
		}
	else
	{
		int count = 0;
		for (int i = 1; i<=atoi(argv[1]) ;i++)
		{
			if( atoi(argv[1]) % i == 0)
			{
				printf("%d\n",i);
				count++;
			}
		}
		if (count != 2)
		{
		printf("%d khong phai la so nguyen to\n",atoi(argv[1]));		
		}
		if (count == 2)
		{
		printf("%d phai la so nguyen to\n",atoi(argv[1]));		
		}
	}
		
	return 0;
}
