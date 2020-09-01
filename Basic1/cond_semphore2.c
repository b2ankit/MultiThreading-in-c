#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define VALUE 1
#define PSHARED 0

int balance = 0;

pthread_t th1,th2;

sem_t lock;

void *addMoney(void *arg){
    sem_wait(&lock);
    printf("Money adding.....\n");
    int *value = (int *)arg;
    balance+= *value;
    printf("adding amount : %d\n",*value);
    printf("current balance is : %d\n",balance);
    sem_post(&lock);
}

void *withdrawMoney(void *arg){
    sem_wait(&lock);
    printf("MoneyWithdrawal.....\n");
    int *value = (int *)arg;
    balance-= *value;
    printf("adding amount : %d\n",*value);
    printf("current balance is : %d\n",balance);
    sem_post(&lock);
}


int main(){

    //semaphore init()
    sem_init(&lock,PSHARED,VALUE);


    int moneyA = 1000;
    int moneyW = 300;


    pthread_create(&th1,NULL,addMoney,&moneyA);
    pthread_create(&th2,NULL,withdrawMoney,&moneyW);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    sem_destroy(&lock);

    return 0;
}