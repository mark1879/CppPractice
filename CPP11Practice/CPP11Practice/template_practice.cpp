//
//  template_practice.cpp
//  CPP11Practice
//
//  Created by MarkWu on 2018/12/13.
//  Copyright © 2018 Zego. All rights reserved.
//

#include "template_practice.hpp"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T, typename... Args>
void foo(const T& t, const Args& ... rest)
{
    cout << "sizeof Args: " << sizeof...(Args) << endl;
    cout << "sizeof rest: " << sizeof...(rest) << endl;
}

ostream &print(ostream  &os, const int &t)
{
    cout << "hi print1" << endl;
    return os << t;
}

template <typename T>
ostream &print(ostream  &os, const T &t)
{
    cout << "hi print2" << endl;
    return os << t;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

template <typename T>
std::string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
    return print(os, debug_rep(rest)...);
}

//int main()
//{
//    
////    errorMsg(cout, 1, 2, 3, 4, 5);
//    
//    print(cout, 1, 2, 3, 5, 6);
//    
//    cout << endl;
//    
//    return 0;
//}
