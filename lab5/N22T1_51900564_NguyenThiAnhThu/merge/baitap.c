// CPP Program to implement merge sort using 
// multi-threading 
//#include <iostream> 
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include<stdio.h>

// number of elements in array
#define MAX 20

// number of threads
#define THREAD_MAX 4

//using namespace std;

// array of size MAX
int a[MAX];
int part = 0;

// merge function for merging two parts
void merge(int low, int mid, int high)
{   
    int* left = (int*) malloc( (mid - low + 1) * sizeof(int));
    int* right = (int*) malloc( (high - mid) * sizeof(int));


    // n1 is size of left part and n2 is size
    // of right part
    int n1 = mid - low + 1,
    n2 = high - mid,
    i, j;

    // storing values in left part
    for (i = 0; i < n1; i++)
        left[i] = a[i + low];

    // storing values in right part
    for (i = 0; i < n2; i++)
        right[i] = a[i + mid + 1];

    int k = low;
    i = j = 0;

    // merge left and right in ascending order
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    // insert remaining values from left
    while (i < n1) {
        a[k++] = left[i++];
    }

    // insert remaining values from right
    while (j < n2) {
        a[k++] = right[j++];
    }

    free(left);
    free(right);
}

// merge sort function
void merge_sort(int low, int high)
{
    // calculating mid point of array
    int mid = low + (high - low) / 2;
    if (low < high) {

        // calling first half
        merge_sort(low, mid);

        // calling second half
        merge_sort(mid + 1, high);

        // merging the two halves
        merge(low, mid, high);
    }
}

// thread function for multi-threading
void* merge_sort123(void* arg)
{
    // which part out of 4 parts
    int thread_part = part++;

    // calculating low and high
    int low = thread_part * (MAX / THREAD_MAX);
    int high = (thread_part + 1) * (MAX / THREAD_MAX) - 1;

    // evaluating mid point
    int mid = low + (high - low) / 2;
    if (low < high) {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
    return 0;
}



// Driver Code
int main()
{
    // generating random values in array
    for (int i = 0; i < MAX; i++){
        a[i] = rand() % 100;
    //        printf("%d ", a[i]);
    }


    pthread_t threads[THREAD_MAX];

    // creating 4 threads
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_create(&threads[i], NULL, merge_sort123,
                       (void*)NULL);

    // joining all 4 threads
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_join(threads[i], NULL);


    
    // merging the final 4 parts
    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1);
    merge(0, (MAX - 1)/2, MAX - 1);


    // displaying sorted array
    printf("\n\nSorted array: ");
    for (int i = 0; i < MAX; i++)
        printf ("%d ", a[i]);


    printf("\n");
    return 0;
}
