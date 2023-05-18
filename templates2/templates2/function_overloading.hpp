//
//  function_overloading.hpp
//  templates2
//
//  Created by MarkWu on 2023/5/18.
//

#ifndef function_overloading_hpp
#define function_overloading_hpp

#include <iostream>

using namespace std;

template<typename T>    //通用模板函数
void func(T t)
{
    cout << "generic template: " << t << endl;
}

template<typename T>    //指针版本
void func(T* t)
{
    cout << "pointer template: "<< *t << endl;
}

void func(int t)    //普通函数
{
    cout << "normal function: " << t << endl;
}

void FunctionOverloading()
{
    int i = 10;
    
    func(i);
    func<int>(i);
    func(&i);
}

#endif /* function_overloading_h */
