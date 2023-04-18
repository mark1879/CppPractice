//
//  test_right_value2.hpp
//  RightValueConference
//
//  Created by MarkWu on 2019/7/17.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef test_right_value2_h
#define test_right_value2_h

int construct_count_ = 0;
int copy_construct_count = 0;
int deconstruct_count = 0;

class B
{
public:
    B()
    {
        cout << "construct: " << ++construct_count_ << endl;
    }
    
    B(const B& b)
    {
        cout << "copy construct: " << ++copy_construct_count << endl;
    }
    
    //    B(B&& b)
    //    {
    //        cout << "move construct" << endl;
    //    }
    
    ~B()
    {
        cout << "destruct: " << ++deconstruct_count << endl;
    }
};

B GetB()
{
    return B();
}

void test_right_value2()
{
    // 右值引用可以延长临时右值的生命周期
    B b1 = GetB();
//    B&& b2 = GetB();
    
    // 常量左值引用是一个“万能”的引用类型，可以接受左值/常量左值、左值引用/常量左值引用、右值/常量右值、右值引用/常量右值引用。
    const B& b3 = GetB();
    
    // 引用的本质是用内存去hold目标
    int a = 100;
    const int b = 1;
    const int c = a;
    const int& d = 1;
    const int& e = d;
    const int&& f = 1;
    const int& h = f;
}

#endif /* test_right_value2_h */
