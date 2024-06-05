#include <pthread.h>
#include <stdio.h>

void* thr1(void *mun) {
	int a = *((int*) num);
	int i, j, count;

	printf("Cac so nguyen to nho hon %d: ", *((int*) num));
	for (i = 1; i <= a; i++) {
		count = 0;
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				count++;
			}
		}
		if (count == 0) {
			/* code */
			printf("%d", i);
		}
	}
	printf("\n");
}

void main(int number, char *arr[]) {
	int num = atoi(arr[1]);

	pthread_t tid[1];
	pthread_create(&tid[0], NULL, thr1, (void*) &num);
	sleep(2);
}
