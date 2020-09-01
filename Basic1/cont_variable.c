 /***********************************************************************************************************************
 * 1. mutex is here. But if somehow th2 is start first.
 *    then it will create problem at line no. 23 (It is a logical error to call pthread_cond_signal() before
      calling pthread_cond_wait()). So, I added sleep at line 52.
 **********************************************************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_t th1,th2;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

int balance = 0;

void * moneyAdd(void *arg){
    printf("moneyAdding .......\n");
    int *value =(int *)arg;
    pthread_mutex_lock(&m1);
    balance +=(*value);
    printf("adding amount : %d\n",*value);
    pthread_mutex_unlock(&m1);
    pthread_cond_signal(&cv);
    printf("current balance is : %d\n",balance);

}

void *moneyWithdraw(void *arg){
    printf("moneyWithdrawal .......\n");
    pthread_mutex_lock(&m1);
    printf("lock aquire\n");
    pthread_cond_wait(&cv,&m1);
    printf("start withdrawing\n");
    int *value =(int *)arg;
    balance -=(*value);
    printf("withdrawal amount : %d\n",*value);
    pthread_mutex_unlock(&m1);
    printf("current balance is : %d\n",balance);

}



int main(){

    int moneyA = 1000;
    int moneyW = 300;

    pthread_create(&th1,NULL,moneyWithdraw,&moneyW);
    sleep(1);
    pthread_create(&th2,NULL,moneyAdd,&moneyA);

    pthread_join(th2,NULL);
    pthread_join(th1,NULL);


    return 0;
}