#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int g_variable = 0;

void *myThreadFunc(void *vargp){

    //store the value argument passed in the thread
    int *myid = (int *)vargp;

    //Lets us create a static variable to observe its change
    static int s = 0;

    ++s;
    ++g_variable;

    printf("Thread ID : %d\nStatic : %d\nGlobal : %d\n",*myid,s,g_variable);
}

int main(){
    pthread_t ThreadID_1;

    for(int i=0;i<4;i++){
        pthread_create(&ThreadID_1,NULL,myThreadFunc,(void  *)&ThreadID_1);
        pthread_join(ThreadID_1,NULL);
    }
    pthread_exit(NULL);
    

    return 0;
}
