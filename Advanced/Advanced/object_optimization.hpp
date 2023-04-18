//
//  ObjectOptimization.h
//  Advanced
//
//  Created by MarkWu on 2023/3/31.
//

#ifndef OBJECT_OPTIMIZATION_HPP
#define OBJECT_OPTIMIZATION_HPP
#include <iostream>
#include <vector>

using namespace std;

namespace ObjectOptimization {
class Stack
{
public:
    Stack() : capacity_(0), top_(kIllegalTop), ptr_(nullptr){
        cout << "Stack(), capacity: " << capacity_ << endl;
    }
    
    Stack(int capacity) : capacity_(capacity), top_(kIllegalTop) {
        cout << "Stack(int), capacity: " << capacity_ << endl;
        ptr_ = new int[capacity_];
    }

    Stack(const Stack &obj) {
        cout << "Stack(const Stack&), capacity: " << obj.capacity_ << endl;
        CopyObj(obj);
    }
    
    Stack(Stack&& src){
        cout << "Stack(Stack&&), capacity: " << src.capacity_ << endl;
        MoveObj(src);
    }
    
    Stack& operator=(const Stack &src) {
        cout << "operator=(const Stack &)" << endl;

        if (this == &src)
        {
            cout << "same, this == &src" << endl;
            return *this;
        }
        
        if (ptr_ != nullptr)
        {
            delete [] ptr_;
        }

        CopyObj(src);

        return *this;
    }
    
    Stack& operator=(Stack &&src) {
        cout << "operator=(const Stack &&)" << endl;

        if (this == &src)
        {
            cout << "same, this == &src" << endl;
            return *this;
        }
        
        
        if (ptr_ != nullptr)
        {
            delete [] ptr_;
        }
        
        MoveObj(src);
        
        return *this;
    }

    void Push(int val) {
        if (top_ == capacity_ - 1)
            Resize(capacity_ * 2);
    
        ptr_[++top_] = val;
    }
    
    void Pop() {
        if (top_ == kIllegalTop)
            return;
        
        --top_;
    }
    
    ~Stack() {
        cout << "~Stack(), capacity: " << capacity_ << endl;
        
        if (ptr_) {
           
            delete ptr_;
            ptr_ = nullptr;
        }
    }
    
    unsigned int capacity() const
    {
        return capacity_;
    }
    
   void Expand(unsigned int capacity)
   {
       Resize(capacity);
   }
    
private:
    void Resize(unsigned int capacity) {
        capacity_ = capacity;
        
        int *new_ptr = new int[capacity_];
        for (int i = 0; i <= top_; i++)
            new_ptr[i] = ptr_[i];
        
        delete [] ptr_;
        ptr_ = new_ptr;
    }
    
    void CopyObj(const Stack &src) {
        top_ = src.top_;
        capacity_ = src.capacity_;
        ptr_ = new int[src.capacity_];
      
        // 不推荐使用 memcpy，因为 memcpy 是内存拷贝，
        // 无法调用 ptr_ 中对象的拷贝构造函数
        for (int i = 0; i <= src.top_; i++)
            ptr_[i] = src.ptr_[i];
    }
    
    void MoveObj(Stack &src) {
        this->top_ = src.top_;
        this->capacity_ = src.capacity_;
        this->ptr_ = src.ptr_;
        
        src.top_ = kIllegalTop;
        src.capacity_ = 0;
        src.ptr_ = nullptr;
    }
    
private:
    const int kIllegalTop = -1;
    
    unsigned int capacity_ = 0;
    int top_ = kIllegalTop;
    int *ptr_ = nullptr;
};
};

using namespace ObjectOptimization;

Stack GetObject1(Stack stack)
{
    stack.Expand(200);
    
    return stack;
}

Stack GetObject2(Stack stack)
{
    stack.Expand(200);
    Stack tmp(stack);
    tmp.Expand(201);
    return  tmp;
}

Stack GetObject3(Stack stack)
{
    stack.Expand(200);
    return Stack(stack.capacity());
}



void TestObjectOptimizationInFuncCall()
{
//    Stack stack;
//    Stack stack1 = GetObject1(stack);
//    Stack stack2 = GetObject2(stack);
//    Stack stack3 = GetObject3(stack);
    
    Stack stack;
    Stack stack4(4);
    stack4 = GetObject1(stack);
//    stack4 = GetObject2(stack);
//    stack4 = GetObject3(stack);
}

void TestObjectConstruction()
{
    // 普通构造
//    Stack stack1(1);
    
    
    // 拷贝构造
//    Stack stack2(stack1);
//    Stack stack2 = stack1;
    
    
    // 普通构造
    // 用临时对象生成新的对象，临时对象会被编译器优化掉
//    Stack stack3 = Stack(3);
//    Stack stack3 = 3;
//    Stack stack3 = (Stack)3;
//    static Stack stack3 = Stack(3);
//    static Stack stack3 = 3;
//    static Stack stack3 = (Stack)3;
    
    
    // 移动构造
//    Stack stack4 = std::move(stack1);
    //  先用普通构造生成临时对象，再移动构造
//    Stack stack4 = std::move((Stack)4);
//    Stack stack4 = std::move(Stack(4));
    
    // 普通构造
//    Stack stack4 = std::move(4);
    
    
    // 拷贝赋值
//    Stack stack5;
//    stack5 = stack1;
    
    
    // 移动赋值
//    Stack stack6;
//    stack6 = std::move(stack1);
//    stack6 = Stack(6);    // 显式生成临时对象，再移动赋值
//    stack6 = (Stack)6;    // 显式生成临时对象，再移动赋值
//    stack6 = 6;           // 隐式生成临时对象，，再移动赋值
//    stack6 = std::move(Stack(6));     // 显式生成临时对象，再移动赋值
//    stack6 = std::move((Stack)6);     // 显式生成临时对象，再移动赋值
//    stack6 = std::move(6);            // 隐式生成临时对象，，再移动赋值
    
    
    // 引用临时对象，需要加 const，只能读，不能写
//    const Stack& stack7_ref = Stack(7);
//    const Stack& stack7_ref = (Stack)7;
//    const Stack& stack7_ref = 7;
    
    
    // 错误，不能取临时对象的地址
//    Stack* stack8_p = &Stack(8);
}


int main()
{
    
//    TestObjectConstruction();
    
    TestObjectOptimizationInFuncCall();
    std::cout << "<<<<<< main finished " << std::endl;
    
    return 0;
}


#endif /* ObjectOptimization_h */
