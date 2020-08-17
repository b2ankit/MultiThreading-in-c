#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *display(void * arg){
    char *message = NULL;
    printf("waiting for 2 sec......\n");
    sleep(2);
    message = (char *)(arg);
    printf("message : %s\n",message);
}

int main(){

    pthread_t Thread_ID1, Thread_ID2;
    int retcode;
    retcode = pthread_create(&Thread_ID1,NULL,display,(void *)"Thread 1");
    if(retcode!=0)
        printf("Thread creation : Failed\n");
    pthread_join(Thread_ID1,NULL);

    retcode = pthread_create(&Thread_ID2,NULL,display,(void *)"Thread 2");
    if(retcode!=0)
        printf("Thread creation : Failed\n");
    pthread_join(Thread_ID2,NULL);
    return 0;
}