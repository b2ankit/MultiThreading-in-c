/*Take 10 Thraed and change a golbal and local variable*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


int global_variable = 0;

void * display(void * argv){

    //store the value argument passed in the Thread
    int *ThreadID = (int *)argv;

    //Lets us create a static variable to observe its change
    static int s = 0;

    s++; global_variable ++;
    printf("Thread ID : %d\nStatic : %d\nGlobal-variable: %d\n",*ThreadID,s,global_variable);
    printf("***** waiting for 2 sec *****\n");
    sleep(2);

}


int main(){
    pthread_t Thread[10];

    for(int i=0;i<10;i++){
        pthread_create(&Thread[i],NULL,display,(void *)&Thread[i]);
        pthread_join(Thread[i],NULL);
    }
    pthread_exit(NULL);


    return 0;
}