//
//  thread_pool.hpp
//  ThreadPool
//
//  Created by MarkWu on 2019/7/10.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef thread_pool_h
#define thread_pool_h
#include <iostream>
#include<list>
#include<thread>
#include<functional>
#include<memory>
#include <atomic>
#include "sync_queue.hpp"

using namespace std;

class ThreadPool
{
public:
    using Task = std::function<void()>;
    
private:
    void Start(int thread_count)
    {
        if (running_)
        {
            cout << "warning, thread pool is running!" << endl;
            return;
        }
        
        running_ = true;
        
        for (int i = 0; i < thread_count; i++)
        {
            thread_grop_.push_back(std::make_shared<std::thread>());
        }
    }
    
    void RunInThread()
    {
        while (running_)
        {
            std::list<Task> list;
            sync_queue_.Take(list);

//            for (auto& task : list)
//            {
//                if (!running_)
//                    return;
//
//                task();
//            }
        }
    }
    
//    void StopThreadGroup()
//    {
//        sync_queue_.Stop();
//        running_ = false;
//
//        for (auto thread : thread_grop_)
//        {
//            if (thread)
//                thread->join();
//        }
//        thread_grop_.clear();
//    }
    
private:
    std::list<std::shared_ptr<std::thread>> thread_grop_;
    SyncQueue<Task> sync_queue_;
    atomic_bool running_;
    std::once_flag flag_;
};

#endif /* thread_pool_h */
