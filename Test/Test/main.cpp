//
//  main.cpp
//  Test
//
//  Created by MarkWu on 2019/3/5.
//  Copyright © 2019 Zego. All rights reserved.
//

#include<list>
#include<mutex>
#include<thread>
#include<condition_variable>
#include <iostream>
#include <vector>

using namespace std;

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
    int *ptr;
};

// 程序的主函数
int main( )
{
    Line line(10);
    
    Line&& line1 = std::move(line);

    cout << line.getLength() << endl;
    cout << line1.getLength() << endl;

    line1.setLength(11);

    cout << line.getLength() << endl;
    cout << line1.getLength() << endl;


    std::string str1 = "hello";
    std::string&& str2 = std::move(str1);

    cout << str1.c_str() << endl;
    cout << str2.c_str() << endl;

    str1 = "world";

    cout << str1.c_str() << endl;
    cout << str2.c_str() << endl;
    
    display(line);
    TestRightCopy(std::move(line));
    
    std::list<Line> queue;
    queue.push_back(std::move(line));
    
    reference(std::move(line));
    
    
    return 0;
}
