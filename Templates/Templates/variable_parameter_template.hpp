//
//  variable_parameter_template.hpp
//  Templates
//
//  Created by MarkWu on 2019/11/16.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef variable_parameter_template_h
#define variable_parameter_template_h
#include <iostream>
#include <sstream>

template<typename T, typename... Args>
void foo(const T& t, const Args& ...rest)
{
    cout << "Args size:" << sizeof...(Args) << endl;
    cout << "rest size:" << sizeof...(rest) << endl;
}

template <typename T>
std::string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>
void print(ostream &os, const T &t)
{
    os << t;
}

template<typename T, typename...Args>
void print(ostream &os, const T &t, const Args& ...rest)
{
    // 打印第一个实参
    os << t << ", ";
    // 递归调用，打印其他实参
    print(os, rest...);
}

template <typename... Args>
void error_msg(ostream &os, const Args&... rest)
{
    print(os, debug_rep(rest)...);
}

void test_variable_parameter_template()
{
//    foo(1, 2);
//    print(cout, 10, "hello", 3.14);
    error_msg(cout, 1, 2, "hello", "world");
    cout << endl;
}


#endif /* variable_parameter_template_h */
