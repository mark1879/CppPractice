//
//  test_lock.hpp
//  Concurrency
//
//  Created by MarkWu on 2022/8/26.
//

#ifndef test_lock_hpp
#define test_lock_hpp

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class LockGuard {
public:
    void Producer(string producer_name) {
        bool runable = true;
        
        while (runable) {
            std::lock_guard<std::mutex> lock(mutex_);
            
            ++product_;
            cout << producer_name << ": " << product_ << endl;
            
            if (product_ >= kMaxProduct)
                runable = false;
        }
    }
    
public:
    static void Test() {
        LockGuard lock_guard;
        
        std::thread t1(&LockGuard::Producer, &lock_guard, "producer1");
        std::thread t2(&LockGuard::Producer, &lock_guard, "producer2");
        
        t1.join();
        t2.join();
    }
    
private:
    const int kMaxProduct = 200;
    int product_ = 0;
    std::mutex mutex_;
};

class UniqueLock {
public:
    void Producer(string producer_name) {
        std::unique_lock<std::mutex> lock(mutex_);
        lock.unlock();

        bool runable = true;
    
        while (runable) {
            lock.lock();

            ++product_;
            cout << producer_name << ": " << product_ << endl;
            
            if (product_ >= kMaxProduct)
                runable = false;
            
            lock.unlock();
        }
           
    }
    
public:
    static void Test() {
        UniqueLock unique_lock;
        
        std::thread t1(&UniqueLock::Producer, &unique_lock, "producer1");
        std::thread t2(&UniqueLock::Producer, &unique_lock, "producer2");
        
        t1.join();
        t2.join();
    }
    
private:
    const int kMaxProduct = 200;
    int product_ = 0;
    std::mutex mutex_;
};

void TestLock() {
    LockGuard::Test();
    UniqueLock::Test();
}


#endif /* test_lock_h */
