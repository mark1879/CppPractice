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

const int kMaxTaskCount = 100;

class ThreadPool
{
public:
    using Task = std::function<void()>;
    ThreadPool(int thread_num) : queue_(kMaxTaskCount)
    {
        if (thread_num <= 0)
            thread_num = std::thread::hardware_concurrency();
        
        Start(thread_num);
    }
    
    ~ThreadPool(void)
    {
        Stop();
    }
    
    void Stop()
    {
        std::call_once(flag_, [this]{ StopThreadGroup(); });
    }
    
    void AddTask(Task&& task)
    {
        queue_.Put(std::forward<Task>(task));
    }
    
    void AddTask(const Task& task)
    {
        queue_.Put(task);
    }
    
private:
    void Start(int numThreads)
    {
        running_ = true;
        
        for (int i = 0; i < numThreads; ++i)
        {
            thread_group_.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
        }
    }
    
    void RunInThread()
    {
        while (running_)
        {
            //取任务分别执行
            std::list<Task> list;
            queue_.Take(list);
            
            for (auto& task : list)
            {
                if (!running_)
                    return;
                
                task();
            }
        }
    }
    
    void StopThreadGroup()
    {
        queue_.Stop();
        running_ = false;
        
        for (auto thread : thread_group_)
        {
            if (thread)
                thread->join();
        }
        
        thread_group_.clear();
    }
    
    std::list<std::shared_ptr<std::thread>> thread_group_;
    SyncQueue<Task> queue_;
    atomic_bool running_;
    std::once_flag flag_;
};

#endif /* thread_pool_h */
