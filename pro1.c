#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *myThreadFun(void *vargp){
    printf("function : %s is sleeping for 2 sec\n",__func__);
    sleep(2);
    printf("I am inside thread\n");
    return NULL;
}


int main(){

    pthread_t threadId_1;   //declare the thread variable
    printf("Before thread\n");
    pthread_create(&threadId_1,NULL,myThreadFun,NULL);
    pthread_join(threadId_1,NULL);
    printf("After Thread\n");
    return 0;
}