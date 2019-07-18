//
//  test_move.hpp
//  RightValueConference
//
//  Created by MarkWu on 2019/7/15.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef test_move_h
#define test_move_h

#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    int *pointer;

public:
    A() : pointer(new int(1))
    {
        cout << "普通构造: " << pointer << endl;
    }
    
    A(A& a) : pointer(new int(*a.pointer))
    {
        cout << "拷贝构造: " << pointer << endl;    // 无意义的对象拷贝
    }
    
    // 移动构造函数
    A(A&& a) : pointer(a.pointer)
    {
        a.pointer = nullptr;
        cout << "移动构造: " << pointer << endl;
    }
    
    A& operator=(const A& a)
    {
        cout << "拷贝赋值: " << a.pointer << endl;
        if (this != &a)
        {
            // 避免内存泄漏
            if (pointer == nullptr)
                pointer = new int(1);
            
            *pointer = *a.pointer;
        }
        return *this;
    }
    
    A& operator=(A&& a)
    {
        cout << "移动赋值: " << a.pointer << endl;
        if (this != &a)
        {
            // 避免内存泄漏
            if (pointer != nullptr)
                delete pointer;
            
            pointer = a.pointer;
            a.pointer = nullptr;
        }
        return *this;
    }
    
    ~A()
    {
        cout << "析构: " << pointer << endl;
        if (pointer != nullptr)
        {
            delete pointer;
        }
    }
};

// 防止编译器优化
A return_rvalue(bool test)
{
    A a, b;
   
    if (test)
        return a;
    else
        return b;
}

void test_move()
{
    // 测试移动构造函数
//    A obj = return_rvalue(false);
//
//    cout << "obj.pointer: " << obj.pointer << endl;
//    cout << "*obj.pointer: " << *obj.pointer << endl;
    
    cout << "测试拷贝赋值运算: " << endl;
    A a, b;
    b = a;
    
    cout << "\n测试移动赋值运算: " << endl;
    b = A();
    
//    cout << "\n<<< std lib \n\n";
//
//    std::string str = "Hello Str";
//    std::vector<std::string> vec;
//
//    vec.push_back(str);
//    cout << "vec.push_back(str): " << vec.back().c_str() << endl;
//    cout << "str: " << str << endl << endl;
//
//    vec.push_back(std::move(str));
//    cout << "vec.push_back(std::move(str)): " << vec.back().c_str() << endl;
//    cout << "str: " << str << endl << endl;
}

#endif /* test_move_h */
