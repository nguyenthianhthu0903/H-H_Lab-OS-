// CPP Program to find sum of array 

/* printf */
#include <stdio.h>
/* pthread_* */
#include <pthread.h>
/* clock */
#include <time.h>
/* gettimeofday */
#include <sys/time.h>
/* syscall */
//#include <sys/syscall.h>
/* pid_t */
#include <sys/types.h>
/* open */
#include <sys/stat.h>
#include <fcntl.h>
/* strrchr */
#include <string.h>
#include<stdlib.h>
// kÃ­ch thÆ°á»›c array 
#define MAX      10000000
  
// maximum number of threads 
#define MAX_THREAD 2

int a[MAX];   //Khá»Ÿi táº¡o giÃ¡ trá»‹ ngáº«u nhiÃªn
int sum[4] = { 0 }; 
int part = 0; 
  
void* sum_array(void* arg) 
{ 
    int thread_part = part++; 
    int local_sum=0;
    for (int i = thread_part * (MAX / MAX_THREAD); i < (thread_part + 1) * (MAX / MAX_THREAD); i++) 
       local_sum += a[i]; 

	sum[thread_part] = local_sum;


} 
  
// ChÆ°Æ¡ng trÃ¬nh chÃ­nh.
int main() 
{ 
 srand((unsigned int)time(NULL));
 for(int i=0; i<MAX; i++){
 	a[i] = rand()%10;
	}

    clock_t t1, t2;
    struct timeval start2, end2;
    t1 = clock(); 
    gettimeofday(&start2, NULL);
    pthread_t threads[MAX_THREAD]; 
  
    // Creating MAX_THREAD threads 
    for (int i = 0; i < MAX_THREAD  ; i++) 
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
  
    // joining MAX_THREAD threads  
    for (int i = 0; i < MAX_THREAD ; i++) 
        pthread_join(threads[i],NULL); 
  
    // tá»•ng láº¡i cÃ¡c tá»•ng Ä‘oáº¡n
  
    int total_sum = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
      { printf("Tong doan %d la : %d\n", i, sum[i]);
        total_sum += sum[i];  }
   
   printf("Tong mang la : %d\n", total_sum);
  
  
      t2 = clock(); 
    gettimeofday(&end2, NULL);
    printf(" clock() method: %ld clocks.\n", (t2 - t1) );
	printf(" gettimeofday() method: %ldms\n", (end2.tv_sec - start2.tv_sec) *1000 + (end2.tv_usec - start2.tv_usec)/1000);
    return 0; 
} 

