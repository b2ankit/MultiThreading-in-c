#include<stdio.h>
#include<pthread.h>

pthread_t th1,th2;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

int balance = 0;

void * moneyAdd(void *arg){
    printf("moneyAdding .......\n");
    pthread_mutex_lock(&m1);
    int *value =(int *)arg;
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
    pthread_create(&th2,NULL,moneyAdd,&moneyA);


    pthread_join(th1,NULL);
    pthread_join(th2,NULL);


    return 0;
}