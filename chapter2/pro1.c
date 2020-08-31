/*************************************************************************************************************
 * 1. making a functions sync.
 * 2. add_num function return the sum of two number
 * 3. sub_num function return the difference of two number
 ************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int add_num(int x, int y){
    return (x+y);
} 

int sub_num(int x, int y){
    return(x-y);
}

void display(int x,char *oper){

    printf("%s of number : %d\n",oper,x);
}

int main(){
    int result = 0;

    result = add_num(5,10);
    display(result,"sum");
    printf("waiting for 2 sec ....\n");
    sleep(2);

    result = add_num(10,20);
    display(result,"sum");
    printf("waiting for 2 sec ....\n");
    sleep(2);


    result = add_num(20,30);
    display(result,"sum");
    printf("waiting for 2 sec ....\n");
    sleep(2);


    result = add_num(30,40);
    display(result,"sum");
    printf("waiting for 2 sec ....\n");
    sleep(2);


    result = sub_num(10,5);
    display(result,"sub");
    printf("waiting for 2 sec ....\n");
    sleep(2);


    result = sub_num(20,10);
    display(result,"sub");
    printf("waiting for 2 sec ....\n");
    sleep(2);


    result = sub_num(30,20);
    display(result,"sub");
    printf("waiting for 2 sec ....\n");
    sleep(2);


    result = sub_num(40,30);
    display(result,"sum");
    printf("waiting for 2 sec ....\n");
    sleep(2);



    return 0;
}