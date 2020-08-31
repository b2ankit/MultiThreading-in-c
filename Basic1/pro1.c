/********************************************************************************************
 * 1. how to create a thread
 * 2. jion the created thread with main thread
 * 3. detach the thread.
 * 4. Terminate the Thread.
 ********************************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *myfunc(void *arg){

    printf("Entering in myfunc..\n");
    printf("Sleeping for 3 sec \n");
    sleep(3);
    printf("Exiting the myfunc...\n");

}

int main(){

    int err;
    /*Thread declaration*/
    pthread_t th1;
    pthread_t th2;

/*Thread1 creation*/
    printf("Before thread1 creation : Hello from Parent thread\n");
    err = pthread_create(&th1,NULL,myfunc,NULL);
    if (err)
    {
        printf("Thread1 creation failed with error code : %d\n",err);
        return err;
    }
    else
        printf("Thread1 created successfully ThreadID : %ld\n",th1);
    printf("After thread1 creation : Hello from Parent thread\n");

    /*joining the main thread*/
    pthread_join(th1,NULL);

    /*Thread2 creation*/
    printf("Before thread2 creation : Hello from Parent thread\n");
    err = pthread_create(&th2,NULL,myfunc,NULL);
    if (err)
    {
        printf("Thread2 creation failed with error code : %d\n",err);
        return err;
    }
    else
        printf("Thread2 created successfully ThreadID : %ld\n",th2);
    printf("After thread2 creation : Hello from Parent thread\n");

    

    /*detaching the thread 2*/
    pthread_detach(th2);

    printf("Th1 join the parent thread\n");


    return 0;
}