/**********************************************************************************************************
 1. Calculate the even and odd sum of large number and calculate timeLap
 2. same program distributted among more thread the time will be reduce.
 *********************************************************************************************************/

#include<stdio.h>
#include<time.h>
#include<pthread.h>

typedef unsigned long long llvalue;

llvalue oddSum = 0;
llvalue evenSum = 0;

void sum_even(llvalue end){
    printf("end in even  : %lld\n",end);
    for(llvalue i = 0;i<end;i++){
        if((i%2)==0){
            evenSum = evenSum+i;
        }
    }
}

void sum_odd(llvalue end){
    printf("end in odd  : %lld\n",end);
    for(llvalue i = 0;i<end;i++){
        if((i%2)!=0){
            oddSum = oddSum+i;
        }
    }
}
int main(){

    int time_sec;
    llvalue end = 1900000000;

    clock_t before = clock();

    sum_even(end);
    sum_odd(end);

    clock_t differnce = clock() - before;
    time_sec = differnce/CLOCKS_PER_SEC;


    printf("EvenSum : %llu\n",evenSum);
    printf("OddSum : %llu\n",oddSum);
    printf("Time laps : %d\n",time_sec);

    return 0;
}