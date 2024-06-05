#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h> 
#include <unistd.h>
struct mesg_buffer
{
	long mesg_type;
	int mesg;	
};
int main(int argc, char ** argv)
{
	struct mesg_buffer mess;
	key_t key;
	int gt = 1;
	int msgid;	
	key = ftok(".", 1);
	msgid= msgget(key, 0666| IPC_CREAT);
	mess.mesg_type = 1;
	int n= atoi(argv[1]);
	if(argc > 2){
		printf("Qua nhieu doi so \n");
	}	
	else if(argc <2)
	{
	printf("thieu doi so\n");
	}else{
		if(n <= 3){
			printf("Doi so nho hon 3\n");
	}else{
		pid_t pid;
		pid=fork();
		if(pid < 0)
		{
			printf("Fork failed");
		}
	else if(pid==0){
	int i;
	for (i=1;i<=n;i++) gt=gt*i;
	mess.mesg= gt;
	msgsnd(msgid, &mess, sizeof(mess), 0);
	}else{
		wait(NULL);
		msgrcv(msgid, &mess, sizeof(mess), 1, 0); 
		printf("%d!=%d\n",n,mess.mesg);
		msgctl(msgid, IPC_RMID, NULL);
	}
	}
}
return 0;
}
