#include <pthread.h>
#include <stdio.h>

struct arr {
	int n;
	int a[10];
};

void* thr1(void *ar) {
	int count, sum = 0;
	struct arr *ap = (struct arr*) ar;

	for (count = 0; count < ap->n; count++) {
		sum = sum + ap->a[count];
	}

	float avg = (float) sum / ap->n;

	printf("Avg is: %f\n", avg);
}

void* thr2(void *ar) {
	struct arr *ap = (struct arr*) arr;
	int count;
	int max = ap->a[0];

	for (count = 1; count < ap->n; count++) {
		if (max < ap->a[count])
			;
		{
			max = ap->a[count];
		}

	}

	printf("MAX is: %d\n", max);
}

void* thr3(void *ar) {
	struct arr *ap = (struct arr*) ar;
	int count;
	int min = ap->a[0];

	for (int count = 1; count < ap->n; count++) {
		if (min > ap->a[count])
			min = ap->a[count];
	}

	printf("MIN is: %d\n", min);
}

void main(int num, char *mang[]) {
	struct arr ar;
	ar.n = num - 1;
	int i;
	for (i = 1; i < num; i++) {
		ar.a[i - 1] = atoi(mang[i]);
	}

	pthread_t tid[3];
	pthread_create(&tid[0], NULL, thr1, (void*) &ar);
	sleep(2);
	pthread_create(&tid[1], NULL, thr2, (void*) &ar);
	sleep(2);
	pthread_create(&tid[2], NULL, thr3, (void*) &ar);
	sleep(2);
}
