//
//  line.hpp
//  AssociativeContainers
//
//  Created by MarkWu on 2020/2/26.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef line_h
#define line_h
#include <iostream>

using namespace std;

class Line
{
public:
    Line(int len);             // 简单的构造函数
    Line(const Line &obj);     // 拷贝构造函数
    Line(Line&& obj);
    ~Line();                   // 析构函数
    
    void SetLength(int length);
    
private:
    int *ptr = nullptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr, len: " << len << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

// 拷贝构造
Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr, len: " << *obj.ptr << endl;
    ptr = new int;
    *ptr = *obj.ptr;    // copy the value
}

// 移动构造
Line::Line(Line&& obj)
{
    cout << "Move constructor, len: " << *obj.ptr << endl;
    this->ptr = obj.ptr;
    obj.ptr = nullptr;
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    
    if (ptr != nullptr){
        cout << "ptr is not null, len: " << *ptr << endl;
        delete ptr;
    } else {
        cout << "ptr is null" << endl;
    }
}

void Line::SetLength(int length){
    if (ptr != nullptr){
        *ptr = length;
    }
}


#endif /* line_h */
