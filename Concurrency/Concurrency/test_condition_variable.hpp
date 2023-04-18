//
//  test_condition_variable.hpp
//  Concurrency
//
//  Created by MarkWu on 2022/9/1.
//

#ifndef test_condition_variable_hpp
#define test_condition_variable_hpp

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
 
std::mutex m;
std::condition_variable cv;
std::string data1;
bool ready = false;
bool processed = false;
 
void worker_thread()
{
    // Wait until main() sends data
    std::unique_lock lk(m);
    cv.wait(lk, []{return ready;});
 
    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data1 += " after processing";
 
    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";
 
    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    
//    cv.notify_one();
//    lk.unlock();
    
//  测试 lk.unlock
//    char buf[1024];
//    fgets(buf, 1024, stdin);
    
//    出了lock的作用域，将自动解锁
}
 
void test_condition_variable()
{
    std::thread worker(worker_thread);
 
    data1 = "Example data";
    // send data to the worker thread
    {
        std::lock_guard lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();
 
    // wait for the worker
    {
        std::unique_lock lk(m);
        cv.wait(lk, []{return processed;});
    }
    std::cout << "Back in main(), data = " << data1 << '\n';
 
    worker.join();
}


#endif /* test_condition_variable_h */
