/*************************************************************************************************************
 * 1. making a functions Async.
 * 2. add_num function return the sum of two number
 * 3. sub_num function return the difference of two number
 ************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

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

void aync_add(int a, int b){
    pthread_t thsum;
    num_value *numValuesadd = NULL;
    numValuesadd = (num_value *)malloc(sizeof(num_value));
    if(!numValuesadd)
    {
        printf("Memory allocation for numValues : Failed\n");
    }
    numValuesadd->x = a;
    numValuesadd->y = b;
    pthread_create(&thsum,NULL,add_num,numValuesadd);
    pthread_join(thsum,NULL);
    if(numValuesadd)
        free(numValuesadd);
}

void aync_sub(int a, int b){
    pthread_t thsub;
    num_value *numValuessub = NULL;
    numValuessub = (num_value *)malloc(sizeof(num_value));
    if(!numValuessub)
    {
        printf("Memory allocation for numValues : Failed\n");
    }
    numValuessub->x = a;
    numValuessub->y = b;
    pthread_create(&thsub,NULL,sub_num,numValuessub);
    pthread_join(thsub,NULL);
    if(numValuessub)
        free(numValuessub);
}

int main(){
    int result = 0;
    aync_add(10,20);
    aync_add(20,30);
    aync_add(30,40);
    aync_sub(10,5);
    aync_sub(30,20);
    

    return 0;
}