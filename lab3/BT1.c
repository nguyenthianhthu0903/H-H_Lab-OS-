#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	pid_t pid;
	pid = fork();
	int sum = 0, totaldivisor = 0, i;

	if (pid < 0)
		printf("No child proccess!!");
	else if (pid == 0) {
		if (argc == 2 && atoi(argv[1]) > 0) {
			for (i = 0; i <= atoi(argv[1]); i++) {
				sum += i;
			}
			printf("sum is: %d", sum);
		}
	}

	else {
		for (i = 1; i <= atoi(argv[1]); i++) {
			if (atoi(argv[1]) % i == 0) {
				totaldivisor += i;
			}
		}
	}
	printf("Totaldivisor is: %d", totaldivisor);
	return 0;
}
