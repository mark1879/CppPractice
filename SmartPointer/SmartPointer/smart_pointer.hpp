//
//  my_smart_pointer.hpp
//  SmartPointer
//
//  Created by MarkWu on 2023/5/8.
//

#ifndef my_smart_pointer_hpp
#define my_smart_pointer_hpp

#include <memory>
#include <iostream>
#include <thread>
#include <vector>


template<typename T>
class SmartPointer
{
public:
    SmartPointer(T *ptr = nullptr)
        : ptr_(ptr)
        , ref_count_(new int(1))
        , mutex_(new std::mutex)
    {}
    
    ~SmartPointer()
    {
        Release();
    }
    
    SmartPointer(const SmartPointer<T>& sp)
        : ptr_(sp.ptr_)
        , ref_count_(sp.ref_count_)
        , mutex_(sp.mutex_)
    {
        AddRefCount();
    }
    
    SmartPointer<T>& operator=(const SmartPointer<T>& sp)
    {
        if (ptr_ == sp.ptr_)
            return *this;
        
        Release();
        
        ptr_ = sp.ptr_;
        ref_count_ = sp.ref_count_;
        mutex_ = sp.mutex_;
        
        AddRefCount();
    }
    
    T& operator*()
    {
        return *ptr_;
    }
    
    T* operator->()
    {
        return ptr_; 
    }
    
    int UseCount() const
    {
        return ref_count_;
    }
    
    T* Get()
    {
        return ptr_;
    }
    
private:
    void AddRefCount()
    {
        mutex_->lock();
        ++(*ref_count_);
        mutex_->unlock();
    }
    
    void Release()
    {
        bool delete_flag = false;
        
        mutex_->lock();
        if (--(*ref_count_) == 0)
        {
            delete ref_count_;
            delete ptr_;        // 不同类型的资源需要不同的释放方式，比如数组
            delete_flag = true;
        }
        mutex_->unlock();
        
        if (delete_flag)    // 此处有多线程安全问题
            delete mutex_;
    }
    
private:
    T* ptr_;
    int* ref_count_;
    std::mutex* mutex_;
};


//int main(int argc, const char * argv[])
//{
//
//    
//    return 0;
//}

#endif /* my_smart_pointer_h */
