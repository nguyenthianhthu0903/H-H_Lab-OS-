#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main( int argc, char* argv[]){
	int fp[2];
	int pid;
	int kq,tt;
if (argc<4){
	printf(" Doi so khong dung\n");
	return -1;
}
if(pipe(fp)==0){
	pid=fork();

	if(pid <0){
		printf(" Fork failed\n");
		return -1;
	}else if(pid ==0){
		int pt= *argv[3];
		int i;
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
		close(fp[0]);
		write(fp[1],&tt,sizeof(tt));
	}
	else{
		close(fp[1]);
		read(fp[0],&kq,sizeof(kq));
		//ghi ra file
		FILE *fp;
		fp=fopen("Result.txt","w+");
		fprintf(fp,"%s %s %s =%d\n",argv[1],argv[3],argv[2],kq);
		fclose(fp);
		}
	}
	else{
		printf("Pipe failed\n");
		return -2;
	} 
	return 0;
}
