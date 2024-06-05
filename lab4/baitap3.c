#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct arr {
	/* data */
	int n;
	int a[10];
	float c;
	int b[10];
};

struct file {
	/* data */
	struct arr ar;
	char *filename;
};

void* thr1(void *ar) {
	int count, sum = 0;
	struct arr *ap = (struct arr*) ar;

	for (count = 0; count < ap->n; count++) {
		sum = sum + ap->a[count];
	}

	float avg = (float) sum / ap->n;

	//printf("Avg is: %f\n", avg);
	ap->a = avg;
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

	//printf("MAX is: %d\n", max);
	ap->b[0] = max;
}

void* thr3(void *ar) {
	struct arr *ap = (struct arr*) ar;
	int count;
	int min = ap->a[0];

	for (int count = 1; count < ap->n; count++) {
		if (min > ap->a[count])
			min = ap->a[count];
	}

	//printf("MIN is: %d\n", min);
	ap->b[1] = min;
}

void* thr4(void *ar) {
	struct file *fi = (struct file*) ar;
	FILE *out;
	out = fopen(fi->filename, "wb");
	fprintf(out, "AVG is: %f\n", fi->ar.c);
	fprintf(out, "MAX is: %f\n", fi->ar.b[0]);
	fprintf(out, "MIN is: %f\n", fi->ar.b[1]);
	fclose(out);
}

void main(int number, char *array[]) {
	struct arr ar;
	ar.n = number - 2;
	int i;

	for (i = 2; i < number; i++) {
		/* code */
		ar.a[i - 2] = atoi(array[i]);
	}

	pthread_t tid[4];
	int status, *pstatus = &status;
	pthread_create(&tid[0], NULL, thr1, (void*) &ar);
	sleep(1);

	if (pthread_join(tid[0], (void**) pstatus) == 0) {
		pthread_create(&tid[1], NULL, thr2, (void*) &ar);
		if (pthread_join(tid[1], (void**) pstatus) == 0) {
			pthread_create(&tid[2], NULL, thr3, (void*) &ar);
			if (pthread_join(tid[2], (void**) pstatus) == 0) {
				struct file arf;
				arf.ar = ar;
				arf.filename = arr[1];
				pthread_create(&tid[3], NULL, thr4, (void*) &arf);
			}
		}
	}
	sleep(2);
}

