#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc ,char *argv[])
{
	pid_t pid;
	int child_status;
	int a=atoi(argv[1]);
	int i;
	int tong=0;
	int tong_uoc=0;
	//Nhan ban tien trinh, add ban sao moi
	pid = fork();
	switch ( pid ) {     
	case -1:
	//tien trinh moi khong duoc tao
		printf("Khong tao duoc tien trinh moi");
	exit( 1 );
	case 0: 
	//tao tien trinh thanh cong, dang o tien trinh con
	for ( i=1;i<=a;i++){
		if(a%i==0)
			tong_uoc+=i;
	}
		printf("Tong Uoc = %d\n",tong_uoc);
		exit( 0 );
	default: 
	//tao tien thanh cong, dang trong tien trinh con
	for(i=0;i<=a;i++){
		tong+=i;
	}
	//wait tien trinh con finish
		wait( &child_status );
		printf("Tong = %d\n",tong);
	}
return 0;
}

