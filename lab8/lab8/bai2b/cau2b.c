#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<pthread.h>
#include <semaphore.h>
 #define SEED 35791246

int count = 0;

sem_t sem;

void* monte(void* arg)
{ 
	double x,y,z;
	int i;
	srand(SEED);
	int n = (*(int*)arg);
	for(i=0;i<n;i++){
	x = (double)rand()/RAND_MAX;
	y =(double)rand()/RAND_MAX;
	z=x*x+y*y;
	if(z<=1){
		sem_wait(&sem);
		count++;
		sem_post(&sem);

		}
	}

}

int main(int argc, char *argv){
	int niter;
	 double pi;
	printf("Enter the number of interations used to estimate pi: ");
	 scanf("%d", &niter);
	sem_init(&sem,0,1);
	int thread, i;
	 printf(" Enter num of thread: ");
	 scanf("%d", &thread);
	pthread_t t[ thread];
	int leng= niter/thread;
	 for (i =0;i<thread;i++){
		pthread_create(&t[i],NULL,monte,&leng);
	}
	 for(i=0; i<thread;i++){
		pthread_join(t[i],NULL);
	}
	 pi =4* (double) count/niter;
	 printf( " Result = %lf\n", pi);
	 sem_destroy(&sem);
	 return 0;
}
