#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
	int fp1[2],fp2[2];
	int buffer;
	int pid;
	if(argv<2){
		printf("Doi so thieu: \n ");
		return -1;
	}
	if(atoi(argv[1])<=3){
		printf("Doi so khong lon hon 3 \n");
		return -1;
	}
else{
	if(pipe(fp1)==0 && pipe(fp2)==0){
		pid=fork();
		if( pid<0){
			printf("Fork failed\n");
			return -1;
		}
		else if(pid==0){
			close(fp1[1]);
			read(fp1[0],&buffer,sizeof(buffer));
			close(fp1[0]);
			int s=1,i;
		for(i=2;i<=buffer;i++)
			s=s*i;
			close(fp2[0]);
			write(fp2[1],&s,sizeof(s));
			close(fp2[1]);
		}
	else{
		close(fp1[0]);
		int temp = atoi(argv[1]);
		write(fp1[1],&temp, sizeof(temp));
		close(fp2[1]);
		int n;
		read(fp2[0],&n,sizeof(n));
		printf("%d! =%d \n",temp,n);
		close(fp2[0]);
		}
	}
else{
	printf("pipe faile \n");
	return -2;
}
}
return 1;
}
