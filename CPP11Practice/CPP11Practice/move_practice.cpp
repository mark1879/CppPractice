//
//  move_practice.cpp
//  CPP11Practice
//
//  Created by MarkWu on 2019/3/21.
//  Copyright © 2019 Zego. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A
{
public:
    int *pointer;
    
public:
    A():pointer(new int(1))
    {
        cout << "构造" << pointer << endl;
    }
    
    A(const A& a):pointer(new int(*(a.pointer)))
    {
        cout << "拷贝" << pointer << endl;
    }

    A(A&& a):pointer(a.pointer)
    {
        a.pointer = nullptr;
        cout << "移动" << pointer << endl;
    }
    
    ~A()
    {
        cout << "析构" << pointer << endl;
        delete pointer;
    }
};

A return_rvalue(bool test)
{
    A a;

    if (test)
        return a;
    else
        return A();

//    return A();
}

void test_standard_library()
{
    std::string str = "Hello World";
    std::vector<std::string> v;
    
    v.push_back(str);
    
    std::cout << "str: " << str << std::endl;
    
    v.push_back(std::move(str));
    
    cout << "str: " << str << endl;
}

//int main()
//{
//    A obj = return_rvalue(true);
////
////    A* pointer = nullptr;
////    delete pointer;
//    
////    A a;
////
////    A b = a;
//    
//    cout << "done" << endl;
//    
//    return 0;
//}
