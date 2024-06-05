#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/errno.h>

#define FIFO1 "/tmp/ff.1"
#define FIFO2 "/tmp/ff.2"
#define PM 0666
extern int errno;
#define PIPE_BUF 4096

int main( int argc, char* argv[]){
	int kq,tt;
	int childpid, readfd, writefd;
	if((mknod(FIFO1,S_IFIFO | PM,0)<0)&& (errno!=EEXIST)){
		printf(" Fail to create FIFO 1.Aborted. \n");
		return -1;
		}
	if((mknod(FIFO2,S_IFIFO | PM,0)<0)&& (errno!=EEXIST)){
		unlink(FIFO1);
		printf(" Fail to create FIFO 2.Aborted. \n");
		return -1;
	}
	childpid=fork();
	if (childpid ==0){
		if((readfd=open(FIFO1,0))<0)
			perror(" child cannot open readFIFO \n");
		if((writefd=open(FIFO2,1))<0)
			perror(" child cannot open writeFIFO \n");
		char pt=*argv[3];
		if(pt == '+'){
			tt=atoi(argv[1]) + atoi(argv[2]);
		}
		else if(pt == '-'){
			tt=atoi(argv[1]) - atoi(argv[2]);
		}
		else if(pt == '*'){
			tt=atoi(argv[1]) * atoi(argv[2]);
		}
		else if(pt == '/'){
			tt=atoi(argv[1]) / atoi(argv[2]);
		}
		else{
			tt=0;
		}
		write(writefd,&tt,sizeof(tt));
		close(writefd);
		close(readfd);
		return 1;
	}
else if(childpid >0){
		if((writefd=open(FIFO1,1))<0)
			perror(" Parent cannot open writeFIFO \n");
		if((readfd=open(FIFO2,0))<0)
			perror(" Parent cannot open readFIFO \n");
		read(readfd,&kq,PIPE_BUF);
		FILE *fp;
fp=fopen("Result2b.txt","w+");
fprintf(fp," %s %s %s =%d\n",argv[1],argv[3],argv[2],kq);
		while (wait((int* ) 0)!=childpid);
		close(writefd);
		close(readfd);
		
		if(unlink(FIFO1)<0)
			perror("cannot remove FIFO1 \n");
		if(unlink(FIFO2)<0)
			perror("cannot remove FIFO2 \n");
		return 1;
	}
else{
printf("Fork failed \n ");
return -1;
}return 0;
}
			
