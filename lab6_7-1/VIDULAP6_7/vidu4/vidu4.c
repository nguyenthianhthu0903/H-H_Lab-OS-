#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
struct Message {
	int mtype;
	char* content;
};
int main(int argc, char* argv[]) {
	int mid, id, n, pid, temp;
	key_t key;
	struct Message msg;
	msg.content=(char*) malloc(BUFSIZ);
	key = ftok(".", 'a');
	if(key==-1) {
		perror("Key created.\n");
		return 1;
	}
	mid=msgget(key, IPC_CREAT | 0666);
	if(mid==-1) {
		perror("Queue created.\n");
		return 2;
	}
	pid = fork();
	if(pid==0) { 
		msg.mtype=10;
		msg.content=argv[1];
		n=strlen(msg.content);
		printf("%s\n", msg.content);
		n+=sizeof(msg.mtype);
		temp=msgsnd(mid, &msg, n, 0);
		if(temp==-1) {
			perror("Message sent.\n");
			return 4;
		}
		sleep(5);
		printf("Child receive from parent:\n");
		n=msgrcv(mid, &msg, BUFSIZ, 11, 0);
		if(n==-1) {
			perror("Message received.\n");
			return 5;
		}
		msg.content[strlen(msg.content)]=0;
		printf("%s\n", msg.content);
		return 0;
	}
	else if(pid >0) { 
		sleep(1);
		printf("Child receive from parent:\n");
		n=msgrcv(mid, &msg, BUFSIZ, 10, 0);
		if(n==-1) {
			perror("Message received.\n");
			return 5;
		}
		printf("Parent received from child:\n");
		msg.content[strlen(msg.content)]=0;
		printf("%s\n", msg.content);
		printf("-------------------\n");
		printf("Message from parent:\n");
		msg.content=argv[2];
		n=strlen(msg.content);
		msg.mtype=11;
		n+=sizeof(msg.mtype);
		temp=msgsnd(mid, &msg, n, 0);
		if(temp==-1) {
			perror("Message sent.\n");
			return 4;
		}
	sleep(10);
	return 0;
	}
	else { perror("Fork failed."); return 3; }
	return 0;
}
