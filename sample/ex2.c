/*Fixing race condition sitiuation using MUTEX*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define MAX_SIZE 10

int counter = 0;

//MUTEX decalaration
pthread_mutex_t lock;

void *increse_counter(void * argv){
    int job;
    pthread_mutex_lock(&lock);
    counter++;
    printf("value of counter : %d\n",counter);
    pthread_mutex_unlock(&lock);
}


int main(){
int retval;
int i;

//Thread insialization
pthread_t threadId[MAX_SIZE];

//Mutex insialization
retval = pthread_mutex_init(&lock,NULL);
if(retval!=0){
    printf("Mutex init : Failed\n");
}

//Thread creatation
for(i=0;i<MAX_SIZE;i++)
{
    
    retval = pthread_create(&threadId[i],NULL,&increse_counter,NULL);
    if(retval!=0){
        printf("Thread%d createion : Failed",i);
    }
}
    

for(int i=0;i<MAX_SIZE;i++)
pthread_join(threadId[i],NULL);

pthread_exit(NULL);
pthread_mutex_destroy(&lock);

return 0;
}
