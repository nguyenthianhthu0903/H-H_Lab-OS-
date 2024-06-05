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
int main(int n, char **a){
	if(n<2){
		printf(" Missing Ardument\n");
		return -1;
	} 
	if(atoi(a[1])<=3){
		printf("Doi so khong lon hon 3");
		return -1;
	}
	else{
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
			perror(" child cannot open readFIFO. \n");
		if((writefd=open(FIFO2,1))<0)
			perror(" child cannot open writeFIFO. \n");
			int s;
			read (readfd,&s,sizeof(s));
			int gt=1;
			for ( int i=1; i<=s;i++){
				gt=gt*i;
			}write(writefd,&gt,sizeof(gt));
			close(readfd);
			close(writefd);
			return 1;
	}
	else if( childpid>0){
		if((writefd=open(FIFO1,1))<0)
			perror(" Child cannot open writeFIFO. \n");
		if((readfd =open(FIFO2,0))<0)
			perror(" Child cannot open raedFIFO. \n");
			int  input=atoi(a[1]);
			write(writefd,&input,sizeof(input));
			int temp;
			read (readfd,&temp,sizeof(temp));
			printf(" Result : %d\n",temp);
			close(readfd);
			close(writefd);
			if ( unlink(FIFO1)<0)
				perror(" cannot remove  FIFO1. \n");
			if(unlink(FIFO2)<0)
				perror("Cannot remove FIDO2. \n");
			return 1;
}
else{
	printf(" Fork failed \n");
	return -1;
}
}

}
