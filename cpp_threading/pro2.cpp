/***************************************************************************
 * try.lock concept in mutex is  : Not able to lock the mutex then it doesn't 
 *                                  get block the code.
 ***************************************************************************/


#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

std::mutex m;

int count = 0;

// void my_loop(){
//     if(m.try_lock()){
//         for(int i=0;i<100000;i++)
//         ++count;
//         m.unlock();
//     }
// } 

void my_loop(){
        m.lock();
        for(int i=0;i<100000;i++)
        ++count;
        m.unlock();
}

int main(){

    std::thread t1(my_loop);
    std::thread t2(my_loop);

    t1.join();
    t2.join();
    cout << "count : "<<count << endl;
    return 0;
}