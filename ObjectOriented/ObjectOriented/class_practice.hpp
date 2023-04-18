//
//  class_practice.hpp
//  ObjectOriented
//
//  Created by MarkWu on 2022/12/14.
//

#ifndef class_practice_hpp
#define class_practice_hpp

#include <vector>
#include <unordered_map>

using namespace std;

namespace ClassPractice {
class Stack
{
public:
    Stack() : capacity_(0), top_(kIllegalTop), ptr_(nullptr){
        cout << "Stack()" << endl;
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
        
        if (ptr_)
            delete [] ptr_;

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

        MoveObj(src);

        return *this;
    }

    void Push(int val) {
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
        cout << "~Stack(), capacity: " << capacity_ << endl;
        
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
        
        src.top_ = -1;
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

using namespace ClassPractice;

Stack GetStack() {
    Stack stack(101);
    
    return stack;
}

void TestEmplace() {
    //  测试 emplace, emplace_back
   vector<Stack> vec;
   Stack stack(10);
   vec.emplace_back(10);
   vec.emplace_back(stack);
   vec.push_back(stack);
   
   unordered_map<string, Stack> map;
   map.emplace("test", 10);
}

Stack& GetStack(Stack& stack)
{
    return stack;
}

int main() {
    // 普通构造
//    Stack stack;

    Stack stack10(10);
//    Stack stack20 = 20;

    // 拷贝构造
    Stack stack10_cpy = stack10;
//    Stack stack10_cpy2(stack10);

//    // 移动构造
//    Stack stack20_replace = std::move(stack20);
//
//    // 赋值运算符
//    stack10 = stack10_cpy;
//
//    // 移动赋值
//    stack20_replace = std::move(stack10_cpy2);
    
    
    // 不调用任何构造函数
//    Stack* p10 = &stack10;
    
    Stack* p30 = new Stack(30);
    // 调用析构函数
    delete p30;
    
    std::cout << "test done!" << std::endl;
    
    return 0;
}



#endif /* class_practice_h */
