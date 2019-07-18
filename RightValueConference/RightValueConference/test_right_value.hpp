//
//  test_right_value.hpp
//  RightValueConference
//
//  Created by MarkWu on 2019/7/12.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef test_right_value_h
#define test_right_value_h

#include <iostream>
#include <string>

using namespace std;

void reference(std::string& str)
{
    cout << "左值" << endl;
}

void reference(std::string&& str)
{
    cout << "右值" << endl;
}

void test_right_value()
{
    std::string lv1 = "string, ";       // lv1 是一个左值
    
    // std::string&& rv1 = lv1;            // 非法，右值不能引用左值
    
    std::string&& rv1 = std::move(lv1);     // lv1 跟 rv1 都指向了同一块内存，等同于 std::string& temp = lv1;
    cout << "lv1: " << lv1.c_str() << endl;
    cout << "rv1: " << rv1.c_str() << endl;
    cout << endl;
    
    std::string rv2 = std::move(lv1);       // lv1 的内容被转移了
    cout << "lv1: " << lv1.c_str() << endl;
    cout << "rv2: " << rv2.c_str() << endl;
    cout << endl;
    
    
    std::string lv2 = "string2, ";
    const std::string& lv3 = lv2 + lv2;         // 合法，常量左值引用能够延长临时变量的生命周期
    cout << "lv3: " << lv3.c_str() << endl;
    cout << endl;
    
    std::string&& rv3 = lv1 + lv2;              // 合法，右值引用延长临时对象生命周期
    cout << "rv3: " << rv3.c_str() << endl;
    cout << endl;
    
    rv3 += "Test";      // 合法，非常量引用能够修改临时变量
    cout << "rv3: " << rv3.c_str() << endl;
    cout << endl;
    
    reference(rv3);
}

#endif /* test_right_value_h */
