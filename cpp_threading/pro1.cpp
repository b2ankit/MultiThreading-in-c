#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int myAmount = 0;

std::mutex m;

void addMoney(){
    m.lock();
    ++myAmount;
    cout << "myAmount : "<< myAmount <<endl;
    m.unlock();
}

int main(){
    /*thread creation*/
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    std::thread t3(addMoney);
    std::thread t4(addMoney);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    

    return 0;
}
