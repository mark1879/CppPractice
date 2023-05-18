//
//  main.cpp
//  templates2
//
//  Created by MarkWu on 2023/1/3.
//

#include <iostream>
#include "template.h"
#include "class_template.hpp"
#include "function_overloading.hpp"
#include "template_func_in_template_class.hpp"
#include "class_template_specialization.hpp"
#include "class_member_specialization.hpp"

void TestInstantiation()
{
    // 显时实例化
    compare<int>(10, 20);
    compare<double>(10.5, 20.5);

    // 隐式实例化，函数模版实参推断
    compare(10, 20);

    // 编译不通过，无法推断实参
//    compare(10.5, 20);

    // 显式实例化，强制类型转化
    compare<int>(10.5, 20);

    // 如果定义了普通函数 compare，则优先调用
    // 否则，调用特例化的 compare<const char*>
    compare("aaa", "bbb");

    // 显式实例化
    compare<const char*>("aaa", "bbb");
}


int main(int argc, const char * argv[])
{
    
//    TestInstantiation();
//    TestClassTemplate();
//    FunctionOverloading();
//    TestTemplateFuncInTemplateClass();
//    TestClassSpecialization();
    
    TestClassMemberSpecialization();
    
    return 0;
}
