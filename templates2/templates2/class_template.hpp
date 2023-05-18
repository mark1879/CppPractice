//
//  class_template.hpp
//  templates2
//
//  Created by MarkWu on 2023/2/24.
//

#ifndef class_template_hpp
#define class_template_hpp
#include <iostream>


template<typename T>
class Stack
{
public:
    Stack() : capacity_(0), top_(kIllegalTop), ptr_(nullptr){
        std::cout << "Stack()" << std::endl;
    }
    
    Stack(int capacity) : capacity_(capacity), top_(kIllegalTop) {
        std::cout << "Stack(int), capacity: " << capacity_ << std::endl;

        ptr_ = new int[capacity_];
    }

    Stack(const Stack<T> &obj) {
        std::cout << "Stack(const Stack&), capacity: " << obj.capacity_ << std::endl;

        CopyObj(obj);
    }

    Stack(Stack<T>&& src){
        std::cout << "Stack(Stack&&), capacity: " << src.capacity_ << std::endl;
        
        MoveObj(src);
    }

    Stack<T>& operator=(const Stack<T> &src) {
        std::cout << "operator=(const Stack &)" << std::endl;

        if (this == &src)
            return *this;

        delete [] ptr_;

        CopyObj(src);

        return *this;
    }
    
    Stack<T>& operator=(Stack<T> &&src) {
        std::cout << "operator=(const Stack &&)" << std::endl;

        if (this == &src)
            return *this;
        
        MoveObj(src);
        
        return *this;
    }

    void Push(const T& val) {
        if (Full())
            Resize();
    
        ptr_[++top_] = val;
    }
    
    void Pop() {
        if (Empty())
            return;
        
        --top_;
    }
    
    bool Full() const {
        return top_ == capacity_ - 1;
    }
    
    bool Empty() const {
        return top_ == -1;
    }
    
    ~Stack() {
        std::cout << "~Stack(), capacity: " << capacity_ << std::endl;
        
        if (ptr_) {
           
            delete ptr_;
            ptr_ = nullptr;
        }
    }
    
private:
    void Resize() {
        capacity_ *= 2;
        int *new_ptr = new int[capacity_];
        for (int i = 0; i <= top_; i++)
            new_ptr[i] = ptr_[i];
        
        delete [] ptr_;
        ptr_ = new_ptr;
    }
    
    void CopyObj(const Stack<T> &src) {
        top_ = src.top_;
        capacity_ = src.capacity_;
        ptr_ = new int[src.capacity_];
      
        // 不推荐使用 memcpy，因为 memcpy 是内存拷贝，
        // 无法调用 ptr_ 中对象的拷贝构造函数
        for (int i = 0; i <= src.top_; i++)
            ptr_[i] = src.ptr_[i];
    }
    
    void MoveObj(Stack<T> &src) {
        this->top_ = src.top_;
        this->capacity_ = src.capacity_;
        this->ptr_ = src.ptr_;
        
        src.top_ = -1;
        src.capacity_ = 0;
        src.ptr_ = nullptr;
    }
    
private:
    const int kIllegalTop = -1;
    
    unsigned int capacity_ = 0;
    int top_ = kIllegalTop;
    T *ptr_ = nullptr;
};

void TestClassTemplate()
{
    int capacity = 20;
    
    Stack<int> stack(capacity);
    for (int i = 0; i < capacity; i++)
        stack.Push(i);
    
    Stack<int> stack2 = stack;
    
    Stack<int> stack3;
    stack3 = stack2;

    Stack<int> stack4 = std::move(stack3);

    Stack<int> stack5;
    stack5 = std::move(stack4);
}


#endif /* class_template_h */
