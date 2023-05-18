//
//  template.cpp
//  templates2
//
//  Created by MarkWu on 2023/1/14.
//

#include <stdio.h>
#include <iostream>
#include "template.h"

template<typename T>
bool compare(T a, T b)
{
    return a > b;
}

// 函数模版指定类型实例化
template bool compare<int>(int a, int b);
template bool compare<double>(double a, double b);

// 模版特例化
template<>
bool compare<const char*>(const char* a, const char* b)
{
    std::cout << "compare<const char*>(const char* a, const char* b)" << std::endl;

    return strcmp(a, b) > 0;
}

// 普通函数
bool compare(const char* a, const char* b)
{
    std::cout << "compare(const char* a, const char* b)" << std::endl;
    
    return strcmp(a, b) > 0;
}
