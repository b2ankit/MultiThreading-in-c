/*Creating RACE condition situation*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define MAX_SIZE 10

int counter = 0;

void *increse_counter(void * argv){
    counter++;
    printf("value of counter : %d\n",counter);
}


int main(){
int retval;

//Thread insialization
pthread_t threadId[MAX_SIZE];

//Thread creatation
for(int i=0;i<MAX_SIZE;i++)
{
    retval = pthread_create(&threadId[i],NULL,&increse_counter,NULL);
    if(retval!=0){
        printf("Thread%d createion : Failed",i);
    }
}
    

for(int i=0;i<MAX_SIZE;i++)
pthread_join(threadId[i],NULL);

pthread_exit(NULL);

return 0;
}
