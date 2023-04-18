//
//  test_detach.hpp
//  Concurrency
//
//  Created by MarkWu on 2022/8/31.
//

#ifndef test_detach_hpp
#define test_detach_hpp

#include <iostream>
#include <chrono>
#include <thread>
 
void independentThread()
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}
 
void threadCaller()
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}
 
void TestDetach()
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}


#endif /* test_detach_h */
