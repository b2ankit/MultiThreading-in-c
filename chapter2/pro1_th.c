/*************************************************************************************************************
 * 1. making a functions Async.
 * 2. add_num function return the sum of two number
 * 3. sub_num function return the difference of two number
 ************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

 //thread decalaration
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;

typedef struct  
{
    int x;
    int y;
}num_value;

typedef num_value num_value;

void *add_num(void *arg){
    num_value *numValues =(num_value *)arg;
    int sum = numValues->x + numValues->y;
   printf("sum  = %d\tx : %d\ty : %d\n",sum,numValues->x,numValues->y);
    
} 

void *sub_num(num_value *arg){
    num_value *numValues =(num_value *)arg;
    int sub = numValues->x - numValues->y;
    printf("sub  = %d\tx : %d\ty : %d\n",sub,numValues->x,numValues->y); 
}



int main(){
    int result = 0;
    

    num_value *numValues1 = NULL;
    numValues1 = (num_value *)malloc(sizeof(num_value));
    if(!numValues1)
    {
        printf("Memory allocation for numValues : Failed\n");
    }
    numValues1->x = 5;
    numValues1->y = 10;
    //creating thread1
    pthread_create(&th1,NULL,add_num,numValues1);

    num_value *numValues2 = NULL;
    numValues2 = (num_value *)malloc(sizeof(num_value));
    if(!numValues2)
    {
        printf("Memory allocation for numValues : Failed\n");
    }
    numValues2->x = 10;
    numValues2->y = 20;
    pthread_create(&th2,NULL,add_num,numValues2);

    num_value *numValues3 = NULL;
    numValues3 = (num_value *)malloc(sizeof(num_value));
    if(!numValues3)
    {
        printf("Memory allocation for numValues : Failed\n");
    }
    numValues3->x = 10;
    numValues3->y = 5;
    pthread_create(&th3,NULL,sub_num,numValues3);

    num_value *numValues4 = NULL;
    numValues4 = (num_value *)malloc(sizeof(num_value));
    if(!numValues4)
    {
        printf("Memory allocation for numValues : Failed\n");
    }
    numValues4->x = 20;
    numValues4->y = 10;
    pthread_create(&th4,NULL,sub_num,numValues4);


    //joining all the thread
    pthread_join(th1,NULL);
    if(numValues1)
        free(numValues1);

    pthread_join(th2,NULL);
    if(numValues2)
        free(numValues2);

    pthread_join(th3,NULL);
    if(numValues3)
        free(numValues3);
        
    pthread_join(th4,NULL);
    if(numValues4)
        free(numValues4);

    return 0;
}