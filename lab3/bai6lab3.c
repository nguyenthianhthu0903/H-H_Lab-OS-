#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void main( int args, char*  argv[]){
	pid_t pid,wait;
	struct timeval start, end;
	pid = fork();
	if(pid>0){
		wait(NULL);
		clock_t t = clock();
		unsigned int time = end.tv_usec - start.tv_usec;
		double t=((double)time)/((double)1000000);
		printf(" Eclapsed time : %ld \n",t);
	}else if(pid==0){
		gettimeofday(&start,NULL);
		int command = system(argv[1]);
		gettimeofday(&end,NULL);
		if(command!=-1){
			printf("Lenh da duoc thuc thi \n");
		}
	}else{
		printf("Error \n");
	}
}