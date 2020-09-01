/*******************************************************************************
 * 1. Muxtex in c multi Threading.
 * 2. Race condition : If more than 1 thread wants to change any shared resourece
 *    then race condition arises. but in accesing there is no race condition.
 * 3. creatx a mutux, lock, unclock anad destroy muxtex.
 ******************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

//Mutex decalaration
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int count = 0;

void *increase_count(void *arg){
    /*mutex lock*/
    pthread_mutex_lock(&lock);
    ++count;
    printf("count : %d\n",count);
    pthread_mutex_unlock(&lock);

}

int main(){
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;
    pthread_t th5;
    pthread_t th6;

    // /*Mutex init*/
    // pthread_mutex_init(&lock,NULL);

    //creating threading 1
    pthread_create(&th1,NULL,increase_count,NULL);
    pthread_create(&th2,NULL,increase_count,NULL);
    pthread_create(&th3,NULL,increase_count,NULL);
    pthread_create(&th4,NULL,increase_count,NULL);
    pthread_create(&th5,NULL,increase_count,NULL);
    pthread_create(&th6,NULL,increase_count,NULL);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_join(th3,NULL);
    pthread_join(th4,NULL);
    pthread_join(th5,NULL);
    pthread_join(th6,NULL);

    /*destroying the mutux*/
    pthread_mutex_destroy(&lock);
    return 0;
}