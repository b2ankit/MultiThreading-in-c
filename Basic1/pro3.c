/*******************************************************************************
 * 1. Semaphores in c multi Threading.
 * 2. Race condition : If more than 1 thread wants to change any shared resourece
 *    then race condition arises. but in accesing there is no race condition.
 * 3. creatx a semaphores,wait, post destroy semaphores.
 ******************************************************************************/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
 
/*Global variable*/
int count = 0 ;

/*semaphore declaration*/
sem_t lock;

/*function decalration*/
void *increase_count(void *arg){
    sem_wait(&lock);    /*put lock on i.e s--*/
    ++count;
    printf("count : %d\n",count);
    sem_post(&lock);    /*Put lock off i.e s++*/
}

int main(){

    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;

    /*Initialize semaphore*/
    sem_init(&lock,0,1);

    printf("Thread creation : Start \n");
    /*Thread Creation*/
    pthread_create(&th1,NULL,increase_count,NULL);
    pthread_create(&th2,NULL,increase_count,NULL);
    pthread_create(&th3,NULL,increase_count,NULL);
    pthread_create(&th4,NULL,increase_count,NULL);
    printf("Thread creation : End \n");

    printf("thread Join : Start\n");
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_join(th3,NULL);
    pthread_join(th4,NULL);
    printf("thread Join : End\n");

    sem_destroy(&lock);

    return 0;
}