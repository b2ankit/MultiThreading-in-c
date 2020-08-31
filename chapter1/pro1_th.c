/**********************************************************************************************************
 1. Calculate the even and odd sum of large number and calculate timeLaps
 2. same program distributted among more thread the time will be reduce.
 *********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

typedef unsigned long long llvalue;

llvalue oddSum = 0;
llvalue evenSum = 0;

void *sum_even(void * arg){
    llvalue end = *((llvalue *)arg);
    printf("end in even  : %lld\n",end);
    for(llvalue i = 0;i<end;i++){
        if((i%2)==0){
            evenSum = evenSum+i;
        }
    }
}

void *sum_odd(void * arg){
    llvalue end = *((llvalue *)arg);
    printf("end in odd  : %lld\n",end);
    for(llvalue i = 0;i<end;i++){
        if((i%2)!=0){
            oddSum = oddSum+i;
        }
    }
}

int main(){

    int time_sec;
    llvalue *arg = NULL;
    llvalue start = 0 , end = 1900000000;
    // llvalue start = 0 , end = 10;

    clock_t before = clock();
    /****************************************
     Thread Decalearation.
     ***************************************/
    pthread_t threadEven;
    pthread_t threadOdd;

    /****************************************
     Allocating memory for arg.
     ***************************************/
    arg = malloc(sizeof(*arg));
    if(!arg){
        printf("Memory allocation of arg : Failed\n");
    }
    *arg = end;
    /****************************************
     Creating Thread.
     ***************************************/
    pthread_create(&threadEven,NULL,sum_even,arg);
    pthread_create(&threadOdd,NULL,sum_odd,arg);

    /****************************************
     * Join the main Thread
     ***************************************/
    pthread_join(threadEven,NULL);
    pthread_join(threadOdd,NULL);

    clock_t differnce = clock() - before;
    time_sec = differnce/CLOCKS_PER_SEC;


    printf("EvenSum : %llu\n",evenSum);
    printf("OddSum : %llu\n",oddSum);
    printf("Time laps : %d\n",time_sec);

    return 0;
}