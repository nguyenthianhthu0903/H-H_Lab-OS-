
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define MAX 16    
  

#define MAX_THREAD 40
#define MAX_POINT 10000

  
int counter = 0;
int in = 0;
void* count(void* arg) 
{ 
  
	int temp =0;
	float x;
	float y;
   for(int i=0; i<MAX_POINT;i++)
   {
	x =  ((float)rand()/(float)(RAND_MAX)) * 2 -1;
	y =  ((float)rand()/(float)(RAND_MAX)) * 2 -1;
	
	if(x*x + y*y <= 1){
		temp++;
		}
   }
	in+= temp;
	counter += MAX_POINT;
} 
  
int main() 
{ 
    clock_t t1, t2; 
  
    t1 = clock(); 
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 4 threads 
    for (int i = 0; i < MAX_THREAD ; i++) 
        pthread_create(&threads[i],NULL,&count,(void*) &counter); 
  
    // joining 4 threads i.e. waiting for all 4 threads to complete 
    for (int i = 0; i < MAX_THREAD ; i++) 
        pthread_join(threads[i],NULL);
  
	
	printf("PI  = %f\n",(double)in/(double)counter * 4);
      t2 = clock(); 
          // time taken by merge sort in seconds 
 
	printf("Time taken: %f\n",(t2 - t1) /  (double)CLOCKS_PER_SEC); 
    return 0; 
} 

