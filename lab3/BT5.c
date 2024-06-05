#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {
	pid_t child = fork();

	if (child > 0)
		sleep(20);
	else
		sleep(10);
}
