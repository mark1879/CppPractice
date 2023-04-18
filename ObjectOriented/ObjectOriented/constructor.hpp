//
//  constructor.hpp
//  ObjectOriented
//
//  Created by MarkWu on 2022/11/5.
//

#ifndef constructor_hpp
#define constructor_hpp

#include<list>
#include<mutex>
#include<thread>
#include<condition_variable>
#include <iostream>
#include <vector>

using namespace std;

namespace  Constructor {

class Line
{
public:
    int getLength( void ) const;
    void setLength(int length);
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
int Line::getLength( void ) const
{
    return *ptr;
}

void Line::setLength(int length)
{
    *ptr = length;
}

template<typename T>
void reference(T& line)
{
    std::cout << "left value" << endl;
}

template<typename T>
void reference(T&& line)
{
    std::cout << "right value" << endl;
}

template<typename T>
void TestRightCopy(T&& t)
{
    cout << "TestRightCopy : " << t.getLength() <<endl;

    reference(std::forward<T>(t));

    //    std::list<Line> queue;
    //    queue.push_back(std::forward<T>(t));
    //
    //    std::cout << "size: " << queue.size() << std::endl;
}

void display(const Line& obj)
{
    cout << "display : " << obj.getLength() <<endl;

    TestRightCopy(obj);
}

//// 程序的主函数
//int main( )
//{
//    const Line line(10);
//
//    reference(line);
//    reference(std::move(line));
    
//    cout << line.getLength() << endl;
//    cout << line1.getLength() << endl;
//
//    line1.setLength(11);
//
//    cout << line.getLength() << endl;
//    cout << line1.getLength() << endl;
//
//
//    std::string str1 = "hello";
//    std::string&& str2 = std::move(str1);
//
//    cout << str1.c_str() << endl;
//    cout << str2.c_str() << endl;
//
//    str1 = "world";
//
//    cout << str1.c_str() << endl;
//    cout << str2.c_str() << endl;
//
//    display(line);
//    TestRightCopy(std::move(line));
    
//    std::list<Line> queue;
//    queue.push_back(line2);
//    cout << line.getLength() << endl;
//
//    queue.push_back(std::move(line));
    
//    reference(std::move(line));
    
    
//    return 0;
//}

};

#endif /* constructor_h */
