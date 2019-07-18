#include <iostream>
#include "ThreadPool.hpp"
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>

using namespace std;

std::mutex g_mutex;
bool g_ready = false;
std::condition_variable g_condition_variable;

void wait_set()
{
    cout << "wait_set in\n";
    
    std::unique_lock<std::mutex> locker(g_mutex);
    
    g_condition_variable.wait(locker, []{ return g_ready;});
    
    cout << "wait_set out\n";
    
}


void race_to_control()
{
    cout << "race_to_control in\n";
    
    std::lock_guard<std::mutex> locker(g_mutex);
    
    int max = 10;
    int count = 0;
    while (count < max)
    {
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);
        
        cout << "race_to_control count:" << count << "\n";
        
        count++;
    }
    
    cout << "race_to_control out\n";
}

void do_set()
{
    cout << "do_set in\n";
    
    std::unique_lock<std::mutex> locker(g_mutex);
    g_ready = true;
    
    std::thread t1(race_to_control);
    t1.detach();
    
    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for(dura);
    
    g_condition_variable.notify_one();
    
    cout << "do_set out\n";
}




int main(int argc, const char * argv[]) {
    
    std::thread t1(wait_set);
    t1.detach();
    
    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for(dura);
    
    do_set();
    
    std::chrono::milliseconds dura1(20000);
    std::this_thread::sleep_for(dura1);
    
    return 0;
}
