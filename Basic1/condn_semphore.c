#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define VALUE 1
#define PSHARED 0

pthread_t th1,th2;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

sem_t lock;



int counter = 0;

void *increase_counter(void *arg){
    sem_wait(&lock);
    printf("Inside++\n");
    counter++;
    printf("counter updated value : %d\n",counter);
    sem_post(&lock);
}

void *decrease_counter(void *arg){
    sem_wait(&lock);
    printf("Inside--\n");
    counter--;
    printf("counter updated value : %d\n",counter);
    sem_post(&lock);

}

int main(){

    //semaphore init()
    sem_init(&lock,PSHARED,VALUE);

    pthread_create(&th2,NULL,increase_counter,NULL);
    pthread_create(&th1,NULL,decrease_counter,NULL);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    sem_destroy(&lock);

    return 0;
}