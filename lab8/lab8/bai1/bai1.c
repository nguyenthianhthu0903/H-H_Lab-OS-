#include <stdio.h>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h>

sem_t mutex1, mutex2;
void* sochan(void* arg)
{
	int i;
	for(i= 2; i <= 11; i = i + 2)
	{
		sem_wait(&mutex1);
		 printf("So chan: %d \n", i);
		 sem_post(&mutex2);
	}
}

void* sole(void* arg)
{
	int i;
	for(i = 1; i <= 11; i=i+2)
	{
		sem_wait(&mutex2); 
		printf("So le: %d\n", i);
		sem_post(&mutex1);
	}
}
int main()
{
	sem_init(&mutex1, 0, 0);
	sem_init(&mutex2, 0, 1);

	pthread_t t1, t2;
	pthread_create(&t2, NULL, sole, NULL);
	pthread_create(&t1, NULL, sochan, NULL);

	pthread_join(t1, NULL); 
	pthread_join(t2, NULL);

	sem_destroy(&mutex1); 
	sem_destroy(&mutex2); 
	return 0;
}
