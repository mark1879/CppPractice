//
//  line.hpp
//  Templates
//
//  Created by MarkWu on 2019/11/22.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef line_h
#define line_h
class Line
{
public:
    Line();
    Line(int len);             // 简单的构造函数
    Line(const Line &obj);     // 拷贝构造函数
    Line(Line&& obj);
    ~Line();                   // 析构函数
    
private:
    int *ptr = nullptr;
};

Line::Line()
{
    cout << "Custom constructor" << endl;
}

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

// 拷贝构造
Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = *obj.ptr; // copy the value
}

// 移动构造
Line::Line(Line&& obj)
{
    cout << "Move constructor." << endl;
    this->ptr = obj.ptr;
    obj.ptr = nullptr;
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    
    if (ptr != nullptr) delete ptr;
}

#endif /* line_h */
