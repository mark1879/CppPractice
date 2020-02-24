//
//  function.hpp
//  Lambda
//
//  Created by MarkWu on 2020/2/14.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef function_h
#define function_h
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

// 函数类型声明
using func1 = void(int);

// 函数声明
void func2(int);

// 函数指针变量声明
void (*func3)(int);

void general_func(func1 f)
{
    f(1);
}

void double_input(int a)
{
    cout << a * 2<< endl;
}

void illegal_double_input(int a, int b)
{
    cout << a * 2 + b << endl;
}

void test_function_pointer()
{
    func1 *f1 = &double_input;
    f1(1);
    
    func3 = &double_input;
    func3(1);
    
    auto f = [](int value) {
        std::cout << value << std::endl;
    };
    
    general_func(f);
    general_func(double_input);
    
    // 缺少类型安全检查机制
    general_func((func1 *)illegal_double_input);
}

using func_type = std::function<int(int)>;

int triple_input(int para)
{
    return para * 3;
}

int generic_func2(func_type f)
{
    return f(100);
}

void test_std_function()
{
    func_type func1 = triple_input;
    
    int important = 1;
    func_type func2 = [&](int value) -> int {
        return value + important;
    };
    
    std::cout << func1(10) << std::endl;
    std::cout << func2(10) << std::endl;
    
    std::cout << generic_func2(triple_input) << endl;
    std::cout << generic_func2(func2) << endl;
}


int foo(int a, int b, int c)
{
    return a + b + c;
}

void test_std_bind_and_std_placeholder()
{
    // 将参数1,2绑定到函数 foo 上，但是使用 std::placeholders::_1 来 对第一个参数进行占位
    int a = 100;
    auto bindFoo = std::bind(foo, std::placeholders::_1, a,2); // 这时调用 bindFoo 时，只需要提供第一个参数即可
    
    a = 200;
    
    cout << bindFoo(1) << endl;
}

ostream &print(ostream &os, const string &str, char c)
{
    return os << str << c;
}

void test_ref()
{
    vector<string> vec_str = {"hello", "world", "yes", "oh", "no"};
    
    for_each(vec_str.cbegin(), vec_str.cend(), bind(print, ref(cout), std::placeholders::_1, ' '));
    
    cout << endl;
}



#endif /* function_h */
