#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
struct mesg_buffer
{
	long mesg_type;
	int mesg_a,mesg_b;
	int mesg_kq;
	char mesg[1];	
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
	if(argc > 4){
		printf(" Qua nhieu doi so");
	}
	else if( argv < 4){
		printf(" Thieu doi so");
	}
	else{
		pid_t pid;
		pid= fork();
		if(pid <0)
		{
			printf(" Fork failed");
		}
		else if(pid ==0){
			sleep(2);
			msgrcv(msgid,&mess, sizeof(mess),1,0);

	int a=mess.mesg_a;
	int b=mess.mesg_b;
	if(strcmp(mess.mesg,"+")==0) mess.mesg_kq = a+b;
	else if(strcmp(mess.mesg,"-")==0) mess.mesg_kq = a-b;
	else if(strcmp(mess.mesg,"x")==0) mess.mesg_kq = a*b;
	else
	mess.mesg_kq= a/b;
	mess.mesg_type = 2;
	msgsnd(msgid, &mess, sizeof(mess),0);
	}
else{
	mess.mesg_type =1;
	mess.mesg_a= atoi(argv[1]);
	mess.mesg_b= atoi(argv[2]);
	strcpy(mess.mesg,argv[3]);
	msgsnd(msgid,&mess, sizeof(mess),0);
	sleep(2);
	msgrcv(msgid,&mess, sizeof(mess),2,0);
	printf("%d %s %d =%d\n",mess.mesg_a, mess.mesg, mess.mesg_b, mess.mesg_kq);
	msgctl(msgid, IPC_RMID, NULL );
	}	
}
return 0;
}
