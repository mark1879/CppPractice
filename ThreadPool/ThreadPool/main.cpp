//
//  main.cpp
//  ThreadPool
//
//  Created by MarkWu on 2018/2/20.
//  Copyright © 2018年 Zego. All rights reserved.
//

#include <iostream>
#include "thread_pool.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    ThreadPool pool(2);
    
    int count  = 0;
    
    std::thread thread1 ([&pool, &count] {
        for (int i = 0; i < 10; i++)
        {
            pool.AddTask([&count]{ cout << "\nthread: " << this_thread::get_id() << " do task, count: " << count++ << endl; });
        }
    });
    
    std::thread thread2 ([&pool, &count] {
        for (int i = 0; i < 10; i++)
        {
            pool.AddTask([&count]{ cout << "\nthread: " << this_thread::get_id() << " do task, count: " << count++ << endl; });
        }
    });
    
    getchar();
    
    thread1.join();
    thread2.join();
    
    return 0;
}
