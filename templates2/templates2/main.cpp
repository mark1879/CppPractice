//
//  main.cpp
//  templates2
//
//  Created by MarkWu on 2023/1/3.
//

#include <iostream>
#include "template.h"
#include "class_template.hpp"

void TestClassTemplate() {
    int capacity = 20;
    
    Stack<int> stack(capacity);
    for (int i = 0; i < capacity; i++)
        stack.Push(i);
    
    Stack<int> stack2 = stack;
    
    Stack<int> stack3;
    stack3 = stack2;

    Stack<int> stack4 = std::move(stack3);

    Stack<int> stack5;
    stack5 = std::move(stack4);
}

int main(int argc, const char * argv[]) {
//    // 显时实例化
//    compare<int>(10, 20);
//    compare<double>(10.5, 20.5);
//
//    // 隐式实例化，函数模版实参推断
//    compare(10, 20);
//
//    // 编译不通过，无法推断实参
////    compare(10.5, 20);
//
//    // 显式实例化，强制类型转化
//    compare<int>(10.5, 20);
//
//    // 如果定义了普通函数 compare，则优先调用
//    // 否则，调用特例化的 compare<const char*>
//    compare("aaa", "bbb");
//
//    // 显式实例化
//    compare<const char*>("aaa", "bbb");
    
    
    TestClassTemplate();
    
    return 0;
}
