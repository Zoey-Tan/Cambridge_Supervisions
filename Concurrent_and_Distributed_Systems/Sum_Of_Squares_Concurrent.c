#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <math.h>
#define N 10000000

typedef struct data{
    int* arr;
    int thread_num;
} data;

void* halfSum(void* p){
    data *ptr = (data*) p;
    int n = ptr->thread_num;
    
    // Declare sum dynamically to return to join:
    int* thread_sum = (int*) calloc(1, sizeof(int));
    
    if(n == 0){
        for(int i = 0; i < N/2; i++)
            thread_sum[0] = thread_sum[0] + pow(ptr->arr[i],2);
    }
    else{
        for(int i = N/2; i < N; i++)
            thread_sum[0] = thread_sum[0] + pow(ptr->arr[i],2);
    }
    
    pthread_exit(thread_sum);
}

int main(void){

    int static numArray[N],squareArray[N]; // Define an array of four integers
    
    // Use current time as seed for rand()
    srand(time(0));
    // Get inputs for the array elements
    for (int i=0;i<N; i++) {
        numArray[i] = rand() % 4 + 1; // Generate random integer between 1 and 4
    }
    
    // Declare arguments for both threads
    data thread_data[2];
    thread_data[0].thread_num = 0;
    thread_data[0].arr = numArray;
    thread_data[1].thread_num = 1;
    thread_data[1].arr = numArray;
    
    // Declare thread IDs
    pthread_t tid[2];
    
    // Start both threads
    pthread_create(&tid[0], NULL, halfSum, &thread_data[0]);
    pthread_create(&tid[1], NULL, halfSum, &thread_data[1]);
    
    // Declare space for sum
    int* sum0;
    int* sum1;
    
    // Retrieve sum of threads
    pthread_join(tid[0], (void**)&sum0);
    pthread_join(tid[1], (void**)&sum1);
    
    printf("%i\n", *sum0 + *sum1);
    
    return 0;

    //Time: 0.133s
}
