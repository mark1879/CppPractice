//
//  test_forward.hpp
//  RightValueConference
//
//  Created by MarkWu on 2019/7/15.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef test_forward_h
#define test_forward_h

#include <iostream>

using namespace std;

void reference(int& v)
{
    cout << "得到：左值引用" << endl;
}

void reference(int&& v)
{
    cout << "得到：右值引用" << endl;
}

// && + 模版函数参数”才能形成引用折叠，添加任何一个条件都不行，比如const T&& 是右值引用。
// 引用折叠规则：
// 1) 所有的右值引用叠加到右值引用上仍然还是一个右值引用
// 2) 所有的其他类型引用之间的叠加都将变成左值引用
template <typename T>
void pass(T&& v)
{
    cout << "普通传参：" << endl;
    reference(v);
    cout << endl;
    
    cout << "std::move 传参：" << endl;
    reference(std::move(v));
    cout << endl;
    
    cout << "std::forward 传参：" << endl;
    reference(std::forward<T>(v));
    cout << endl;
}

void test_forward()
{
    cout << "<<< 传递右值：" << endl;
    pass(1);
    
    cout << "<<< 传递左值：" << endl;
    int v = 1;
    pass(v);
}

#endif /* test_forward_h */
